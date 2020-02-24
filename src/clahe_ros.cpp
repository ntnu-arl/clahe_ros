#include "clahe_ros/clahe_ros.h"

ClaheRos::ClaheRos(const ros::NodeHandle &nh, const ros::NodeHandle &nh_private)
	: nh_(nh), nh_private_(nh_private), it_(nh_private)
{
	//Get Param
	nh_private_.param<double>("clahe_clip_limit", clahe_clip_limit_, 2);
	nh_private_.param<double>("clahe_grid_size", clahe_grid_size_, 6);

	//Setup Publishers and Subscribers
	image_pub_ = it_.advertise("/equalized_image", 5);
	image_sub_ = it_.subscribe("/image", 5, &ClaheRos::imageCb, this);
}

void ClaheRos::imageCb(const sensor_msgs::ImageConstPtr &msg)
{
	std_msgs::Header header = msg->header;
	cv::Mat bgr_image = cv_bridge::toCvShare(msg, "bgr8")->image;
	cv::Mat lab_image, dst;
	cv::cvtColor(bgr_image, lab_image, CV_BGR2Lab);

	// Extract the L channel
	std::vector<cv::Mat> lab_planes(3);
	cv::split(lab_image, lab_planes); // now we have the L image in lab_planes[0]

	// apply the CLAHE algorithm to the L channel
	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
	clahe->setClipLimit(clahe_clip_limit_);
	clahe->setTilesGridSize(cv::Size(clahe_grid_size_, clahe_grid_size_));
	clahe->apply(lab_planes[0], dst);

	// Merge the the color planes back into an Lab image
	dst.copyTo(lab_planes[0]);
	cv::merge(lab_planes, lab_image);

	// convert back to RGB
	cv::Mat image_clahe;
	cv::cvtColor(lab_image, image_clahe, CV_Lab2BGR);
	image_pub_.publish(cv_bridge::CvImage(header, "bgr8", image_clahe).toImageMsg());
}