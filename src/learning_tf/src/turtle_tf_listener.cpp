/*
This demo file is to listen to the transform of turtle1 and tutle 2 at different time instances which leads to various motion of turtle2
*/
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle =
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);

  ros::Publisher turtle_vel =
    node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);

  tf::TransformListener listener;

  ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform;
    
    // turtle2 will follow turtle1 by taking transformation at current time. Works well
    // try{
    //   listener.lookupTransform("/turtle2", "/turtle1",
    //                            ros::Time::now(), transform);
    // }
    
    // turtle2 will follow turtle1 by taking transformation at delayed time of 3. Works well
    // try{
    //   ros::Time now = ros::Time::now();
    //   listener.waitForTransform("/turtle2", "/turtle1",
    //                             now, ros::Duration(3.0));
    //   listener.lookupTransform("/turtle2", "/turtle1",
    //                            now, transform);
    // }

    // turtle2 will follow turtle1 by taking transformation of turtle1 frame and turtle2 frame 5 seconds before now. 
    // Does not works well and results in waivy motion as the frames are not defined at -5 seconds
    // http://wiki.ros.org/tf/Tutorials/Time%20travel%20with%20tf%20%28C%2B%2B%29

    // try{
    //   ros::Time past = ros::Time::now() - ros::Duration(5.0);
    //   listener.waitForTransform("/turtle2", "/turtle1",
    //                             past, ros::Duration(1.0));
    //   listener.lookupTransform("/turtle2", "/turtle1",
    //                            past, transform);
    // }

    // turtle2 will follow turtle1 by taking transformation of turtle1 frame 5 seconds before now and turtle2 frame now. 
    // Works well. turtle2 follows turtle1 position 5 seconds in the past
    // This is done using advanced API for lookupTransform which now takes 6 arguments and needs a fixed frame (world in our case)
    // as reference. wiatForTransform also takes 6 arguments in advanced API. 
    // http://wiki.ros.org/tf/Tutorials/Time%20travel%20with%20tf%20%28C%2B%2B%29
    
    try{
        ros::Time now = ros::Time::now();
        ros::Time past = now - ros::Duration(5.0);
        listener.waitForTransform("/turtle2", now,
                                  "/turtle1", past,
                                  "/world", ros::Duration(1.0));
        listener.lookupTransform("/turtle2", now,
                                 "/turtle1", past,
                                 "/world", transform);
      }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    geometry_msgs::Twist vel_msg;
    vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(),
                                    transform.getOrigin().x());
    vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                  pow(transform.getOrigin().y(), 2));
    turtle_vel.publish(vel_msg);

    rate.sleep();
  }
  return 0;
};
