cmake_minimum_required(VERSION 2.8)
project(sfml-ui)

# include the configuration file
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake)

# setup version numbers
set(VERSION_MAJOR 0)
set(VERSION_MINOR 3)
set(VERSION_PATCH 1)

# define a macro that helps defining an option
macro(sfml_set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

sfml_set_option(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)

if (SFML_OS_WINDOWS)
    sfml_set_option(SFML_INCLUDE_PATH  "C:/Program Files (x86)/SFML/include" CACHE PATH "Location of SFML's include folder" FORCE)
    sfml_set_option(SFML_LIBRARY_PATH  "C:/Program Files (x86)/SFML/lib" CACHE PATH "Location of SFML's library folder" FORCE)
else()
    sfml_set_option(SFML_INCLUDE_PATH  /usr/include CACHE PATH "Location of SFML's include folder" FORCE)
    sfml_set_option(SFML_LIBRARY_PATH  /usr/lib CACHE PATH "Location of SFML's library folder" FORCE)
endif()

if(NOT (SFML_OS_IOS OR SFML_OS_ANDROID))
    sfml_set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build SFML as shared libraries, FALSE to build it as static libraries")
else()
    if(SFML_OS_IOS)
        set(BUILD_SHARED_LIBS FALSE)
    elseif(SFML_OS_ANDROID)
        set(BUILD_SHARED_LIBS TRUE)
    endif()
endif()

set(LIBRARY_OUTPUT_PATH lib)

include_directories(include)
include_directories(${SFML_INCLUDE_PATH})
link_directories(${SFML_LIBRARY_PATH})

if(BUILD_SHARED_LIBS)
    set(BUILD_NAME SHARED)
else()
    set(BUILD_NAME STATIC)
endif()

# Android options
if(SFML_OS_ANDROID)
    # force usage of the STL port
    set(ANDROID_USE_STLPORT TRUE)

    # make sure there's the android library available
    if (${ANDROID_NATIVE_API_LEVEL} LESS 9)
        message(FATAL_ERROR "API level must be equal or greater than 9")
    endif()

    # install everything in $NDK/sources/ because this path is appended by the NDK (convenient)
    set(CMAKE_INSTALL_PREFIX ${ANDROID_NDK}/sources/sfml)

    # we install libs in a subdirectory named after the ABI (lib/mips/*.so)
    set(LIB_SUFFIX "/${ANDROID_ABI}")

    # this is a workaround to compile sfml-activity without stlport_shared as dependency
    # we save the original compilation command line to restore it later in Macro.cmake
    set(CMAKE_CXX_CREATE_SHARED_LIBRARY_WITH_STLPORT ${CMAKE_CXX_CREATE_SHARED_LIBRARY})
    set(CMAKE_CXX_CREATE_SHARED_LIBRARY_WITHOUT_STLPORT "<CMAKE_CXX_COMPILER> <CMAKE_SHARED_LIBRARY_CXX_FLAGS> <LANGUAGE_COMPILE_FLAGS> <LINK_FLAGS> <CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS> <SONAME_FLAG><TARGET_SONAME> -o <TARGET> <OBJECTS> <LINK_LIBRARIES>")
endif()

# define an option for choosing between static and dynamic C runtime (Windows only)
if(SFML_OS_WINDOWS)
    sfml_set_option(SFML_USE_STATIC_STD_LIBS FALSE BOOL "TRUE to statically link to the standard libraries, FALSE to use them as DLLs")

    # the following combination of flags is not valid
    if (BUILD_SHARED_LIBS AND SFML_USE_STATIC_STD_LIBS)
        message(FATAL_ERROR "BUILD_SHARED_LIBS and SFML_USE_STATIC_STD_LIBS cannot be used together")
    endif()

    # for VC++, we can apply it globally by modifying the compiler flags
    if(SFML_COMPILER_MSVC AND SFML_USE_STATIC_STD_LIBS)
        foreach(flag
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
            if(${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif()
        endforeach()
    endif()
endif()

# disable the rpath stuff
set(CMAKE_SKIP_BUILD_RPATH TRUE)

if(SFML_OS_LINUX OR SFML_OS_FREEBSD)
    if(BUILD_SHARED_LIBS)
        sfml_set_option(SFML_INSTALL_PKGCONFIG_FILES FALSE BOOL "TRUE to automatically install pkg-config files so other projects can find SFML")
        if(SFML_INSTALL_PKGCONFIG_FILES)
            CONFIGURE_FILE(
                "tools/pkg-config/sfml-ui.pc.in"
                "tools/pkg-config/sfml-ui.pc"
                    @ONLY)
            INSTALL(FILES "${CMAKE_CURRENT_BINARY_DIR}/tools/pkg-config/sfml-ui.pc"
                    DESTINATION "${CMAKE_INSTALL_PREFIX}/lib${LIB_SUFFIX}/pkgconfig")
        endif()
    else()
        if(SFML_INSTALL_PKGCONFIG_FILES)
            message(WARNING "No pkg-config files are provided for the static SFML libraries (SFML_INSTALL_PKGCONFIG_FILES will be ignored).")
        endif()
    endif()
endif()

# enable project folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

file(
    GLOB_RECURSE
    sources
    src/*
    include/*
)

add_library(
    sfml-ui
    ${BUILD_NAME}
    ${sources}
)

target_link_libraries(
	sfml-ui
	sfml-graphics
	sfml-window
	sfml-system
)

install(TARGETS sfml-ui DESTINATION lib/${LIB_SUFFIX})
install(DIRECTORY include DESTINATION .)

if(SFML_OS_ANDROID)

    # install Android.mk so the NDK knows how to set up SFML UI
    install(FILES src/Android.mk DESTINATION .)

endif()
