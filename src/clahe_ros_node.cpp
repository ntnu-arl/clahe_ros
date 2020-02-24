#include <ros/ros.h>
#include "clahe_ros/clahe_ros.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "clahe_ros_node");
	ros::NodeHandle nh;
	ros::NodeHandle private_nh("~");
	ClaheRos clahe_ros(nh, private_nh);
	ros::spin();
	return 0;
}