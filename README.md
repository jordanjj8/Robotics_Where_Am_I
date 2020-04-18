# Robotics_Go_Chase_It
Project #2 Go Chase It! for [Robotics Software Engineer Nanodegree Program](https://www.udacity.com/course/robotics-software-engineer--nd209)

## Overview 
In this project, I created two ROS packages: `my_robot` and `ball_chaser` that will be used on Gazebo. The `my_robot` package includes the design of the robot, which also includes the differential drive, lidar & camera sensors, and the gazebo world the robot lives in. The `ball_chaser` package contains two C++ ROS nodes that interact with the robot and makes it chase after a white-colored ball.

## C++ ROS Nodes Description
1. `drive_bot`:
  *  A server node that will provide a ball_chaser/command_robot ROS service to drive the robot around by controlling its linear x and angular z velocities
  * The service publishes a message containing the velocities to the wheel joints
2. `process_image`:
  * A client node that subscribes to the robot's camera images and analyze them to determine the position of the white ball
  * Upon determining the position, the client node requests a service from the `drive_bot` server node to drive toward the ball
  
## Requirements 
* [Gazebo](http://gazebosim.org/) any version later than v7.0.0 
* ROS Kinetic -follow instructions here: [ROS Installation Instructions](http://wiki.ros.org/ROS/Installation)
* GNU make 
  - Installation for Windows 
  - Installation for Mac
  - make is installed by default for most Linux distros 
* C++11 Complier (gcc/g++)

Recommended Virtual Machine Alternative Specs
* Ubuntu 64-bit Disk Image 
* 2 GB of RAM 
* 20 GB Disk Space
* 4 Logical Cores 

## Setup
1. After installing and meeting the requirements listed above, open up command line.
2. Create and initialize a catkin workspace:
``` 
    $ mkdir -p /home/workspace/catkin_ws/src
    $ cd /home/workspace/catkin_ws/src
    $ catkin_init_workspace
```
2. Clone the project repository & copy the `my_robot` and `ball_chaser` directories into the `src` directory:
