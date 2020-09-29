cmake_minimum_required (VERSION 3.18) 
 
set (PROJECT PROJECT_DIES) 
 
project (${PROJECT}) 
 
set (HEADERS 
	src/dies.hpp
	src/dies/date.hpp)
 
set (SOURCES 
	test/main.cpp) 
 
add_executable (${PROJECT} ${HEADERS} ${SOURCES})