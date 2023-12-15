#include "ImageGetter.h"

#include <iostream>

/**
 * @brief Construct a new ImageGetter instance
 * 
 */
ImageGetter::ImageGetter()
{

}

/**
 * @brief Destroy the ImageGetter instance
 * 
 */
ImageGetter::~ImageGetter()
{

}

/**
 * @brief The function that set the subscribe topic of RGB-D camera.
 * 
 * @param strColorTopic The ROS topic name of color image.
 * @param strDepthTopic The ROS topic name of depth image.
 * @param strColorInfo The ROS topic name of intrinsic parameter of RGB camera.
 * @param strDepthInfo The ROS topic name of intrinsic parameter of Depth camera.
 */
void ImageGetter::SubImgFromRGBD(string strColorTopic, string strDepthTopic, string strColorInfo, string strDepthInfo)
{
	if(!strColorTopic.empty())
	{
		this->image_sub_ = this->nh_.subscribe(strColorTopic, 1, &ImageGetter::ImageCb, this);
	}

	if(!strDepthTopic.empty())
	{
		this->depth_sub_ = this->nh_.subscribe(strDepthTopic, 1, &ImageGetter::DepthCb, this);
	}

	if(!strColorInfo.empty())
	{
		this->ImageCalibCb_sub_ = this->nh_.subscribe(strColorInfo, 1, &ImageGetter::ImageCalibCb, this);
	}

	if(!strDepthInfo.empty())
	{
		this->DepthCalibCb_sub_ = this->nh_.subscribe(strDepthInfo, 1, &ImageGetter::DepthCalibCb, this);
	}
}

/**
 * @brief Color image callback, Convert Color image to BGR888 format
 * 
 * @param msg The ROS sensor_msgs::Image message
 */
void ImageGetter::ImageCb(const sensor_msgs::ImageConstPtr &msg)
{
	try
	{
		std::unique_lock<std::mutex> lock(image_lock);
		cv_bridge::CvImageConstPtr cv_ptr;
		cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
		this->img_from_camera = cv_ptr->image.clone();
		this->image_sub_flag = true;
	}
	catch (cv_bridge::Exception &e)
	{
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	}
}

/**
 * @brief Depth image callback, Convert Depth image to 16 bit uint 1 channel format
 * 
 * @param msg The ROS sensor_msgs::Image message
 */
void ImageGetter::DepthCb(const sensor_msgs::ImageConstPtr &msg)
{
	try
	{
		std::unique_lock<std::mutex> lock(depth_lock);
		cv_bridge::CvImageConstPtr cv_ptr;
		cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::TYPE_16UC1);
		this->depth_from_camera = cv_ptr->image.clone();
		this->depth_sub_flag = true;
	}
	catch (cv_bridge::Exception &e)
	{
		ROS_ERROR("cv_bridge exception: %s", e.what());
		return;
	}
}

/**
 * @brief The callback function that get the camera intrinsic parameters.
 * 
 * @param msg The ROS sensor_msgs::CameraInfo message
 */
void ImageGetter::ImageCalibCb(const sensor_msgs::CameraInfo &msg)
{
	try
	{
		{
			std::unique_lock<std::mutex> lock(image_intrinsic_lock);
			this->image_width = msg.width;
			this->image_height = msg.height;
			this->image_fx = msg.K[0];
			this->image_fy = msg.K[4];
			this->image_cx = msg.K[2];
			this->image_cy = msg.K[5];
			this->image_k1 = msg.D[0];
			this->image_k2 = msg.D[1];
			this->image_p1 = msg.D[2];
			this->image_p2 = msg.D[3];
			this->image_k3 = msg.D[4];

			this->bImageIntrinsicSet = true;
		}
	}
	catch (const std::exception &e)
	{
		ROS_ERROR("Camera Calibration Parameter exception: %s", e.what());
		return;
	}
}

/**
 * @brief The callback function that get the depth intrinsic parameters.
 * 
 * @param msg The ROS sensor_msgs::CameraInfo message
 */
void ImageGetter::DepthCalibCb(const sensor_msgs::CameraInfo &msg)
{
	try
	{
		{
			std::unique_lock<std::mutex> lock(depth_intrinsic_lock);
			this->depth_width = msg.width;
			this->depth_height = msg.height;
			this->depth_fx = msg.K[0];
			this->depth_fy = msg.K[4];
			this->depth_cx = msg.K[2];
			this->depth_cy = msg.K[5];
			this->depth_k1 = msg.D[0];
			this->depth_k2 = msg.D[1];
			this->depth_p1 = msg.D[2];
			this->depth_p2 = msg.D[3];
			this->depth_k3 = msg.D[4];

			this->bDepthIntrinsicSet = true;
		}
	}
	catch (const std::exception &e)
	{
		ROS_ERROR("Depth Calibration Parameter exception: %s", e.what());
		return;
	}
}

