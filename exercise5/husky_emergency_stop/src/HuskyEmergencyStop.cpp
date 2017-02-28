#include "husky_emergency_stop/HuskyEmergencyStop.hpp"

// STD
#include <string>

namespace husky_emergency_stop {

HuskyEmergencyStop::HuskyEmergencyStop(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  ROS_INFO("Successfully launched node.");
}

HuskyEmergencyStop::~HuskyEmergencyStop()
{
}
} /* namespace */
