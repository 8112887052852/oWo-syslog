SET(COMMON_SOURCES ${CMAKE_CURRENT_LIST_DIR}/TestPriorities.cpp)

target_sources(TestHeader PRIVATE ${COMMON_SOURCES})

target_sources(TestCHeader PRIVATE ${COMMON_SOURCES})