
#include <iostream>
#include "ArUcoProcessing.h"

#include <opencv2/calib3d.hpp>

ArUcoProcessing::ArUcoProcessing(){}

/**
 * @brief The function that get the intrinsic parameter matrix
 * 
 * @param K Output intrinsic matrix
 */
void ArUcoProcessing::GetIntrinsic(cv::Mat &K)
{
    if(mK.empty())
    {
        std::cout << "Intrinsic Matrix empty. Maybe you forget to call ArUcoProcessing::SetIntrinsic()?" << std::endl;
        return;
    }
    else
    {
        K = mK.clone();
    }
}

/**
 * @brief The function that set the intrinsic parameters
 * 
 * @param fx fx of intrinsic parameters
 * @param fy fy of intrinsic parameters
 * @param cx cx of intrinsic parameters
 * @param cy cy of intrinsic parameters
 */
void ArUcoProcessing::SetIntrinsic(float fx, float fy, float cx, float cy)
{
    mK = cv::Mat::eye(3,3,CV_32F);
    mK.at<float>(0,0) = fx;
    mK.at<float>(1,1) = fy;
    mK.at<float>(0,2) = cx;
    mK.at<float>(1,2) = cy;
}

/**
 * @brief The function that detect the ArUco using specific dictionary ID.
 * 
 * @param color_image Source image
 * @param dictionary_id The ID of the ArUco dictionary
 * @param corners Output detected corners, see also @ref ArUco_CORNERS
 * @param ids Output detected IDs, see also @ref ArUco_IDS
 */
void ArUcoProcessing::DetectMarkers(const cv::Mat &color_image, const int dictionary_id, ArUco_CORNERS &corners, ArUco_IDS &ids)
{
    ArUco_DICT dictionary = cv::aruco::getPredefinedDictionary(dictionary_id);
    DetectMarkers(color_image, dictionary, corners, ids);
}

/**
 * @brief The function that detect the ArUco using specific dictionary and default parameters.
 * 
 * @param color_image Source image
 * @param dictionary ArUco dictionary, see also @ref ArUco_DICT
 * @param corners Output detected corners, see also @ref ArUco_CORNERS
 * @param ids Output detected IDs, see also @ref ArUco_IDS
 */
void ArUcoProcessing::DetectMarkers(const cv::Mat &color_image, const ArUco_DICT &dictionary, ArUco_CORNERS &corners, ArUco_IDS &ids)
{
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    parameters->adaptiveThreshWinSizeStep = 2;
    parameters->adaptiveThreshConstant = 5;
    cv::aruco::detectMarkers(color_image, dictionary, corners, ids, parameters);
}

/**
 * @brief The function that detect the ArUco using specific dictionary and custom parameters.
 * 
 * @param color_image Source image
 * @param dictionary ArUco dictionary, see also @ref ArUco_DICT
 * @param corners Output detected corners, see also @ref ArUco_CORNERS
 * @param ids Output detected IDs, see also @ref ArUco_IDS
 * @param parameters The custom parameters, see also @ref ArUco_PARAM
 */
void ArUcoProcessing::DetectMarkers(const cv::Mat &color_image, const ArUco_DICT &dictionary, ArUco_CORNERS &corners, ArUco_IDS &ids, ArUco_PARAM parameters)
{
    cv::aruco::detectMarkers(color_image, dictionary, corners, ids, parameters);
}

/**
 * @brief Draw detected result on image
 * 
 * @param color_image Source and Output image.
 * @param corners Detected Corners, see also @ref ArUco_CORNERS
 * @param ids Detected IDs, see also @ref ArUco_IDS
 */
void ArUcoProcessing::DrawDetectedMarkers(cv::Mat &color_image, const ArUco_CORNERS &corners, const ArUco_IDS &ids)
{
    cv::aruco::drawDetectedMarkers(color_image, corners, ids);
}

/**
 * @brief 
 * 
 * @param corners Detected Corners, see also @ref ArUco_CORNERS
 * @param idx Target Marker
 * @param markersize The real size of the ArUco marker (meter)
 * @param CameraPose Output Camera Position relative to Marker. Origin is at center of the target marker
 * @note CameraPose is double type
 */
void ArUcoProcessing::EstimatePoseOneMarker(const ArUco_CORNERS &corners, const int idx, const float markersize, cv::Mat &CameraPose)
{
    if(mK.empty())
    {
        std::cout << "[ArUco] Error: Intrinsic Matrix empty. Maybe you forget to call ArUcoProcessing::SetIntrinsic()?" << std::endl;
        return;   
    }
    else if(idx >= corners.size())
    {
        std::cout << "[ArUco] Error: Index out of range" << std::endl;
        return;     
    }
    else
    {

        float half_len = markersize/2;
        std::vector<cv::Point3f> Marker3D = {   cv::Point3f(-1*half_len,  1*half_len, 0),
                                                cv::Point3f( 1*half_len,  1*half_len, 0),
                                                cv::Point3f( 1*half_len, -1*half_len, 0),
                                                cv::Point3f(-1*half_len, -1*half_len, 0)    };
        cv::Mat r, t, R;
        cv::solvePnP(Marker3D, corners[idx], mK, cv::Mat(), r, t, false);
        cv::Rodrigues(r, R);

        CameraPose =  cv::Mat::eye(4,4,CV_64F); // Data is in double format
        CameraPose = (cv::Mat_<double>(4,4)<<
                        R.at<double>(0, 0), R.at<double>(0, 1), R.at<double>(0, 2), t.at<double>(0, 0),
                        R.at<double>(1, 0), R.at<double>(1, 1), R.at<double>(1, 2), t.at<double>(1, 0),
                        R.at<double>(2, 0), R.at<double>(2, 1), R.at<double>(2, 2), t.at<double>(2, 0),
                        0, 0, 0, 1
        );
    }
}
