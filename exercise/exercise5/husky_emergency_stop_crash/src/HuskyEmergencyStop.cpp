#include "husky_emergency_stop/HuskyEmergencyStop.hpp"

// STD
#include <string>

namespace husky_emergency_stop {

HuskyEmergencyStop::HuskyEmergencyStop(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  ROS_INFO("Successfully launched node.");

  // initialize subscriber
  subscriber_ = nodeHandle.subscribe("/imu/data", 10, &HuskyEmergencyStop::topicCallback, this);
  client_ = nodeHandle.serviceClient<std_srvs::SetBool>("/pause_husky");

}

HuskyEmergencyStop::~HuskyEmergencyStop()
{
}

void HuskyEmergencyStop::topicCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
  float acc_x = msg->linear_acceleration.x;
  float acc_y = msg->linear_acceleration.y;

  std_srvs::SetBool service;

  if (pow(acc_x, 2) + pow(acc_y, 2) > pow(0.5, 2)) {
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
