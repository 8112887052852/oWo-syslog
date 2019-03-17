# author: 8112887052852

SET(CLIENT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/header.cpp
        ${CMAKE_CURRENT_LIST_DIR}/CurrentTimeFunctor.cpp)

target_sources(header PRIVATE ${CLIENT_SOURCES})

target_sources(cheader PRIVATE ${CLIENT_SOURCES})