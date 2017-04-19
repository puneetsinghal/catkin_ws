
YOUBOT Tutorials

------------------------------------------------------------------------
Installation Packages
------------------------------------------------------------------------

ROS Indigo: http://www.youbot-store.com/wiki/index.php/Gazebo_simulation
Since no pre-compiled debian packages are available so far, you have to check out manually. To do that, first create a Catkin workspace, and enter in a terminal

# sudo apt-get install ros-indigo-ros-control ros-indigo-ros-controllers ros-indigo-gazebo-ros-control
# cd <your-catkin-folder>/src
# git clone http://github.com/youbot/youbot_description.git -b indigo-devel
# git clone http://github.com/youbot/youbot_simulation.git
# catkin_make

The last command should run through without errors. In order to launch it, enter

# roslaunch youbot_gazebo_robot youbot.launch 

Note: the simulated motion of the robot can be very slow, as the mobile base uses a non-optimized controller.

------------------------------------------------------------------------

------------------------------------------------------------------------


------------------------------------------------------------------------

------------------------------------------------------------------------

------------------------------------------------------------------------

------------------------------------------------------------------------

rostopic pub /cmd_vel geometry_msgs/Twist "linear:
        x: 0.5
        y: 0.0
        z: 0.0
angular:
        x: 0.0
        y: 0.0
        z: 0.0"