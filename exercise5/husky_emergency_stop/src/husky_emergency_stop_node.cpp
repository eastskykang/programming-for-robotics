#include <ros/ros.h>
#include "husky_emergency_stop/HuskyEmergencyStop.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ros_package_template");
  ros::NodeHandle nodeHandle("~");

  husky_emergency_stop::HuskyEmergencyStop husky_emergency_stop(nodeHandle);

  ros::spin();
  return 0;
}
