cmake_minimum_required(VERSION 3.10)
project(imgui CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_STANDARD 14)

if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /MTd /Z7")
    set(CMAKE_CXX_FLAGS_RELEASE "/Os")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O0 -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-Os")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(
    GLOB_RECURSE
    source_files
    LIST_DIRECTORIES TRUE
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)

list(FILTER source_files EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/examples/.*")
list(FILTER source_files EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/misc/freetype/.*")

add_library(${CMAKE_PROJECT_NAME} STATIC ${source_files})

foreach(source IN LISTS source_list)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()
