cmake_minimum_required(VERSION 2.8)
project(test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

LINK_LIBRARIES("/usr/local/lib/libboost_system.a")
LINK_LIBRARIES("/usr/local/lib/libboost_thread.a")
add_executable(test
    main.cpp
)
