#include "LiDARGetter.h"

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

/**
 * @brief Construct a new LiDARGetter instance
 * 
 */
LiDARGetter::LiDARGetter()
{

}

/**
 * @brief Destroy the LiDARGetter instance
 * 
 */
LiDARGetter::~LiDARGetter()
{

}

/**
 * @brief The function that set the subscribe topic of laser scan.
 * 
 * @param strScanTopic The ROS topic name of laserscan.
 */
void LiDARGetter::SubScanFromLiDAR(string strScanTopic)
{
	if(!strScanTopic.empty())
	{
		this->scan_sub_ = this->nh_.subscribe(strScanTopic, 1, &LiDARGetter::ScanCb, this);
	}
}

/**
 * @brief Laser scan callback
 * 
 * @param msg The ROS sensor_msgs::LaserScan message
 */
void LiDARGetter::ScanCb(const sensor_msgs::LaserScanConstPtr &msgScan)
{
    unique_lock<mutex> lock(scan_lock);
    mveScanPoints.clear();

    mfRangeMin = msgScan->range_min;
    mfRangeMax = msgScan->range_max;
    mfAngleIncrement = msgScan->angle_increment;
    mfAngleStart = msgScan->angle_min;
    mfAngleEnd = msgScan->angle_max;
    mnNumScan = msgScan->ranges.size();

    // Convert to Vector of Eigen 
    for (int i = 0; i < mnNumScan; ++i)
    {
        float angle = mfAngleStart + i * mfAngleIncrement;
        if (msgScan->ranges[i] > mfRangeMin && msgScan->ranges[i] < mfRangeMax)
        {
            Eigen::Vector2f scan_point(msgScan->ranges[i] * cos(angle), msgScan->ranges[i] * sin(angle));
            mveScanPoints.emplace_back(scan_point.x(), scan_point.y());
        }
    }

	mnValidScan = mveScanPoints.size();

    if(!scan_sub_flag)
        scan_sub_flag = true;
}

/**
 * @brief The function that get the recorded laser scan info.
 * 
 * @param info_t  Output laser scan info, see also @ref tLiDARInfo
 * @return true if the laser scan is received
 * @return false if the laser scan is not received
 */
bool LiDARGetter::GetInfo(tLiDARInfo * info_t)
{
    unique_lock<mutex> lock(scan_lock);
    if(scan_sub_flag)
    {
        info_t->fRangeMin = mfRangeMin;
        info_t->fRangeMax = mfRangeMax;
        info_t->fAngleStart = mfAngleStart;
        info_t->fAngleEnd = mfAngleEnd;
        info_t->fAngleIncrement = mfAngleIncrement;
        info_t->nValidScan = mnValidScan;
        info_t->nNumScan = mnNumScan;
    }

    return scan_sub_flag;
}

/**
 * @brief The function that get the recorded laser scan data.
 * 
 * @param vScanPoints Output laser scan data
 * @return true if the laser scan is received
 * @return false if the laser scan is not received
 */
bool LiDARGetter::GetScan(std::vector<Eigen::Vector2f> &vScanPoints)
{
    std::unique_lock<std::mutex> lock(scan_lock);
    if(scan_sub_flag)
    {
        vScanPoints = mveScanPoints;
    }
    return scan_sub_flag;
}

/**
 * @brief The function that draw the laser scan data on the iamge and return.
 * 
 * @param bZaxisUp True if the Z axis is upward
 * @param bDrawLines True if to draw lines on the image, the distance between lines is 1 meter.
 * @param nPlotMaxRange The maximum range displayed by the drawn image
 * @param nImageSize The image size
 * @return cv::Mat Output image
 */
cv::Mat LiDARGetter::GetScanImage(bool bZaxisUp, bool bDrawLines, int nPlotMaxRange, int nImageSize)
{
    if(bDrawLines)
    {
        return GetScanLineImage(bZaxisUp, nPlotMaxRange, nImageSize);
    }
    else
    {
        return GetScanRawImage(bZaxisUp, nPlotMaxRange, nImageSize);
    }
}

/**
 * @brief The function that draw the laser scan data without grid on the iamge and return.
 * 
 * @param bYaxisUp True if the Z axis is upward
 * @param nPlotMaxRange The maximum range displayed by the drawn image
 * @param nImageSize The image size
 * @return cv::Mat Output image
 */
