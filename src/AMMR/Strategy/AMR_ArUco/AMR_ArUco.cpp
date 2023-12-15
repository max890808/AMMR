#include "AMR_ArUco.h"
#include <opencv2/highgui/highgui.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include<Eigen/Dense>

AMR_ArUco::AMR_ArUco(bool *pTerminate)
{
    mpAMMR = AMMR::GetAMMR(eAMMRType::Type_AMR);
    mpAMMR->mpControlInterface->SubControlFromTwist("/cmd_vel");
    mpAMMR->mpVisionInterface->StartSubFromRGBD("/camera/color/image_raw", "/camera/aligned_depth_to_color/image_raw", 
                                        "/camera/color/camera_info", "/camera/aligned_depth_to_color/camera_info");
    mpAMMR->mpLiDARInterface1->StartSubFromLiDAR("/slamware_ros_sdk_server_node/scan");

    mpbTerminate = pTerminate;
    StartStrategy2();
}

void AMR_ArUco::StartStrategy1()
{
    typedef std::vector<std::vector<cv::Point2f>> ArUco_CORNERS;
    typedef std::vector<int> ArUco_IDS;

    ArUcoProcessing *pArUcoProcessing = mpAMMR->mpVisionInterface->mpArUcoProcessing;

    while(!*mpbTerminate)
    {
        tCameraInfo tColorInfo;
        if(mpAMMR->mpVisionInterface->mpImageGetter->GetColorInfo(&tColorInfo))
        {
            pArUcoProcessing->SetIntrinsic(tColorInfo.fFX, 
                                            tColorInfo.fFY,
                                            tColorInfo.fCX,
                                            tColorInfo.fCY);
            std::cout << "Get Intrinsic Parameters" << std::endl;
            break;
        }
    }

    // Set Aruco Parameters
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(10);
    parameters->adaptiveThreshWinSizeStep = 2;
    parameters->adaptiveThreshConstant = 5;

    // GAMMA Correction
    cv::Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( int i = 0; i < 256; ++i)
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, 0.67) * 255.0);

    // TF
    mpTFListener = new tf2_ros::TransformListener(mTFBuffer);
    geometry_msgs::TransformStamped tfStamp;

    while(!*mpbTerminate){
        
        // Get the Pose of the Robot
        cv::Mat Twc = cv::Mat::eye(4,4,CV_64F);
        try
        {
            tfStamp = mTFBuffer.lookupTransform("map", "camera", ros::Time(0));
            tf2::Quaternion q(tfStamp.transform.rotation.x, tfStamp.transform.rotation.y, tfStamp.transform.rotation.z, tfStamp.transform.rotation.w);
            tf2::Matrix3x3 m(q);

            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    Twc.at<double>(i,j)=double(m[i][j]);
                }
            }
            Twc.at<double>(0,3) = double(tfStamp.transform.translation.x);
            Twc.at<double>(1,3) = double(tfStamp.transform.translation.y);
            Twc.at<double>(2,3) = double(tfStamp.transform.translation.z);
        }
        catch (tf2::TransformException ex)
        {
            ROS_WARN("[SLAM Interface] %s",ex.what());
        }

        // Detect the Mark
        cv::Mat cvColor;
        mpAMMR->mpVisionInterface->mpImageGetter->GetColorImgAndClear(cvColor);
        if(!cvColor.empty())
        {
            ArUco_CORNERS corners;
            ArUco_IDS ids;

            // ArUco Detection using Library 10, which is DICT_6X6_250
            cv::Mat DetectMat;
            cvtColor(cvColor,DetectMat,CV_BGR2GRAY);

            LUT(DetectMat, lookUpTable, DetectMat);

            pArUcoProcessing->DetectMarkers(DetectMat, dictionary, corners, ids, parameters);

            // // Draw ArUco Detection Result
            pArUcoProcessing->DrawDetectedMarkers(cvColor, corners);


            if(ids.size() == 1){
                cv::Mat Tcm;
                pArUcoProcessing->EstimatePoseOneMarker(corners, 0, 0.06, Tcm);

                // Generate the Quat+Trans vector of Pose of Marker in the World
                cv::Mat Twm = Twc * Tcm;

                Eigen::Matrix<double,3,3> eM;
                eM << Twm.at<double>(0,0), Twm.at<double>(0,1), Twm.at<double>(0,2),
                        Twm.at<double>(1,0), Twm.at<double>(1,1), Twm.at<double>(1,2),
                        Twm.at<double>(2,0), Twm.at<double>(2,1), Twm.at<double>(2,2);
                Eigen::Quaterniond q(eM);
                std::vector<float> v(4);
                v[0] = q.x();
                v[1] = q.y();
                v[2] = q.z();
                v[3] = q.w();
                
                std::cout << "ID:" << ids[0] << ", " << v[0] << "," 
                                                    << v[1] << "," 
                                                    << v[2] << "," 
                                                    << v[3] << ","
                                                    << Twm.at<double>(0,3) << "," 
                                                    << Twm.at<double>(1,3) << "," 
                                                    <<Twm.at<double>(2,3) <<std::endl;
            }

            cv::imshow("AMR_ArUco", cvColor);
        }
    }

    cv::destroyWindow("AMR_ArUco");
    std::cout << "[AMR_ArUco] Strategy End." << std::endl;
}

