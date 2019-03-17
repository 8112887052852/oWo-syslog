# author: 8112887052852
target_compile_definitions(header PRIVATE OWOSYSLOG_EXPORT)

target_sources(header INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/oWoSyslog.h
        )

target_compile_definitions(cheader PRIVATE DISABLE_MODERN_OWO_SYSLOG OWOSYSLOG_EXPORT)

target_sources(cheader INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/oWoSyslog.h
        )