cv::Mat LiDARGetter::GetScanRawImage(bool bYaxisUp, int nPlotMaxRange, int nImageSize)
{
    unique_lock<mutex> lock(scan_lock);
    if(scan_sub_flag)
    {
        cv::Mat scan_image = cv::Mat::ones(cv::Size(nImageSize,nImageSize),CV_8UC3);
        scan_image = cv::Scalar(50,50,50);
        cv::Point2f center(scan_image.cols/2, scan_image.rows/2);

        DrawGrid(nPlotMaxRange, scan_image, center);

        for(Eigen::Vector2f vScanPoint : mveScanPoints)
        {
            float px = vScanPoint.x() / nPlotMaxRange * nImageSize / 2;
            float py = vScanPoint.y() / nPlotMaxRange * nImageSize / 2;
            if(bYaxisUp)
                py = -1 * py;

            cv::Point2f ScanPosition = center + cv::Point2f(px, py);
            cv::circle(scan_image, ScanPosition, 1, cv::Scalar(255,255,255), 1);
        }

        DrawAxis(bYaxisUp, scan_image, center);

        return scan_image;
    }
    return cv::Mat();

}

/**
 * @brief The function that draw the laser scan data with grid on the iamge and return.
 * 
 * @param bYaxisUp True if the Z axis is upward
 * @param nPlotMaxRange The maximum range displayed by the drawn image
 * @param nImageSize The image size
 * @return cv::Mat Output image
 */
cv::Mat LiDARGetter::GetScanLineImage(bool bYaxisUp, int nPlotMaxRange, int nImageSize)
{
    unique_lock<mutex> lock(scan_lock);
    if(scan_sub_flag)
    {
        cv::Mat scan_image = cv::Mat::ones(cv::Size(nImageSize,nImageSize),CV_8UC3);
        scan_image = cv::Scalar(50,50,50);
        cv::Point2f center(scan_image.cols/2, scan_image.rows/2);

        DrawGrid(nPlotMaxRange, scan_image, center);

        for(Eigen::Vector2f vScanPoint : mveScanPoints)
        {
            float px = vScanPoint.x() / nPlotMaxRange * nImageSize / 2;
            float py = vScanPoint.y() / nPlotMaxRange * nImageSize / 2;
            if(bYaxisUp)
                py = -1 * py;

            cv::Point2f ScanPosition = center + cv::Point2f(px, py);
            cv::line(scan_image, center, ScanPosition, cv::Scalar(255,255,255), 1);
        }

        DrawAxis(bYaxisUp, scan_image, center);
           
        return scan_image;
    }
	return cv::Mat();
}

/**
 * @brief The function that draw the grid on the image
 * 
 * @param nPlotMaxRange The maximum range displayed by the drawn image
 * @param mImage Source+Output image
 * @param pCenter The position of the origin
 */
void LiDARGetter::DrawGrid(int nPlotMaxRange, cv::Mat &mImage, const cv::Point2f &pCenter)
{
    int nImageSize = mImage.cols;
    int nPixelPerMeter = nImageSize / (2 * nPlotMaxRange);
    cv::Point2f pOffset(nPlotMaxRange*nPixelPerMeter, nPlotMaxRange*nPixelPerMeter);
    cv::Point2f pStart(pCenter - pOffset);

    for(int meter=0; meter < 2 * nPlotMaxRange; meter++)
    {
        float start_x = pStart.x + meter * nPixelPerMeter;
        float start_y = pStart.y + meter * nPixelPerMeter;
        cv::line(mImage, cv::Point2f(start_x, 0), cv::Point2f(start_x, nImageSize), cv::Scalar(25,25,25), 4);
        cv::line(mImage, cv::Point2f(0, start_y), cv::Point2f(nImageSize, start_y), cv::Scalar(25,25,25), 4);
    }
}

/**
 * @brief The function that draw the axis on the image
 * 
 * @param bYaxisUp True if the Z axis is upward
 * @param mImage Source+Output image
 * @param pCenter The position of the origin
 */
void LiDARGetter::DrawAxis(bool bYaxisUp, cv::Mat &mImage, const cv::Point2f &pCenter)
{
    int nArrawLength = 50;
    cv::arrowedLine(mImage, pCenter, pCenter+cv::Point2f(nArrawLength,0), cv::Scalar(0,0,255), 2, 8, 0, 0.2);
    if(bYaxisUp)
    {
        cv::arrowedLine(mImage, pCenter, pCenter+cv::Point2f(0,-nArrawLength), cv::Scalar(0,255,0), 2, 8, 0, 0.2);
        cv::circle(mImage, pCenter, nArrawLength/5, cv::Scalar(255,0,0), -1);
    }
    else
    {
        cv::arrowedLine(mImage, pCenter, pCenter+cv::Point2f(0,nArrawLength), cv::Scalar(0,255,0), 2, 8, 0, 0.2);
        cv::drawMarker(mImage, pCenter, cv::Scalar(255,0,0), cv::MARKER_TILTED_CROSS, nArrawLength/2, 2);
    }
}
