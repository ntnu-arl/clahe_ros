#ifndef CLAHE_ROS
#define CLAHE_ROS

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core.hpp>
#include <vector>
#include <sensor_msgs/Image.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <std_msgs/Header.h>

class ClaheRos
{
public:
	ClaheRos(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private);
	void imageCb(const sensor_msgs::ImageConstPtr &msg);

private:
	double clahe_clip_limit_;
	double clahe_grid_size_;

	// nodes
	ros::NodeHandle nh_;
	ros::NodeHandle nh_private_;
	image_transport::ImageTransport it_;

	// publishers
	image_transport::Publisher image_pub_;
	image_transport::Subscriber image_sub_;
};

#endif // CLAHE_ROS

