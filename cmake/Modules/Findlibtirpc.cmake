find_package(PkgConfig)
pkg_check_modules(PC_LIBTIRPC QUIET libtirpc)
set(TIRPC_DEFINITIONS ${PC_LIBTIRPC_CFLAGS_OTHER})

find_path(TIRPC_INCLUDE_DIR rpc/rpc.h
          HINTS ${PC_LIBTIRPC_INCLUDEDIR} ${PC_LIBTIRPC_INCLUDE_DIRS}
          PATH_SUFFIXES libtirpc )

find_library(TIRPC_LIBRARY NAMES tirpc libtirpc
             HINTS ${PC_LIBTIRPC_LIBDIR} ${PC_LIBTIRPC_LIBRARY_DIRS} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set TIRPC_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libtirpc DEFAULT_MSG
                                  TIRPC_LIBRARY TIRPC_INCLUDE_DIR)

mark_as_advanced(TIRPC_INCLUDE_DIR TIRPC_LIBRARY )

set(TIRPC_LIBRARIES ${TIRPC_LIBRARY} )
set(TIRPC_INCLUDE_DIRS ${TIRPC_INCLUDE_DIR} )

add_library(TIRPC::TIRPC INTERFACE IMPORTED)
set_target_properties(TIRPC::TIRPC PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${TIRPC_INCLUDE_DIRS}"
    INTERFACE_LINK_LIBRARIES "${TIRPC_LIBRARY}"
)
