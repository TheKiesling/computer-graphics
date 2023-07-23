cmake_minimum_required(VERSION 3.26)

project(HW VERSION 1.0)

add_executable(${PROJECT_NAME}
	src/main.cpp
)

find_package(SDL2 REQUIRED)

target(${PROJECT_NAME}
	${SDL2_LIBRARIES}
)
