/**
 * @file ImageGetter.h
 * @brief Image getter header file
 * 
 */

#ifndef IMAGEGETTER_H
#define IMAGEGETTER_H

#include <cv_bridge/cv_bridge.h>
#include <mutex>
#include <opencv2/core/core.hpp>
#include <ros/ros.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/image_encodings.h>

using namespace std;

/**
 * @struct tCameraInfo
 * @brief Camera intrinsic parameter struct
 * 
 */
typedef struct tCameraInfo {
	int nWidth; /**< @brief Width of the camera*/
	int nHeight; /**< @brief Height of the camera*/
	float fFX; /**< @brief intrinsic fx*/
	float fFY; /**< @brief intrinsic fy*/
	float fCX; /**< @brief intrinsic cx*/
	float fCY; /**< @brief intrinsic cy*/
	float fK1; /**< @brief distortion k1*/
	float fK2; /**< @brief distortion k2*/
	float fK3; /**< @brief distortion k3*/
	float fP1; /**< @brief distortion p1*/
	float fP2; /**< @brief distortion p2*/
} tCameraInfo;

/**
 * @brief The class for Image Getter
 * 
 */
class ImageGetter
{
public:
	//Constructor
	ImageGetter();
	~ImageGetter();

	// Ros Function
	void SubImgFromRGBD(string strColorTopic, string strDepthTopic, string strColorInfo, string strDepthInfo);
	void ImageCb(const sensor_msgs::ImageConstPtr &msg);
	void DepthCb(const sensor_msgs::ImageConstPtr &msg);
	void ImageCalibCb(const sensor_msgs::CameraInfo &msg);
	void DepthCalibCb(const sensor_msgs::CameraInfo &msg);

	// Ros
	ros::NodeHandle nh_;
	ros::Subscriber image_sub_;
	ros::Subscriber depth_sub_;
	ros::Subscriber ImageCalibCb_sub_;
	ros::Subscriber DepthCalibCb_sub_;

	// Getter
	bool GetColorInfo(tCameraInfo * info_t);
	bool GetDepthInfo(tCameraInfo * info_t);
	void GetColorImg(cv::Mat &img);
	void GetDepthImg(cv::Mat &img);
	void GetColorImgAndClear(cv::Mat &img);
	void GetDepthImgAndClear(cv::Mat &img);

	//parameter
	int image_width, image_height;
	float image_fx, image_fy;
	float image_cx, image_cy;
	float image_k1, image_k2, image_k3;
	float image_p1, image_p2;

	int depth_width, depth_height;
	float depth_fx, depth_fy;
	float depth_cx, depth_cy;
	float depth_k1, depth_k2, depth_k3;
	float depth_p1, depth_p2;

	cv::Mat image_to_pub;
	cv::Mat image_d_to_pub;

private:
	cv::Mat img_from_camera;
	bool image_sub_flag = false;

	cv::Mat depth_from_camera;
	bool depth_sub_flag = false;

	bool bImageIntrinsicSet = false;

	bool bDepthIntrinsicSet = false;

private:
	std::mutex image_lock;
	std::mutex depth_lock;
	std::mutex image_intrinsic_lock;
	std::mutex depth_intrinsic_lock;
};

#endif // IMAGEGETTER_H