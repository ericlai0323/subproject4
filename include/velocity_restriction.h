#include <cstdio>
#include <stdlib.h>
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>

class CommandVelocityRestriction
{
public:
    // ROS Command Velocity Topic
    geometry_msgs::Twist CommandVelocity;
    geometry_msgs::Twist CommandVelocityRestrict;
    void CommandVelocityCallBack(const geometry_msgs::Twist &msg);

private:
        // int main(int argc, char *argv[]);
    float MinLinearVelocityX = 0.5;
    float MinAngularVelocityZ = 0.1;
};