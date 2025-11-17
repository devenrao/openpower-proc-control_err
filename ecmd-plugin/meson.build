# meson.build for ecmd-plugin

# ---------------------------------------------------------------------
# Source files
# ---------------------------------------------------------------------

ecmd_plugin_src = files(
  'ecmd_dll_cfam.cpp',
  'ecmd_dll_init.cpp',
  'ecmd_dll_istep.cpp',
  'ecmd_dll_scom.cpp',
  'ecmd_dll_query.cpp',
  'ecmd_dll_ring.cpp',
  'ecmd_util.cpp',
)

# ---------------------------------------------------------------------
# Paths passed from bitbake/recipe
# ---------------------------------------------------------------------

ecmd_src_dir = get_option('ecmd_src_dir')   # e.g. recipe-sysroot/usr/lib/ecmd
ecmd_inc_dir = get_option('ecmd_inc_dir')   # e.g. recipe-sysroot/usr/include/ecmd

ecmd_generated_src = files(
  ecmd_src_dir / 'ecmdClientCapiFunc.C',
  ecmd_src_dir / 'ecmdDllCapi.C',
)

ecmd_generated_inc = include_directories(ecmd_inc_dir)

# ---------------------------------------------------------------------
# Include directories
# ---------------------------------------------------------------------

ecmd_plugin_inc = include_directories('.')

# ---------------------------------------------------------------------
# Libraries
# ---------------------------------------------------------------------

ipl_dep  = cxx.find_library('ipl', required: true)
ecmd_dep = cxx.find_library('ecmd', required: true)
pdbg_dep = cxx.find_library('pdbg', required: true)
phosphor_logging_dep = dependency('phosphor-logging')

ecmd_plugin_deps = [
  ipl_dep,
  ecmd_dep,
  pdbg_dep,
  phosphor_logging_dep,
]

#---------------------------------------------------------------
#Remove unsupported functions
#---------------------------------------------------------------
ecmd_remove_flags = [
  '-DECMD_STATIC_FUNCTIONS',
  '-DECMD_REMOVE_RING_FUNCTIONS',
  '-DECMD_REMOVE_LATCH_FUNCTIONS',
  '-DECMD_REMOVE_ARRAY_FUNCTIONS',
  '-DECMD_REMOVE_SPY_FUNCTIONS',
  '-DECMD_REMOVE_TRACEARRAY_FUNCTIONS',
  '-DECMD_REMOVE_JTAG_FUNCTIONS',
  '-DECMD_REMOVE_CLOCK_FUNCTIONS',
  '-DECMD_REMOVE_REFCLOCK_FUNCTIONS',
  '-DECMD_REMOVE_PROCESSOR_FUNCTIONS',
  '-DECMD_REMOVE_MPIPL_FUNCTIONS',
  '-DECMD_REMOVE_MEMORY_FUNCTIONS',
  '-DECMD_REMOVE_BLOCK_FUNCTIONS',
  '-DECMD_REMOVE_SP_FUNCTIONS',
  '-DECMD_REMOVE_UNITID_FUNCTIONS',
  '-DECMD_REMOVE_VPD_FUNCTIONS',
  '-DECMD_REMOVE_I2C_FUNCTIONS',
  '-DECMD_REMOVE_GPIO_FUNCTIONS',
  '-DECMD_REMOVE_POWER_FUNCTIONS',
  '-DECMD_REMOVE_ADAL_FUNCTIONS',
  '-DECMD_REMOVE_SENSOR_FUNCTIONS',
  '-DECMD_REMOVE_PNOR_FUNCTIONS',
  '-DECMD_REMOVE_SPI_FUNCTIONS',
]

# ---------------------------------------------------------------------
# Build the shared library
# ---------------------------------------------------------------------
ecmd_plugin_lib = shared_library(
  'ecmd-plugin',
  ecmd_plugin_src + ecmd_generated_src,
  include_directories: [
      ecmd_plugin_inc,
      ecmd_generated_inc,
  ],
  dependencies: ecmd_plugin_deps,
  cpp_args: ecmd_remove_flags,
  version: '1.0.0',
  soversion: '1',
  install: true,
  install_dir: get_option('libdir'),
)

ecmd_plugin_dep = declare_dependency(
    link_with: ecmd_plugin_lib,
    include_directories: [ecmd_plugin_inc, ecmd_generated_inc],
    dependencies: ecmd_plugin_deps
)

# ---------------------------------------------------------------------
# pkg-config file generation
# ---------------------------------------------------------------------
pkgconfig = import('pkgconfig')

pkgconfig.generate(
  libraries: ecmd_plugin_lib,        # <— use the variable returned above
  version: meson.project_version(),
  filebase: 'ecmd-plugin',
  name: 'ecmd-plugin',
  description: 'eCMD platform plugin shared library',
  subdirs: 'ecmd',
  requires: [
    'ipl',
    'pdbg',
    'ecmd',
    'phosphor-logging'
  ],
)

