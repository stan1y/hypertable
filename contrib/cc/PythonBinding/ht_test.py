#!/usr/bin/python

#import sys, os, glob

#os.system('python setup.py build')

#for path in glob.glob('build/*'):
#    sys.path.insert(0, path)


import ht

def test():
    client = ht.Client("/opt/hypertable/current/conf/hypertable.cfg")

    print client.hql('show tables')
    print client.hql('drop table if exists xxx')
    print client.hql('show tables')
    print client.hql('create table xxx (yyy)')
    print client.hql('show tables')
    print client.get_schema("xxx", True)

    def selectstar():
        print ["%s:%s %s" % (cell.row_key, cell.column_family, cell.value) for cell in client.hql('select * from xxx')]

    selectstar()

    print "=== hql examples"
    print client.hql('insert into xxx values ("666","yyy:777","888")')
    selectstar()

    print client.hql('delete * from xxx where row="666"')
    selectstar()

    print "=== mutator examples"
    table = client.open_table("xxx")
    mutator = table.create_mutator()
    # insert value
    mutator.set("py-k1", "yyy", "", "py-v1")
    mutator.flush()
    selectstar()

    # insert another value
    mutator.set("py-k2", "yyy", "", "py-v2")
    mutator.flush()
    selectstar()

    # delete value
    mutator.set_delete("py-k1", "yyy", "")
    mutator.flush()
    selectstar()

    print "=== scanner examples"
    scan_spec_builder = ht.ScanSpecBuilder()
    scan_spec_builder.add_row_interval("p", True, "q", False)
    for cell in table.create_scanner(scan_spec_builder):
        print "%s:%s %s" % (cell.row_key, cell.column_family, cell.value)

test()
