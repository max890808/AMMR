#include "LiDARInterface.h"
#include <iostream>

/**
 * @brief Construct a new LiDAR Interface instance
 * 
 */
LiDARInterface::LiDARInterface(void)
{	
	this->mpLiDARGetter = new LiDARGetter();
	cout<<"\tClass constructed: LiDAR"<<endl;
}

/**
 * @brief Destroy the LiDAR Interface instance
 * 
 */
LiDARInterface::~LiDARInterface(void)
{
	delete mpLiDARGetter;
}

/**
 * @brief The function that set the subscribe topic of laser scan data.
 * 
 * @param strScanTopic The ROS topic name of laser scan data.
 */
void LiDARInterface::StartSubFromLiDAR(string strScanTopic)
{
	if(strScanTopic.empty())
	{
		cout << "[LiDARInterface] Please provide Topic name. -> StartSubFromLiDAR(Scan)" << endl;
		return;
	}

	cout << "[LiDARInterface] Start sub from LiDAR" << endl;
	cout << "[LiDARInterface] Scan Topic: " << strScanTopic << endl;

	mpLiDARGetter->SubScanFromLiDAR(strScanTopic);
	this->mbStart_sub_flag = true;
}