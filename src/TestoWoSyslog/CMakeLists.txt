# author: 8112887052852
add_executable(TestliboWoSyslog
	main.cpp
	)

target_link_libraries(TestliboWoSyslog
	gtest
	gmock
	asio
	)
