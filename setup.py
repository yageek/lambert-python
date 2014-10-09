from distutils.core import setup, Extension

module1 = Extension('lambert',
		define_macros = [('MAJOR_VERSION', '1'),
			('MINOR_VERSION', '0')],
		sources = ['lambertmodule.c'])

setup (name = 'lambert',
		version = '1.0',
		description = 'A Python wrapper to the C lambert library',
		author = 'Yannick Heinrich',
		author_email = 'yannick.heinrich@gmail.com',
		url = 'http://docs.python.org/extending/building',
		long_description = '''
This is really just a demo package.
''',
ext_modules = [module1])
