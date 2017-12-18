#include <iostream>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

//#include <ros/ros.h>
//#include <sensor_msgs/Joy.h>

#include "serial.h"
#include "msgs/VelocityMsg3.hpp"
#include "msgs/VelocityMsg4.hpp"

VelocityMsg3 serial_vel_msg;

void Callback(const char* topic, const VelocityMsg3& msg)
{
    printf("vx=%03.2f  vy=%03.2f  vz=%03.2f\r\n", msg.vx, msg.vy, msg.vz);
    fflush(stdout);
}

//void joy_callback(const sensor_msgs::Joy::ConstPtr& msg)
//{
//    const float alpha = 0.5;
//    serial_vel_msg.vx = msg->axes[1] * alpha;
//    serial_vel_msg.vy = msg->axes[0] * alpha;
//    serial_vel_msg.vz = msg->axes[3] * alpha;
//}


int main(int argc, char *argv[])
{
//    ros::init(argc, argv, "serial_joy");
//    ros::NodeHandle n;
//    ros::Rate rate(50);
//    ros::Subscriber sub = n.subscribe("joy", 10, joy_callback);

    NodeHandleSerial serial;
    serial.subscribe<VelocityMsg3>(0x10,"[Global Velocity]", &Callback);

    while(1)
    {
        serial.publish(0x10, &serial_vel_msg);
//        ros::spinOnce();
//        rate.sleep();
    }
    return 0;
}