/**
 * @brief The function that get the recorded camera intrinsic parameters.
 * 
 * @param info_t Output camera intrinsic parameters, see also @ref tCameraInfo
 * @return true if the intrinsic parameters are received
 * @return false if the intrinsic parameters are not received
 */
bool ImageGetter::GetColorInfo(tCameraInfo * info_t)
{
	std::unique_lock<std::mutex> lock(image_lock);
	if (bImageIntrinsicSet)
	{
		info_t->nWidth = image_width;
		info_t->nHeight = image_height;
		info_t->fFX = image_fx;
		info_t->fFY = image_fy;
		info_t->fCX = image_cx;
		info_t->fCY = image_cy;
		info_t->fK1 = image_k1;
		info_t->fK2 = image_k2;
		info_t->fK3 = image_k3;
		info_t->fP1 = image_p1;
		info_t->fP2 = image_p2;
	}
	return bImageIntrinsicSet;
}

/**
 * @brief The function that get the recorded depth intrinsic parameters.
 * 
 * @param info_t Output camera intrinsic parameters, see also @ref tCameraInfo
 * @return true if the intrinsic parameters are received
 * @return false if the intrinsic parameters are not received
 */
bool ImageGetter::GetDepthInfo(tCameraInfo * info_t)
{
	std::unique_lock<std::mutex> lock(depth_lock);
	if (bDepthIntrinsicSet)
	{
		info_t->nWidth = depth_width;
		info_t->nHeight = depth_height;
		info_t->fFX = depth_fx;
		info_t->fFY = depth_fy;
		info_t->fCX = depth_cx;
		info_t->fCY = depth_cy;
		info_t->fK1 = depth_k1;
		info_t->fK2 = depth_k2;
		info_t->fK3 = depth_k3;
		info_t->fP1 = depth_p1;
		info_t->fP2 = depth_p2;
	}
	return bDepthIntrinsicSet;
}

/**
 * @brief The function that get the recorded color image.
 * @note If no image is received, then the output image will be empty.
 * @note Last image is returned if no new image is available.
 * @note see also @ref GetColorImgAndClear()
 * 
 * @param img Output image
 */
void ImageGetter::GetColorImg(cv::Mat &img)
{
	std::unique_lock<std::mutex> lock(image_lock);
	if (image_sub_flag)
	{
		img = this->img_from_camera.clone();
	}
	else
	{
		img = cv::Mat();
	}
}

/**
 * @brief The function that get the recorded color image.
 * @note If no image is received, then the output image will be empty.
 * @note After calling this function, an internal flag is set and next image is available only if a new image is received.
 * @note see also @ref GetColorImg()
 * 
 * @param img Output image
 */
void ImageGetter::GetColorImgAndClear(cv::Mat &img)
{
	std::unique_lock<std::mutex> lock(image_lock);
	if (image_sub_flag)
	{
		img = this->img_from_camera.clone();
	}
	else
	{
		img = cv::Mat();
	}
	image_sub_flag = false;
}

/**
 * @brief The function that get the recorded depth image.
 * @note If no image is received, then the output image will be empty.
 * @note Last image is returned if no new image is available.
 * @note see also @ref GetDepthImgAndClear()
 * 
 * @param img Output image
 */
void ImageGetter::GetDepthImg(cv::Mat &img)
{
	std::unique_lock<std::mutex> lock(depth_lock);
	if (depth_sub_flag)
	{
		img = this->depth_from_camera.clone();
	}
	else
	{
		img = cv::Mat();
	}
}

/**
 * @brief The function that get the recorded depth image.
 * @note If no image is received, then the output image will be empty.
 * @note After calling this function, an internal flag is set and next image is available only if a new image is received.
 * @note see also @ref GetDepthImg()
 * 
 * @param img Output image
 */
void ImageGetter::GetDepthImgAndClear(cv::Mat &img)
{
	std::unique_lock<std::mutex> lock(depth_lock);
	if (depth_sub_flag)
	{
		img = this->depth_from_camera.clone();
	}
	else
	{
		img = cv::Mat();
	}
	depth_sub_flag = false;
}
