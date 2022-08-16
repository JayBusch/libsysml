cmake_minimum_required(VERSION 3.18)

project(libsysml LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
SET(CMAKE_C_FLAGS_DEBUG "-O0 -g")
# SET(CMAKE_EXE_LINKER_FLAGS "-v")

# add_subdirectory(dependencies)

add_subdirectory(src)