void AMR_ArUco::StartStrategy2()
{
    typedef std::vector<std::vector<cv::Point2f>> ArUco_CORNERS;
    typedef std::vector<int> ArUco_IDS;

    ArUcoProcessing *pArUcoProcessing = mpAMMR->mpVisionInterface->mpArUcoProcessing;

    while(!*mpbTerminate)
    {
        tCameraInfo tColorInfo;
        if(mpAMMR->mpVisionInterface->mpImageGetter->GetColorInfo(&tColorInfo))
        {
            pArUcoProcessing->SetIntrinsic(tColorInfo.fFX, 
                                            tColorInfo.fFY,
                                            tColorInfo.fCX,
                                            tColorInfo.fCY);
            std::cout << "Get Intrinsic Parameters" << std::endl;
            break;
        }
    }

    // Set Aruco Parameters
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(10);
    parameters->adaptiveThreshWinSizeStep = 2;
    parameters->adaptiveThreshConstant = 5;

    // GAMMA Correction
    cv::Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( int i = 0; i < 256; ++i)
        p[i] = cv::saturate_cast<uchar>(pow(i / 255.0, 0.67) * 255.0);

    // Ground Truth Landmark
    std::vector<std::vector<double>> Landmark
    {
        {0.705175,-0.00727287,0.00012002,0.708996,-0.0108679,0.791089,-0.0330544},
        {0.527627,0.499221,0.480431,0.491501,-0.0822753,4.43114,-0.0313092},
        {0.492255,-0.482768,-0.510182,0.514134,3.9099,4.09195,-0.0337317},
        {0.000617157,0.709462,0.704721,-0.00559213,3.19364,0.835509,-0.0363517},
        {0.69531,0.0137606,0.0181249,0.718349,3.96363,2.48663,-0.02981},
        {0.484501,-0.504446,-0.504598,0.506136,5.18035,1.70438,-0.0342821}
    };

    // TF
    mpTFListener = new tf2_ros::TransformListener(mTFBuffer);
    geometry_msgs::TransformStamped tfStamp;

    while(!*mpbTerminate){
        
        // Get the Pose of the Robot
        cv::Mat Tcw = cv::Mat::eye(4,4,CV_64F);
        try
        {
            tfStamp = mTFBuffer.lookupTransform("camera", "map", ros::Time(0));
            tf2::Quaternion q(tfStamp.transform.rotation.x, tfStamp.transform.rotation.y, tfStamp.transform.rotation.z, tfStamp.transform.rotation.w);
            tf2::Matrix3x3 m(q);

            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    Tcw.at<double>(i,j)=double(m[i][j]);
                }
            }
            Tcw.at<double>(0,3) = double(tfStamp.transform.translation.x);
            Tcw.at<double>(1,3) = double(tfStamp.transform.translation.y);
            Tcw.at<double>(2,3) = double(tfStamp.transform.translation.z);
        }
        catch (tf2::TransformException ex)
        {
            ROS_WARN("[SLAM Interface] %s",ex.what());
        }

        // Detect the Mark
        cv::Mat cvColor;
        mpAMMR->mpVisionInterface->mpImageGetter->GetColorImgAndClear(cvColor);
        if(!cvColor.empty())
        {
            ArUco_CORNERS corners;
            ArUco_IDS ids;

            // ArUco Detection using Library 10, which is DICT_6X6_250
            cv::Mat DetectMat;
            cvtColor(cvColor,DetectMat,CV_BGR2GRAY);

            LUT(DetectMat, lookUpTable, DetectMat);

            pArUcoProcessing->DetectMarkers(DetectMat, dictionary, corners, ids, parameters);

            // // Draw ArUco Detection Result
            pArUcoProcessing->DrawDetectedMarkers(cvColor, corners);


            if(ids.size() == 1){
                cv::Mat Tcm;
                pArUcoProcessing->EstimatePoseOneMarker(corners, 0, 0.06, Tcm);
                int tID = ids[0];

                tf2::Quaternion q(Landmark[tID][0], Landmark[tID][1], Landmark[tID][2], Landmark[tID][3]);
                tf2::Matrix3x3 m(q);

                cv::Mat Twm = cv::Mat::eye(4,4,CV_64F);
                
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        Twm.at<double>(i,j)=m[i][j];
                    }
                }
                Twm.at<double>(0,3) = Landmark[tID][4];
                Twm.at<double>(1,3) = Landmark[tID][5];
                Twm.at<double>(2,3) = Landmark[tID][6];

                cv::Mat Tmc;
                cv::invert(Tcm, Tmc); 
                cv::Mat estTwc = Twm * Tmc;

                std::cout << "ID:" << ids[0] << ",Est: " << estTwc.at<double>(0,3) << "," 
                                                        << estTwc.at<double>(1,3) << "," 
                                                        <<estTwc.at<double>(2,3) <<std::endl;
                
                cv::Mat gtTwc = cv::Mat::eye(4,4,CV_64F);
                cv::invert(Tcw, gtTwc);                             
                std::cout << "ID:" << ids[0] << ",Gt : " << gtTwc.at<double>(0,3) << "," 
                                                        << gtTwc.at<double>(1,3) << "," 
                                                        <<gtTwc.at<double>(2,3) <<std::endl;
            }

            cv::imshow("AMR_ArUco", cvColor);
        }
    }

    cv::destroyWindow("AMR_ArUco");
    std::cout << "[AMR_ArUco] Strategy End." << std::endl;
}

AMR_ArUco::~AMR_ArUco()
{
    delete mpTFListener;
}
