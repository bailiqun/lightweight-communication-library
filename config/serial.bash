#!/bin/bash 
export PATH=$PATH:/opt/ros/indigo/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/x86_64-linux-gnu
source /opt/ros/indigo/setup.bash
source /home/wellcasa_i5/catkin_ws/devel/setup.bash

roslaunch serial serial.launch
