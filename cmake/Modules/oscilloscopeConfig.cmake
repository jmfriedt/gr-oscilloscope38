INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_OSCILLOSCOPE oscilloscope)

FIND_PATH(
    OSCILLOSCOPE_INCLUDE_DIRS
    NAMES oscilloscope/api.h
    HINTS $ENV{OSCILLOSCOPE_DIR}/include
        ${PC_OSCILLOSCOPE_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    OSCILLOSCOPE_LIBRARIES
    NAMES gnuradio-oscilloscope
    HINTS $ENV{OSCILLOSCOPE_DIR}/lib
        ${PC_OSCILLOSCOPE_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/oscilloscopeTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(OSCILLOSCOPE DEFAULT_MSG OSCILLOSCOPE_LIBRARIES OSCILLOSCOPE_INCLUDE_DIRS)
MARK_AS_ADVANCED(OSCILLOSCOPE_LIBRARIES OSCILLOSCOPE_INCLUDE_DIRS)
