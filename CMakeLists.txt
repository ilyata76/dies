cmake_minimum_required (VERSION 3.18) 
 
set (PROJECT PROJECT_DIES) 
 
project (${PROJECT}) 
 
set (HEADERS 
	src/dies.hpp
	src/dies/date.hpp
	src/dies/drand.hpp
	src/calen/calen.hpp
	src/calen/calenday.hpp
	src/calen/calenmonth.hpp
)
 
set (SOURCES 
	src/dies/src/date.cpp
	src/dies/src/drand.cpp
	src/calen/src/calen.cpp
	src/calen/src/calenday.cpp
	src/calen/src/calenmonth.cpp
	test/source.cpp
) 
 
add_executable (${PROJECT} ${HEADERS} ${SOURCES})