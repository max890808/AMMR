/**
 * @file LiDARGetter.h
 * @brief LiDAR Getter header file
 * 
 */

#ifndef LIDARGETTER_H
#define LIDARGETTER_H

#include <Eigen/Geometry>
#include <mutex>
#include <opencv2/core.hpp>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>

using namespace std;

/**
 * @struct tLiDARInfo
 * @brief LiDAR parameter struct
 * 
 */
typedef struct tLiDARInfo {
	float fRangeMin; /**< @brief Minimum range*/
	float fRangeMax; /**< @brief Maximum range*/
	float fAngleStart; /**< @brief Laser start angle*/
	float fAngleEnd; /**< @brief Laser begin angle*/
	float fAngleIncrement; /**< @brief Laser angle increment*/
	int nValidScan; /**< @brief Number of valid laser points*/
	int nNumScan; /**< @brief Number of all laser points*/
} tLiDARInfo;

/**
 * @brief The class for LiDAR Getter
 * 
 */
class LiDARGetter
{
public:
	//Constructor
	LiDARGetter();
	~LiDARGetter();

	//Ros Function
	void SubScanFromLiDAR(string strScanTopic);
	void ScanCb(const sensor_msgs::LaserScanConstPtr &msgScan);

	// Ros
	ros::NodeHandle nh_;
	ros::Subscriber scan_sub_;

	// Getter
	bool GetInfo(tLiDARInfo * info_t);
	bool GetScan(std::vector<Eigen::Vector2f> &vScanPoints);
	cv::Mat GetScanImage(bool bZaxisUp, bool bDrawLines, int nPlotMaxRange, int nImageSize);

private:
    std::vector<Eigen::Vector2f> mveScanPoints;

	float mfRangeMin, mfRangeMax, mfAngleStart, mfAngleEnd, mfAngleIncrement;
	int mnValidScan, mnNumScan;

    bool scan_sub_flag = false;

	cv::Mat GetScanLineImage(bool bZaxisUp, int nPlotMaxRange, int nImageSize);
    cv::Mat GetScanRawImage(bool bZaxisUp, int nPlotMaxRange, int nImageSize);
	void DrawGrid(int nPlotMaxRange, cv::Mat &mImage, const cv::Point2f &pCenter);
	void DrawAxis(bool bYaxisUp, cv::Mat &mImage, const cv::Point2f &pCenter);

private:
	std::mutex scan_lock;
};

#endif // LIDARGETTER_H