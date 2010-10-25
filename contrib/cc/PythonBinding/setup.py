#!/usr/bin/python
from setuptools import setup, Extension

setup(name = "ht",
        version = "0.9.3.4.cyclozzo1",
        description = "Hypertable Binding",
        author = "Sreejith K",
        author_email = "srejit@k7computing.com",
		url = "http://www.k7computing.com",
        ext_modules=[
   Extension(  "ht",
               ["HypertableBindings.cc"],
               include_dirs         =["/opt/hypertable/0.9.3.4/include"],
               library_dirs         =["/opt/hypertable/0.9.3.4/lib"],
               libraries            =["boost_python", "Hypertable"],
               define_macros        =[],
               extra_compile_args   =["-Wno-deprecated", ],
               extra_link_args      =[],
               depends              =[],
            ), ] )
