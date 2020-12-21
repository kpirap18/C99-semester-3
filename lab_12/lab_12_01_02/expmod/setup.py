from distutils.core import setup, Extension

setup(name='libarray_dll',
    ext_modules=[
        Extension('libarray_dll',
            ['wrap.c'],
            include_dirs = ['.'],
            define_macros = [('FOO','1')],
            undef_macros = ['BAR'],
            library_dirs = ['.'],
            libraries = ['libarray']
            )
        ]
)