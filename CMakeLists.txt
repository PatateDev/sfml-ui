cmake_minimum_required(VERSION 2.6)
project(sfml-ui)

set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type : Release or Debug" FORCE)
set(SFML_INCLUDE_PATH  /usr/include CACHE PATH "Location of SFML's include folder")
set(SFML_LIBRARY_PATH /usr/lib CACHE PATH "Location of SFML's library folder")
set(BUILD_SHARED TRUE CACHE BOOL "Build the library shared or not (static)")

set(LIBRARY_OUTPUT_PATH lib/)
set(SFML_LIBS sfml-graphics sfml-window sfml-system)
include_directories(include)
include_directories(${SFML_INCLUDE_PATH})
link_directories(${SFML_LIBRARY_PATH})

if(BUILD_SHARED)
    set(BUILD_NAME SHARED)
else()
    set(BUILD_NAME STATIC)
endif()

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
    ${SFML_LIBS}
)
