// drive_bot.h header file
// include this file in "drive_bot.cpp"
//4/17/2020

#ifndef DRIVE_BOT_CLASS_H
#define DRIVE_BOT_CLASS_H

// include ros library
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h" // Include the ball_chaser "DriveToTarget" header file

class DriveBot 
{
public:
	DriveBot(ros::NodeHandle* nodehandle);

private:
	ros::NodeHandle n;
	ros::Publisher motor_command_publisher; // ROS::Publisher motor commands;
	ros::ServiceServer service;

	void initialize_services();
	void initialize_publishers();

	bool handle_drive_request(ball_chaser::DriveToTarget::Request& req, ball_chaser::DriveToTarget::Response& res);
};

#endif 
