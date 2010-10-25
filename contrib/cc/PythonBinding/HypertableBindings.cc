#include <Common/Compat.h>
#include <Common/System.h>
#include <Hypertable/Lib/Client.h>
#include <Hypertable/Lib/HqlInterpreter.h>
#include <boost/python.hpp>
#include <boost/python/class.hpp>
#include <boost/python/list.hpp>
#include <boost/python/module.hpp>
#include <boost/python/borrowed.hpp>
#include <boost/python/def.hpp>

using namespace boost::python;
using namespace Hypertable;
using namespace std;



class PyClient : public Client
{
public:
    PyClient(const string &config_file, uint32_t default_timeout_ms=0)
        : Client(string(), config_file, default_timeout_ms)
    {
    }

    TablePtr open_table(const string& name, bool force=false)
    {
        return Client::open_table(name, force);
    }

    boost::python::list get_tables()
    {
        vector<string> tables;
        Client::get_tables(tables);

        boost::python::list t;
        BOOST_FOREACH(const string& name, tables ) { t.append(name); }
        return t;
    }

    object hql(const string& str)
    {
        struct : HqlInterpreter::Callback
        {
            TableScannerPtr scanner;
            boost::python::list t;
            virtual void on_return(const string & s) { t.append(s); }
            virtual void on_scan(TableScanner & ts) { scanner = &ts; }
        } cb;
        HqlInterpreterPtr hql = create_hql_interpreter();
        hql->execute(str, cb);
        // return scanner (iterable) or list
        if(cb.scanner)
            return object(cb.scanner);
        else
            return cb.t;
    }
};

struct PyCell
{
    str         row_key;
    str         column_family;
    str         column_qualifier;
    str         value;
    uint64_t    timestamp;
    uint64_t    revision;
    uint8_t     flag;

    PyCell(Cell& cell)
        : row_key(cell.row_key)
        , column_family(cell.column_family)
        , column_qualifier(cell.column_qualifier)
        , value((const char*)cell.value, cell.value_len)
        , timestamp(cell.timestamp)
        , revision(cell.revision)
        , flag(cell.flag)
    {
    }
};

PyCell scanner_next(TableScannerPtr p)
{
    Cell cell;
    if( !p->next(cell) ) {
        PyErr_SetString(PyExc_StopIteration, "No more data.");
        throw_error_already_set();
    }
    return PyCell(cell);
}

KeySpec make_keyspec(const string& row,
                     const string& column_family,
                     const string& column_qualifier)
{
    KeySpec key;
    key.clear();
    key.row                   = row.c_str();
    key.row_len               = row.length();
    key.column_family         = column_family.c_str(),
    key.column_qualifier      = column_qualifier.c_str();
    key.column_qualifier_len  = column_qualifier.length();
    return key;
}

void mutator_set(TableMutatorPtr p,
                 const string& row,
                 const string& column_family,
                 const string& column_qualifier,
                 const string& value)
{
    p->set(make_keyspec(row, column_family, column_qualifier), value.c_str(), value.length());
}

void mutator_set_delete(TableMutatorPtr p,
                        const string& row,
                        const string& column_family,
                        const string& column_qualifier)
{
    p->set_delete(make_keyspec(row, column_family, column_qualifier));
}

void     mutator_flush(TableMutatorPtr p) { p->flush(); }

uint64_t mutator_get_resend_count(TableMutatorPtr p) { return p->get_resend_count(); }

uint64_t mutator_memory_used(TableMutatorPtr p) {  return p->memory_used(); }


TableScannerPtr create_scanner(TablePtr p,
                               ScanSpecBuilder& spec,
                               uint32_t timeout_ms = 0,
                               bool retry_table_not_found = false)
{
    return p->create_scanner(spec.get(), timeout_ms, retry_table_not_found);
}
BOOST_PYTHON_FUNCTION_OVERLOADS(create_scanner_overloads, create_scanner, 2, 4)

TableMutatorPtr create_mutator(TablePtr p,
                               uint32_t timeout_ms=0,
                               uint32_t flags=0,
                               uint32_t flush_interval_ms=0 )
{
    return p->create_mutator(timeout_ms, flags, flush_interval_ms);
}
BOOST_PYTHON_FUNCTION_OVERLOADS(create_mutator_overloads, create_mutator, 1, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(open_table_overloads, open_table, 1, 2)


BOOST_PYTHON_MODULE(ht)
{
  class_<PyClient, boost::noncopyable>("Client", init<const string&, optional<uint32_t> >())
    .def("open_table",          &PyClient::open_table, open_table_overloads())
    .def("create_table",        &PyClient::create_table)
    .def("refresh_table",       &PyClient::refresh_table)
    .def("drop_table",          &PyClient::drop_table)
    .def("get_schema",          &PyClient::get_schema)
    .def("get_tables",          &PyClient::get_tables)
    .def("close",               &PyClient::close)
    .def("shutdown",            &PyClient::shutdown)
    .def("hql",                 &PyClient::hql)
    ;

  class_<TablePtr>("Table", "Table representation", no_init)
    .def("create_scanner",      create_scanner, create_scanner_overloads())
    .def("create_mutator",      create_mutator, create_mutator_overloads())
    ;

  class_<TableMutatorPtr>("TableMutator", "Table Mutator class", no_init)
    .def("set",                 mutator_set)
    .def("set_delete",          mutator_set_delete)
    .def("get_resend_count",    mutator_get_resend_count)
    .def("memory_used",         mutator_memory_used)
    .def("flush",               mutator_flush)
    ;

  class_<TableScannerPtr>("TableScanner", no_init)
    .def("next",                scanner_next)
    .def("__iter__",            objects::identity_function())
    ;

  class_<ScanSpecBuilder, boost::noncopyable>("ScanSpecBuilder", "scan spec docstring")
    .def("clear",               &ScanSpecBuilder::clear)
    .def("set_row_limit",       &ScanSpecBuilder::set_row_limit)
    .def("set_max_versions",    &ScanSpecBuilder::set_max_versions)
    .def("add_column",          &ScanSpecBuilder::add_column)
    .def("add_row",             &ScanSpecBuilder::add_row)
    .def("add_row_interval",    &ScanSpecBuilder::add_row_interval)
    .def("add_cell",            &ScanSpecBuilder::add_cell)
    .def("add_cell_interval",   &ScanSpecBuilder::add_cell_interval)
    .def("set_time_interval",   &ScanSpecBuilder::set_time_interval)
    .def("set_start_time",      &ScanSpecBuilder::set_start_time)
    .def("set_end_time",        &ScanSpecBuilder::set_end_time)
    .def("set_keys_only",       &ScanSpecBuilder::set_keys_only)
    .def("set_return_deletes",  &ScanSpecBuilder::set_return_deletes)
    ;

  class_<PyCell>("Cell", no_init)
    .def_readonly("row_key",            &PyCell::row_key)
    .def_readonly("column_family",      &PyCell::column_family)
    .def_readonly("column_qualifier",   &PyCell::column_qualifier)
    .def_readonly("timestamp",          &PyCell::timestamp)
    .def_readonly("flag",               &PyCell::flag)
    .def_readonly("value",              &PyCell::value)
    ;
}
