#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_srvs/SetBool.h>

namespace husky_emergency_stop {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class HuskyEmergencyStop
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  HuskyEmergencyStop(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~HuskyEmergencyStop();

 private:
  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  ros::Subscriber subscriber_;

  ros::ServiceClient client_;

  void topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
};

} /* namespace */
