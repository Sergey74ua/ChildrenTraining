cmake_minimum_required(VERSION 3.25)

project(Upgrade_01-Task_1 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(Upgrade_01-Task_1
	main.cpp
	inout.h
	print.cpp
	read.cpp
)

add_library(inoutlib
	print.cpp
	read.cpp
)

target_link_libraries(Upgrade_01-Task_1
	inoutlib
)