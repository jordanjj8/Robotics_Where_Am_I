// Jordan Leung
// process_image v2 using a class 
// a client node that will subscribe to the robot's camera images and analyze them to determine the position of the white ball 
// will request a service from the drive_bot server to drive the robot towards the ball 

// Jordan Leung
// process_image 
// a client node that will subscribe to the robot's camera images and analyze them to determine the position of the white ball 
// will request a service from the drive_bot server to drive the robot towards the ball 

#include "process_image.h"

// ProcessImage constructor 
ProcessImage::ProcessImage(ros::NodeHandle* nodehandle):n(*nodehandle)
{
	// constructor 
	ROS_INFO("in class constructor of ProcessImage");
	initialize_subscribers();
	initialize_clients();
}

void ProcessImage::initialize_subscribers()
{
	ROS_INFO("Initializing Subscribers");
	// subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
	//ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);
	sub1 = n.subscribe("/camera/rgb/image_raw", 10, &ProcessImage::process_image_callback, this);

}

void ProcessImage::initialize_clients()
{
	ROS_INFO("Initializing Clients");
	// define a client service capable of requesting services from command_robot
	client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

}


ros::ServiceClient* ProcessImage::get_client()
{
	return &client;
}


// this function calls the command_robot service to drive the robot in the specified direction (left, right, or forward)
void drive_robot(float lin_x, float ang_z, ProcessImage* ptr)
{
	// request robot to move according to the processed image 
	ball_chaser::DriveToTarget srv; 
	srv.request.linear_x = lin_x;
	srv.request.angular_z = ang_z;

	if (!ptr->get_client()->call(srv))
		ROS_ERROR("Failed to call service drive_bot");
}

// this callback function continuously executes and reads the image data 
void ProcessImage::process_image_callback(const sensor_msgs::Image img)
{

	int white_pixel = 255;
	bool ball_present = false; // flag for whether or not ball is present or not 
	int ball_location = 0;
	int pixels_found = 0;

	for (int i = 0; i< (img.step * img.height -2); i++) {
		if (img.data[i] == white_pixel && img.data[i+1] == white_pixel && img.data[i+2] == white_pixel) {
			ball_present = true;
			// using modulus results in a remainder that allows for simple comparison to the step
			//pixels_found += 1;
			//ball_location += i;
			ball_location = i%img.step;
			break;		
		}
	}
	//if (ball_present == true) {
	// get the avg location (ideally the center) of the ball
	//ball_location = (ball_location/pixels_found)%img.step;
	//}

	if (ball_location < img.step/3 && ball_present == true) {
		// left 
		drive_robot(0.15, 0.35, this);
	} else if (ball_location > img.step/3 && ball_location < img.step*2/3 && ball_present == true) {
		// forward
		drive_robot(0.15, 0, this);
	} else if (ball_present == true) {
		//right 
		drive_robot(0.15, -0.35, this);
	} else {
		// stop 
		drive_robot(0,0, this);	
}



}

int main(int argc, char** argv)
{
	// initialize the process_image node and create a handle to it
	// ROS setup 
	ros::init(argc, argv, "process_image");
	ros::NodeHandle n; // node handle, now need to pass this to the class constructor 

	ROS_INFO("main: instantiating an object of type process_image");
	ProcessImage ProcessImage(&n); // instantiate a ProcessImage object type and pass in the node handle pointer for the constructor to use 


	ROS_INFO("main: going into spin; let the callbacks do all the work");
	// handle ROS communication events
	ros::spin();
	return 0;
}

