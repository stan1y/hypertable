#!/usr/bin/python

#import sys, os, glob

#os.system('python setup.py build')

#for path in glob.glob('build/*'):
#	 sys.path.insert(0, path)


import ht
schema = '''
<Schema>
  <AccessGroup name="default">
    <ColumnFamily>
      <Name>app</Name>
      <deleted>false</deleted>
    </ColumnFamily>
    <ColumnFamily>
      <Name>props</Name>
      <deleted>false</deleted>
    </ColumnFamily>
  </AccessGroup>
</Schema>
'''

def test():
	client = ht.Client("/opt/hypertable/0.9.4.3/conf/hypertable.cfg")
	
	rootns = client.open_namespace('/')
	ns_list = rootns.get_namespaces()
	print 'namespaces:'
	print repr(ns_list)
	if not 'testspace' in ns_list:
		client.create_namespace('testspace', True)
	ns = client.open_namespace('testspace')
	print 'tables in %s' % ns.get_name()
	tbl_list = ns.get_tables()
	if 'xxx1' in tbl_list:
		ns.drop_table('xxx1')
	ns.create_table('xxx1', schema)
	table = ns.open_table('xxx1')
	mutator = table.create_mutator()
	# insert value
	mutator.set("py-k1", "app", "", "py-v1")
	mutator.flush()
	

	# insert another value
	mutator.set("py-k2", "app", "", "py-v2")
	mutator.flush()

	# delete value
	mutator.set_delete("py-k1", "app", "")
	mutator.flush()

	scan_spec_builder = ht.ScanSpecBuilder()
	scan_spec_builder.add_row_interval("p", True, "q", False)
	for cell in table.create_scanner(scan_spec_builder):
		print "%s:%s %s" % (cell.row_key, cell.column_family, cell.value)

test()
