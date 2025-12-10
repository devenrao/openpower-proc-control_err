# meson.build for ecmd-plugin
# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------
ecmd_plugin_src = files(
    'ecmd_dll_capi.cpp',
    'ecmd_dll_error.cpp',
    'ecmd_dll_istep.cpp',
    'ecmd_dll_ring.cpp',
    'ecmd_util.cpp',
)

# Include directories
# ---------------------------------------------------------------------
ecmd_plugin_inc = include_directories('.')

# ---------------------------------------------------------------------
# Libraries / Dependencies
# ---------------------------------------------------------------------

ecmd_plugin_deps = [
    cxx.find_library('ipl', required: true),
    cxx.find_library('ecmd', required: true),
    cxx.find_library('pdbg', required: true),
    dependency('phosphor-logging'),
]

# ---------------------------------------------------------------------
# Build shared library
# ---------------------------------------------------------------------

ecmd_plugin_lib = shared_library(
    'ecmd-plugin',
    ecmd_plugin_src,
    include_directories: [ecmd_plugin_inc],
    dependencies: ecmd_plugin_deps,
    version: '1.0.0',
    soversion: '1',
    install: true,
    install_dir: get_option('libdir'),
)

ecmd_plugin_dep = declare_dependency(
    link_with: ecmd_plugin_lib,
    include_directories: [ecmd_plugin_inc],
    dependencies: ecmd_plugin_deps,
)

# ---------------------------------------------------------------------
# pkg-config file generation
# ---------------------------------------------------------------------

pkgconfig = import('pkgconfig')

pkgconfig.generate(
    libraries: ecmd_plugin_lib,
    version: meson.project_version(),
    filebase: 'ecmd-plugin',
    name: 'ecmd-plugin',
    description: 'eCMD platform plugin shared library',
    subdirs: 'ecmd',
    requires: ['ipl', 'pdbg', 'ecmd', 'phosphor-logging'],
)
