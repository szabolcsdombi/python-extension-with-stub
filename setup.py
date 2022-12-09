from setuptools import Extension, setup

ext = Extension(
    name='mymodule',
    sources=['./mymodule.cpp'],
    define_macros=[('PY_SSIZE_T_CLEAN', None)],
)

setup(
    name='mymodule',
    version='0.1.0',
    ext_modules=[ext],
    include_package_data=True,
    package_data={'mymodule-stubs': ['__init__.pyi']},
    packages=['mymodule-stubs'],
)
