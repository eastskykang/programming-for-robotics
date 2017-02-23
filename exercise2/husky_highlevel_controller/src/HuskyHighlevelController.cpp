#include "husky_highlevel_controller/HuskyHighlevelController.hpp"

namespace husky_highlevel_controller {

HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
  subscriber_ = nodeHandle.subscribe("/scan", 10, &HuskyHighlevelController::topicCallback, this);

  std::string topic;
  int queue_size;

  if(!nodeHandle.getParam("topic", topic)) {
    ROS_ERROR("Could not find topic parameter!");
  }

  if (!nodeHandle.getParam("queue_size", queue_size)) {
    ROS_ERROR("Could not find queue_size parameter!");
  }
}

HuskyHighlevelController::~HuskyHighlevelController()
{
}

void HuskyHighlevelController::topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  int i = 0;
  int size = msg->ranges.size();

  float min_dis = 10000;

  for (i = 0; i < size; i++)
  {
    float dist = msg->ranges.at(i);

    if (dist < min_dis) min_dis = dist;
  }

  ROS_INFO("min distance: %f", min_dis);
}

} /* namespace */

