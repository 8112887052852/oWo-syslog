# author: 8112887052852

include(ExternalProject)

add_subdirectory(gtest)

add_library(asio INTERFACE)
target_sources(asio INTERFACE ${CMAKE_CURRENT_LIST_DIR}/asio/asio/include/asio.hpp)

