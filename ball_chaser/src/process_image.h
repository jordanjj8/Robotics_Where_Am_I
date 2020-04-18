// process_image.h header file
// include this file in "process_image.cpp"

#ifndef PROCESS_IMAGE_CLASS_H
#define PROCESS_IMAGE_CLASS_H

// include ros library
#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h" // include pre-defined service message, contained in shared "ball_chaser" package
#include <sensor_msgs/Image.h> // include message type used 

class ProcessImage
{
public:
	ProcessImage(ros::NodeHandle* nodehandle); // "main" needs to instantiate a ROS nodehandle and pass the pointer to the constructor 
	ros::ServiceClient* get_client();

private: 
	// private data only available to member functions of this class
	ros::NodeHandle n; 
	ros::Subscriber sub1;
	ros::ServiceClient client;

	// member methods
	void initialize_subscribers();
	void initialize_clients();

	void process_image_callback(const sensor_msgs::Image img);
	//void drive_robot(float lin_x, float ang_z);
}; 

#endif // to match with #ifndef
