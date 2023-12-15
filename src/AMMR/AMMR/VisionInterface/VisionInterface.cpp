#include "VisionInterface.h"
#include <iostream>

/**
 * @brief Construct a new Vision Interface instance
 * 
 */
VisionInterface::VisionInterface(void)
{	
	this->mpImageGetter = new ImageGetter();
    this->mpArUcoProcessing = new ArUcoProcessing();
	cout<<"\tClass constructed: VisionInterface"<<endl;
}

/**
 * @brief Destroy the Vision Interface instance
 * 
 */
VisionInterface::~VisionInterface(void)
{
	delete mpImageGetter;
    delete mpArUcoProcessing;
}

/**
 * @brief The function that set the subscribe topic of RGB-D camera.
 * 
 * @param strColorTopic The ROS topic name of color image.
 * @param strDepthTopic The ROS topic name of depth image.
 * @param strColorInfo The ROS topic name of intrinsic parameter of RGB camera.
 * @param strDepthInfo The ROS topic name of intrinsic parameter of Depth camera.
 */
void VisionInterface::StartSubFromRGBD(string strColorTopic, string strDepthTopic, string strColorInfo, string strDepthInfo)
{
	if(strColorTopic.empty() && strDepthTopic.empty() && strColorInfo.empty() && strDepthInfo.empty())
	{
		cout << "[VisionInterface] Please provide Topic name. -> StartSubFromCamera(Color, Depth, ColorCalib, DepthCalib)" << endl;
		return;
	}

	cout << "[VisionInterface] Start sub from Camera" << endl;
	cout << "[VisionInterface] Color Image Topic: " << strColorTopic << endl;
	cout << "[VisionInterface] Depth Image Topic: " << strDepthTopic << endl;
	cout << "[VisionInterface] Color Info  Topic: " << strColorInfo  << endl;
	cout << "[VisionInterface] Depth Info  Topic: " << strDepthInfo  << endl;

	mpImageGetter->SubImgFromRGBD(strColorTopic, strDepthTopic, strColorInfo, strDepthInfo);
	this->mbStart_sub_flag = true;
}
