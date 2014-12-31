# This script locates the SFML-UI library
# ------------------------------------
#
# Usage
# -----
#
# You can enforce a specific version, either MAJOR.MINOR or only MAJOR.
# If nothing is specified, the version won't be checked (i.e. any version will be accepted).
# example:
#   find_package(SFML-UI COMPONENTS ...)     // no specific version required
#   find_package(SFML-UI 0 COMPONENTS ...)   // any 0.x version
#   find_package(SFML-UI 0.5 COMPONENTS ...) // version 0.5 or greater
#
# By default, the dynamic libraries of SFML-UI will be found. To find the static ones instead,
# you must set the SFML_UI_STATIC_LIBRARY variable to TRUE before calling find_package(SFML-UI ...).
# In case of static linking, the SFML_STATIC macro will also be defined by this script.
# example:
#   set(SFML_UI_STATIC_LIBRARY TRUE)
#   find_package(SFML_UI 0)
#
# On Mac OS X if SFML_UI_STATIC_LIBRARY is not set to TRUE then by default CMake will search for frameworks unless
# CMAKE_FIND_FRAMEWORK is set to "NEVER" for example. Please refer to CMake documentation for more details.
# Moreover, keep in mind that SFML-UI frameworks are only available as release libraries unlike dylibs which
# are available for both release and debug modes.
#
# If SFML-UI is not installed in a standard path, you can use the SFML_UI_ROOT CMake (or environment) variable
# to tell CMake where SFML is.
#
# Output
# ------
#
# This script defines the following variables:
# - SFML_UI_LIBRARY_DEBUG:   the name of the debug library of the UI module (set to SFML_UI_LIBRARY_RELEASE is no debug version is found)
# - SFML_UI_LIBRARY_RELEASE: the name of the release library of the UI module (set to SFML_UI_LIBRARY_DEBUG is no release version is found)
# - SFML_UI_LIBRARY:         the name of the library to link to for the UI module (includes both debug and optimized names if necessary)
# - SFML_UI_FOUND:           true if either the debug or release library of the UI module is found
# - SFML_UI_INCLUDE_DIR:  the path where SFML headers are located (the directory containing the SFML/UI.hpp file)
#
# example:
#   find_package(SFML_UI 0 REQUIRED)
#   include_directories(${SFML_UI_INCLUDE_DIR})
#   add_executable(myapp ...)
#   target_link_libraries(myapp ${SFML_UI_LIBRARY})

# define the SFML_STATIC macro if static build was chosen
if(SFML_UI_STATIC_LIBRARY)
    add_definitions(-DSFML_STATIC)
endif()

# define the list of search paths for headers and libraries
set(FIND_SFML_UI_PATHS
    ${SFML_UI_ROOT}
    $ENV{SFML_UI_ROOT}
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local
    /usr
    /sw
    /opt/local
    /opt/csw
    /opt)

if (SFML_OS_ANDROID)
    set(CMAKE_FIND_ROOT_PATH ${ANDROID_NDK}/sources/sfml-ui)
    set(CMAKE_LIBRARY_ARCHITECTURE ${ANDROID_ABI})
endif()

# find the SFML include directory
find_path(SFML_UI_INCLUDE_DIR SFML/UI.hpp
          PATH_SUFFIXES include
	  PATHS ${FIND_SFML_UI_PATHS})
# check the version number
set(SFML_UI_VERSION_OK TRUE)
if(SFML_UI_FIND_VERSION AND SFML_UI_INCLUDE_DIR)
    # extract the major and minor version numbers from SFML/Config.hpp
    # we have to handle framework a little bit differently:
    if("${SFML_UI_INCLUDE_DIR}" MATCHES "SFML.framework")
	    set(SFML_UI_HPP_INPUT "${SFML_UI_INCLUDE_DIR}/Headers/UI.hpp")
    else()
	    set(SFML_UI_HPP_INPUT "${SFML_UI_INCLUDE_DIR}/SFML/UI.hpp")
    endif()
    FILE(READ "${SFML_UI_HPP_INPUT}" SFML_UI_HPP_CONTENTS)
    STRING(REGEX MATCH ".*#define SFML_UI_VERSION_MAJOR ([0-9]+).*#define SFML_UI_VERSION_MINOR ([0-9]+).*#define SFML_UI_VERSION_PATCH ([0-9]+).*" SFML_UI_HPP_CONTENTS "${SFML_UI_HPP_CONTENTS}")
    
    set(SFML_UI_VERSION_MAJOR "-1")
    STRING(REGEX REPLACE ".*#define SFML_UI_VERSION_MAJOR ([0-9]+).*" "\\1" SFML_UI_VERSION_MAJOR "${SFML_UI_HPP_CONTENTS}")
    
    STRING(REGEX REPLACE ".*#define SFML_UI_VERSION_MINOR ([0-9]+).*" "\\1" SFML_UI_VERSION_MINOR "${SFML_UI_HPP_CONTENTS}")
    
    STRING(REGEX REPLACE ".*#define SFML_UI_VERSION_PATCH ([0-9]+).*" "\\1" SFML_UI_VERSION_PATCH "${SFML_UI_HPP_CONTENTS}")
    
    math(EXPR SFML_UI_REQUESTED_VERSION "${SFML_UI_FIND_VERSION_MAJOR} * 10000 + ${SFML_UI_FIND_VERSION_MINOR} * 100 + ${SFML_UI_FIND_VERSION_PATCH}")
    
    # if we could extract them, compare with the requested version number
    if (SFML_UI_VERSION_MAJOR GREATER -1)
        # transform version numbers to an integer
        math(EXPR SFML_UI_VERSION "${SFML_UI_VERSION_MAJOR} * 10000 + ${SFML_UI_VERSION_MINOR} * 100 + ${SFML_UI_VERSION_PATCH}")

        # compare them
        if(SFML_UI_VERSION LESS SFML_UI_REQUESTED_VERSION)
            set(SFML_UI_VERSION_OK FALSE)
        endif()
    else()
        message(WARNING "Cannot determinate SFML-UI's version")
    endif()
