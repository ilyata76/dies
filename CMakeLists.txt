cmake_minimum_required (VERSION 3.18) 
 
set (PROJECT PROJECT_DIES) 
 
project (${PROJECT}) 
 
set (HEADERS 
	src/dies.hpp)
 
set (SOURCES 
	src/dies.cpp
	src/main.cpp) 
 
add_executable (${PROJECT} ${HEADERS} ${SOURCES})