/**
 * @file ArUcoProcessing.h
 * @brief ArUco Processing header file
 * 
 */

#ifndef ARUCOPROCESSING_H
#define ARUCOPROCESSING_H

#include <opencv2/aruco.hpp>

/**
 * @brief The class for ArUco Processing
 * 
 */
class ArUcoProcessing
{
    public:
        typedef cv::Ptr<cv::aruco::Dictionary> ArUco_DICT; /**< ArUco dictionary */
        typedef std::vector<std::vector<cv::Point2f>> ArUco_CORNERS; /**< Detected Corners */
        typedef std::vector<int> ArUco_IDS; /**< Detected IDs */
        typedef cv::Ptr<cv::aruco::DetectorParameters> ArUco_PARAM; /**< Custom Parameters */

        ArUcoProcessing();
        void GetIntrinsic(cv::Mat &K);
        void SetIntrinsic(float fx, float fy, float cx, float cy);
        void DetectMarkers(const cv::Mat &color_image, const int dictionary_id, ArUco_CORNERS &corners, ArUco_IDS &ids);
        void DetectMarkers(const cv::Mat &color_image, const ArUco_DICT &dictionary, ArUco_CORNERS &corners, ArUco_IDS &ids);
        void DetectMarkers(const cv::Mat &color_image, const ArUco_DICT &dictionary, ArUco_CORNERS &corners, ArUco_IDS &ids, ArUco_PARAM parameters);
        void DrawDetectedMarkers(cv::Mat &color_image, const ArUco_CORNERS &corners, const ArUco_IDS &ids={});
        void EstimatePoseOneMarker(const ArUco_CORNERS &corners, const int idx, const float markersize, cv::Mat &CameraPose);
    
    public:
        cv::Mat mK; // Intrinsic parameter. Only needed if 3D position calculation is required
};

#endif // ARUCOPROCESSING_H
