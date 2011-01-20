#!/usr/bin/python

from setuptools import setup, Extension

setup(name = "ht",
        version = "0.9.4.3",
        description = "Hypertable 0.9.4 Python Binding",
        author = "Stanislav Yudin",
        author_email = "stanislav.yudin@k7cloud.com",
		url = "http://www.k7cloud.com",
        ext_modules=[
        Extension(  "ht",
                    ["HypertableBindings.cc"],
                    include_dirs         =["../../../src/cc"],
                    library_dirs         =["../../../lib", "../../../src/cc/Hypertable/Lib"],
                    libraries            =["boost_python", "Hypertable"],
                    define_macros        =[],
                    extra_compile_args   =["-Wno-deprecated", ],
                    extra_link_args      =[],
                    depends              =[],
                ), ]
        )