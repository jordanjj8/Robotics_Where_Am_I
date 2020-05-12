# Robotics_Where_Am_I
Project #3 Where Am I for [Robotics Software Engineer Nanodegree Program](https://www.udacity.com/course/robotics-software-engineer--nd209)

## Overview 
Refer to this YouTube link for how it performed: https://www.youtube.com/watch?v=Nc97I8n34iI
### Start 
![Start State](https://github.com/jordanjj8/Robotics_Where_Am_I/blob/master/Start.png)

### End 
![End](https://github.com/jordanjj8/Robotics_Where_Am_I/blob/master/End.JPG)

## Requirements 
* [Gazebo](http://gazebosim.org/) any version later than v7.0.0 
* ROS Kinetic -follow instructions here: [ROS Installation Instructions](http://wiki.ros.org/ROS/Installation)
* GNU make 
  - Installation for Windows 
  - Installation for Mac
  - make is installed by default for most Linux distros 
* C++11 Complier (gcc/g++)

Recommended Virtual Machine Alternative Specs:
* Ubuntu 64-bit Disk Image 
* 2 GB of RAM 
* 20 GB Disk Space
* 4 Logical Cores 

## Setup
1. After installing and meeting the requirements listed above, open up a terminal.
2. Create and initialize a catkin workspace:
``` 
    $ mkdir -p /home/workspace/catkin_ws/src
    $ cd /home/workspace/catkin_ws/src
    $ catkin_init_workspace
```
3. Clone the project repository & move the `my_robot` and `teleop_twist_keyboard` directories into the `src` directory:
```
    $ cd /home/workspace/catkin_ws/src
    $ git clone https://github.com/jordanjj8/Robotics_Where_Am_I.git
    $ mv Robotics_Where_Am_I/teleop_twist_keyboard /home/workspace/catkin_ws/src/teleop_twist_keyboard 
    $ mv Robotics_Where_Am_I/my_robot /home/workspace/catkin_ws/src/my_robot
    $ rm -rf Robotics_Where_Am_I
```
4. Navigate back to the catkin workspace and build the executables:
```
    $ cd /home/workspace/catkin_ws/
    $ catkin_make
```
5. Source the setup script and launch the launch file. The robot in Gazebo should open up:
``` 
    $ cd /home/workspace/catkin_ws/
    $ source devel/setup.bash
    $ roslaunch my_robot world.launch 
```
6. Now open up another terminal and launch amcl.launch in the my_robot package. This will enable the robot to localize itself in the map.
```
    $ cd /home/workspace/catkin_ws/
    $ source devel/setup.bash
    $ roslaunch my_robot amcl.launch
```
7. (optional) If you wish to navigate the robot manually (via keyboard), follow the instructions:
```
    $ cd /home/workspace/catkin_ws/
    $ source devel/setup.bash
    $ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```


