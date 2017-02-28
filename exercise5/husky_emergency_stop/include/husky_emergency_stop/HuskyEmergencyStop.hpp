#pragma once

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>

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
};

} /* namespace */
