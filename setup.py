from setuptools import setup, Extension

module1 = Extension('pylambert',
		define_macros = [('MAJOR_VERSION', '1'),
			('MINOR_VERSION', '0')],
		sources = ['lambertmodule.c', './lib/src/lambert.c'],
		include_dirs = ['./lib/src'])

setup (name = 'pylambert',
		version = '1.0',
		description = 'A Python wrapper to the C lambert library',
		author = 'Yannick Heinrich',
		author_email = 'yannick.heinrich@gmail.com',
		url = 'https://github.com/yageek/lambert-python',
		keywords = ['lambert', 'coordinates', 'gps', 'wgs84'], # arbitrary keywords
		headers = ["./lib/src/lambert.h"],
ext_modules = [module1])
