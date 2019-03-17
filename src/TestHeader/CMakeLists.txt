# author: 8112887052852
target_compile_definitions(TestHeader PRIVATE SYSLOG_NAMES)

target_sources(TestHeader PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

target_compile_definitions(TestCHeader PRIVATE DISABLE_MODERN_OWO_SYSLOG SYSLOG_NAMES)

target_sources(TestCHeader PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

add_subdirectory(testfiles)