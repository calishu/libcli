# !!! Only compile for tests !!!
project('LibCLI', 'cpp', default_options: ['cpp_std=c++20'])

catch2_dep = dependency('catch2', method: 'pkg-config', required: true)

lib_include = include_directories('src/')
test_files = files('tests/main.cpp')

test_exe = executable('libcli_test', test_files, include_directories: lib_include, dependencies: [catch2_dep])
