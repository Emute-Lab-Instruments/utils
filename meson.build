project('eli-utils', 'cpp',
    version: '0.1.0',
    default_options: [
        'cpp_std=c++17',
        'warning_level=3'
    ]
)

# Configure string backend option
string_backend = get_option('string_backend')
string_backend_define = ''

if string_backend == 'std'
    string_backend_define = 'ELI_STRING_STD'
elif string_backend == 'extended_std'
    string_backend_define = 'ELI_STRING_EXTENDED_STD'
elif string_backend == 'arduino'
    string_backend_define = 'ELI_STRING_ARDUINO'
else
    string_backend_define = 'ELI_STRING_OTHER'
endif

# Define the string library
eli_string_lib = static_library('eli-string',
    ['src/ELI_String.h'],
    include_directories: include_directories('src'),
    cpp_args: ['-DELI_STRING_BACKEND=' + string_backend_define],
    install: true
)

# Declare dependency for other projects
eli_string_dep = declare_dependency(
    link_with: eli_string_lib,
    include_directories: include_directories('src'),
    compile_args: ['-DELI_STRING_BACKEND=' + string_backend_define]
)