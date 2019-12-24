from distutils.core import setup
from Cython.Build import cythonize

from os import walk
from os.path import join, relpath, splitext

build = 'build'
src = 'src'

pyx_path = 'some_dir/helloworld2'

cython_extension = ['.pyx']
c_extension = '.c'


cython_files = []
append = cython_files.append
for (dirpath, dirnames, filenames) in walk(src):
    print(dirpath)
    for filename in filenames:
        basename, extension = splitext(filename)
        if extension in cython_extension:
            src_path = join(dirpath, filename)

            relative_path = relpath(dirpath, src)
            build_path = join(build, relative_path) if relative_path != '.' else build

            append((src_path, build_path))

for src_module, build_path in cython_files:
    setup(
        ext_modules=cythonize(src_module, build_dir=build)
    )
