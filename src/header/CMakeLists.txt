# author: 8112887052852
target_sources(header PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/header.cpp)

target_compile_definitions(cheader PRIVATE DISABLE_MODERN_OWO_SYSLOG)

target_sources(cheader PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/header.cpp)