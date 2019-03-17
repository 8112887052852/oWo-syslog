# author: 8112887052852
project(oWo-syslog)

cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GoogleTest)

# latex config
set(LATEX_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/documentation)
include(CMake/CMakeLatex/UseLATEX.cmake)

add_library(header SHARED)
target_include_directories(header PUBLIC include)

add_library(cheader SHARED)
target_include_directories(cheader PUBLIC include)

add_executable(TestliboWoSyslog)
target_link_libraries(TestliboWoSyslog
        gtest
        gmock
        asio
        )

add_executable(TestHeader)
target_link_libraries(TestHeader
	gtest
	gmock
	asio
	header
	)
target_include_directories(TestHeader PUBLIC
		include)

add_executable(TestCHeader)
target_link_libraries(TestCHeader
	gtest
	gmock
	asio
	cheader
	)
target_include_directories(TestCHeader PUBLIC
		include)

add_subdirectory(dependencies)
add_subdirectory(doc)
add_subdirectory(include)
add_subdirectory(src)

add_custom_target(modern
        DEPENDS
			header
			TestHeader
			TestliboWoSyslog)

add_custom_target(old
        DEPENDS
			cheader
			TestCHeader
			TestliboWoSyslog)

add_custom_target(bin
        DEPENDS modern old)

add_custom_target(doc
        DEPENDS pdf)

enable_testing()
