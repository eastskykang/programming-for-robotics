#include "husky_highlevel_controller/HuskyHighlevelController.hpp"

namespace husky_highlevel_controller {

HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
  std::string topic;
  int queue_size;
//  int control_freq;
  float p_gain;

  // get parameter from config.yaml
  if(!nodeHandle.getParam("topic", topic)) {
    ROS_ERROR("Could not find topic parameter!");
  }

  if (!nodeHandle.getParam("queue_size", queue_size)) {
    ROS_ERROR("Could not find queue_size parameter!");
  }

  if (!nodeHandle.getParam("p_gain", p_gain)) {
    ROS_ERROR("Could not find p_gain parameter!");
  }

  // subscriber and publisher initializing
  subscriber_ = nodeHandle.subscribe(topic, queue_size, &HuskyHighlevelController::topicCallback, this);
  publisher_ = nodeHandle.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
}

HuskyHighlevelController::~HuskyHighlevelController()
{
}

void HuskyHighlevelController::topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
  int i = 0;
  int size = msg->ranges.size();

  float min_dis = 10000;
  float min_i = 0;

  // get min distance
  for (i = 0; i < size; i++)
  {
    float dist = msg->ranges.at(i);

    if (dist < min_dis) {
      min_dis = dist;
      min_i = i;
    }
  }

  // calculate x, y
  float angle_increment = msg->angle_increment;
  float angle_min = msg->angle_min;
  float rad = angle_min + angle_increment * min_i;

  float x, y;

  x = min_dis * cos(rad);
  y = min_dis * sin(rad);

  // calculate control input
  x_dot = -

  publisher_.publish(message);
}

} /* namespace */