endif()

# find the requested modules
set(SFML_UI_FOUND TRUE) # will be set to false if one of the required modules is not found
set(FIND_SFML_UI_COMPONENT_LOWER "ui")
set(FIND_SFML_UI_COMPONENT_UPPER "UI")
set(FIND_SFML_UI_COMPONENT_NAME sfml-${FIND_SFML_UI_COMPONENT_LOWER})
# static release library
find_library(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE
             NAMES ${FIND_SFML_UI_COMPONENT_NAME}-s
             PATH_SUFFIXES lib64 lib
             PATHS ${FIND_SFML_UI_PATHS})

# static debug library
find_library(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG
             NAMES ${FIND_SFML_UI_COMPONENT_NAME}-s-d
             PATH_SUFFIXES lib64 lib
             PATHS ${FIND_SFML_UI_PATHS})

# dynamic release library
find_library(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE
             NAMES ${FIND_SFML_UI_COMPONENT_NAME}
             PATH_SUFFIXES lib64 lib
             PATHS ${FIND_SFML_UI_PATHS})

# dynamic debug library
find_library(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG
             NAMES ${FIND_SFML_UI_COMPONENT_NAME}-d
             PATH_SUFFIXES lib64 lib
             PATHS ${FIND_SFML_UI_PATHS})

# choose the entries that fit the requested link type
if(SFML_UI_STATIC_LIBRARY)
    if(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE)
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE})
    endif()
    if(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG)
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG})
    endif()
else()
    if(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE)
         set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE})
    endif()
    if(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG)
         set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG})
    endif()
endif()

if (SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG OR SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE)
    # library found
    set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_FOUND TRUE)

    # if both are found, set SFML_XXX_LIBRARY to contain both
    if (SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG AND SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE)
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY debug     ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG}
                                                          optimized ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE})
    endif()

    # if only one debug/release variant is found, set the other to be equal to the found one
    if (SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG AND NOT SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE)
        # debug and not release
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG})
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY         ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG})
    endif()
    if (SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE AND NOT SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG)
        # release and not debug
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE})
        set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY       ${SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE})
    endif()
else()
    # library not found
    set(SFML_UI_FOUND FALSE)
    set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_FOUND FALSE)
    set(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY "")
endif()

# mark as advanced
MARK_AS_ADVANCED(SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY
                 SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_RELEASE
                 SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DEBUG
                 SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_RELEASE
                 SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_STATIC_DEBUG
                 SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_RELEASE
                 SFML_${FIND_SFML_UI_COMPONENT_UPPER}_LIBRARY_DYNAMIC_DEBUG)

# handle errors
if(NOT SFML_UI_VERSION_OK)
    # SFML version not ok
    set(FIND_SFML_UI_ERROR "SFML-UI found but version too low (requested: ${SFML_UI_FIND_VERSION}, found: ${SFML_UI_VERSION_MAJOR}.${SFML_UI_VERSION_MINOR}.${SFML_UI_VERSION_PATCH})")
    set(SFML_UI_FOUND FALSE)
elseif(NOT SFML_UI_FOUND)
    # include directory or library not found
    set(FIND_SFML_UI_ERROR "Could NOT find SFML-UI")
endif()
if (NOT SFML_UI_FOUND)
    if(SFML_UI_FIND_REQUIRED)
        # fatal error
        message(FATAL_ERROR ${FIND_SFML_UI_ERROR})
    elseif(NOT SFML_UI_FIND_QUIETLY)
        # error but continue
        message("${FIND_SFML_UI_ERROR}")
    endif()
endif()

# handle success
if(SFML_UI_FOUND AND NOT SFML_UI_FIND_QUIETLY)
    message(STATUS "Found SFML-UI ${SFML_UI_VERSION_MAJOR}.${SFML_UI_VERSION_MINOR}.${SFML_UI_VERSION_PATCH} in ${SFML_UI_INCLUDE_DIR}")
endif()
