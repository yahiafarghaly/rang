project('rang', 'cpp', version : '1.1',
        default_options : ['cpp_std=c++11'])

inc = include_directories('include')
catch_inc = include_directories('test')

subdir('test')

rang_dep = declare_dependency(include_directories:inc)
