from distutils.core import setup, Extension

module1 = Extension('student',
                    sources = ['classextension.cpp'],
		    )

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
