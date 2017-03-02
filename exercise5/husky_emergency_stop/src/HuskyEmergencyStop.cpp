#include "husky_emergency_stop/HuskyEmergencyStop.hpp"

// STD
#include <string>

namespace husky_emergency_stop {

HuskyEmergencyStop::HuskyEmergencyStop(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  ROS_INFO("Successfully launched node.");

  // initialize subscriber
  subscriber_ = nodeHandle.subscribe("/scan", 10, &HuskyEmergencyStop::topicCallback, this);
  client_ = nodeHandle.serviceClient<std_srvs::SetBool>("/pause_husky");

}

HuskyEmergencyStop::~HuskyEmergencyStop()
{
}

void HuskyEmergencyStop::topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  int i = 0;
  int size = msg->ranges.size();

  float min_dis = 10000;
  float min_i = 0;

  // get min distance
  for (i = 0; i < size; i++) {
    float dist = msg->ranges.at(i);

    if (dist < min_dis) {
      min_dis = dist;
      min_i = i;
    }
  }

  std_srvs::SetBool service;

  if (min_dis < 1.0) {
    // too close
    service.request.data = true;

    if (client_.call(service)) {
      ROS_INFO("Response msg: %s", service.response.message.c_str());
    } else {
      ROS_ERROR("Failed to call service");
      return;
    }
  }
}
} /* namespace */
