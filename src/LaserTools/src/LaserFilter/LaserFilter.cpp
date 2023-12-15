
#include "LaserFilter/LaserFilter.h"
#include <math.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

/**
 * @brief Construct a new LaserFilter::LaserFilter object
 *
 */
LaserFilter::LaserFilter() : mbGetIMU(false), mbGetScan(false), mbFilterIMU(true), mdX(0), mdY(0), mdZ(0), mdW(0), mdYaw(0), mdPitch(0), mdRoll(0)
{
    ros::NodeHandle private_nh_("~");

    private_nh_.param("FromScanTopic", mstrSrcScanTopic, std::string("/slamware_ros_sdk_server_node/scan"));
    private_nh_.param("FromImuTopic", mstrSrcIMUTopic, std::string("/Quaternion"));
    private_nh_.param("ToScanTopic", mstrDstScanTopic, std::string("/RPLidar_scan"));
    private_nh_.param("ToScanFrame", mstrDstScanFrame, std::string("RPLidar_laser"));
    private_nh_.param("MinAngle", mfMinAngle, float(-M_PI));
    private_nh_.param("MaxAngle", mfMaxAngle, float(M_PI));
    private_nh_.param("MaxRange", mfMaxRange, -1.0f);
    private_nh_.param("UseImuFilter", mbFilterIMU, true);
    private_nh_.param("StablePitchRad", mfStablePitchRad, 0.0f);
    private_nh_.param("ToleratePitchRad", mfToleratePitchRad, float(M_PI/12));
    private_nh_.param("StableRollRad", mfStableRollRad, 0.0f);
    private_nh_.param("TolerateRollRad", mfTolerateRollRad, float(M_PI/12));


    ROS_INFO("[LaserFilter] Original Scan Topic: %s", mstrSrcScanTopic.c_str());
    ROS_INFO("[LaserFilter] Original IMU  Topic: %s", mstrSrcIMUTopic.c_str());
    ROS_INFO("[LaserFilter] Publish  Scan Topic: %s", mstrDstScanTopic.c_str());
    ROS_INFO("[LaserFilter] Publish  Scan Frame: %s", mstrDstScanFrame.c_str());
    ROS_INFO("[LaserFilter] Minimum Accept Angle: %f", mfMinAngle);
    ROS_INFO("[LaserFilter] Maximum Accept Angle: %f", mfMaxAngle);

    pub_Scan_ = n_.advertise<sensor_msgs::LaserScan>(mstrDstScanTopic, 1);
    sub_Scan_ = n_.subscribe(mstrSrcScanTopic, 1, &LaserFilter::Scan_Callback, this);

    if(mbFilterIMU)
    {
        sub_IMU_ = n_.subscribe(mstrSrcIMUTopic, 1, &LaserFilter::IMU_Callback, this);
    }
    
}

void LaserFilter::Scan_Callback(sensor_msgs::LaserScan msg)
{
    bool bPubScan = false;
    if(mbFilterIMU)
    {
        std::unique_lock<std::mutex> lock(mlockIMU);
        float fRollDiff = float(mdRoll) - mfStableRollRad;
        float fPitchDiff = float(mdPitch) - mfStablePitchRad;
        bool bRollReject = fRollDiff > mfTolerateRollRad || fRollDiff < -mfTolerateRollRad;
        bool bPitchReject = fPitchDiff > mfToleratePitchRad || fPitchDiff < -mfToleratePitchRad;
        if(!bRollReject && !bPitchReject)
        {
            bPubScan = true;
        }
    }
    else
    {
        bPubScan = true;
    }

    std::unique_lock<std::mutex> lock(mlockIMU);
    mbGetScan = true;

    if(bPubScan)
    {
        msg.header.frame_id = mstrDstScanFrame;

        float fAngle_End, fAngle_Start, fRange_Max;
        std::vector<float> vfRanges;

        for (int i = 0; i < msg.ranges.size(); ++i)
        {
            float angle = msg.angle_min + i * msg.angle_increment;
            if(angle < mfMaxAngle && angle > mfMinAngle)
            {
                // Update Angle Start/End
                float target_range = -1;
                if(mfMaxRange == -1)
                {
                    target_range = msg.ranges[i];
                }
                else if(mfMaxRange != -1 && msg.ranges[i] <= mfMaxRange)
                {
                    target_range = msg.ranges[i];
                }
                else
                {
                    target_range = -1;
                }

                if(vfRanges.size()==0)
                {
                    fAngle_Start = angle;
                    fRange_Max = target_range;
                }
                fAngle_End = angle;

                // Update Ranges
                vfRanges.push_back(target_range);
                
                // Update Range Max
                if(msg.ranges[i] > fRange_Max)
                    fRange_Max = msg.ranges[i];
            }
        }

        // If increment is negative, reverse the order
        if(msg.angle_increment < 0)
        {
            msg.angle_min = fAngle_End;
            msg.angle_max = fAngle_Start;
            msg.angle_increment = -1 * msg.angle_increment;
            msg.range_min = 0;
            msg.range_max = fRange_Max;

            std::reverse(vfRanges.begin(),vfRanges.end());
            msg.ranges = vfRanges;
        }
        else
        {
            msg.angle_min = fAngle_Start;
            msg.angle_max = fAngle_End;
            msg.range_min = 0;
            msg.range_max = fRange_Max;
            msg.ranges = vfRanges;
        }
        pub_Scan_.publish(msg);
    }
}

void LaserFilter::IMU_Callback(const geometry_msgs::QuaternionStampedConstPtr &msg)
{
    std::unique_lock<std::mutex> lock(mlockIMU);

    mbGetIMU = true;
    mdX = msg->quaternion.x;
    mdY = msg->quaternion.y;
    mdZ = msg->quaternion.z;
    mdW = msg->quaternion.w;

    tf2::Quaternion q(mdX, mdY, mdZ, mdW);
    tf2::Matrix3x3 m(q);
    m.getRPY(mdRoll, mdPitch, mdYaw);
    // std::cout << mdRoll << " " << mdPitch << std::endl;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "LaserFilter");

    LaserFilter *pLaserFilter = new LaserFilter();

    ros::spin();

    return 0;
}
