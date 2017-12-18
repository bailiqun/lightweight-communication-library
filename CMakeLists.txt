cmake_minimum_required(VERSION 2.8.12)
project(serial)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

#find_package(catkin REQUIRED COMPONENTS  roscpp rospy sensor_msgs std_msgs nav_msgs geometry_msgs tf)
find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIR})
#include_directories(include  ${catkin_INCLUDE_DIRS})

link_directories(${Boost_LIBRARY_DIRS})
add_executable(serial
    main.cpp
)
target_link_libraries(serial ${Boost_LIBRARIES})
