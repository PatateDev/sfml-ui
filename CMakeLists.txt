cmake_minimum_required(VERSION 2.6)
project(sfml-ui)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

if (NOT SFML_INCLUDE_PATH)
	set(SFML_INCLUDE_PATH  /usr/include CACHE PATH "Location of SFML's include folder")
endif()
if (NOT SFML_LIBRARY_PATH)
	set(SFML_LIBRARY_PATH  /usr/include CACHE PATH "Location of SFML's library folder")
endif()
if (NOT BUILD_SHARED)
	set(BUILD_SHARED TRUE CACHE BOOL "Build the library shared or not (static)")
endif()

set(LIBRARY_OUTPUT_PATH lib)

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
	sfml-graphics
	sfml-window
	sfml-system
)

install(TARGETS sfml-ui DESTINATION lib)
install(DIRECTORY include DESTINATION .)
