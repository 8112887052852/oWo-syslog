# author: 8112887052852
project(oWo-syslog)

cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GoogleTest)

# latex config
set(LATEX_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/documentation)
include(CMake/CMakeLatex/UseLATEX.cmake)

add_library(header SHARED)
add_library(cheader SHARED src/header/header.cpp)

add_subdirectory(dependencies)
add_subdirectory(doc)
add_subdirectory(src)

enable_testing()
