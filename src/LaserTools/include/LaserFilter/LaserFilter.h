#ifndef LASER_FILTER_H
#define LASER_FILTER_H

#include <mutex>
#include <string>

#include <geometry_msgs/QuaternionStamped.h>
#include <nav_msgs/OccupancyGrid.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

class LaserFilter
{
public:
    LaserFilter();
    void IMU_Callback(const geometry_msgs::QuaternionStampedConstPtr &msg);
    void Scan_Callback(sensor_msgs::LaserScan msg);

private:
    // Lock
    std::mutex mlockIMU;
    std::mutex mlockScan;

    // Data
    bool mbFilterIMU;
    bool mbGetIMU, mbGetScan;
    double mdX,mdY,mdZ,mdW;
    double mdYaw, mdPitch, mdRoll;

private:
    ros::NodeHandle n_; 
    ros::Publisher pub_Scan_;
    ros::Subscriber sub_IMU_;
    ros::Subscriber sub_Scan_;

    std::string mstrSrcIMUTopic;
    std::string mstrSrcScanTopic;
    std::string mstrDstScanTopic;
    std::string mstrDstScanFrame;
    float mfMinAngle;
    float mfMaxAngle;
    float mfMaxRange;

    float mfStablePitchRad;
    float mfToleratePitchRad;
    float mfStableRollRad;
    float mfTolerateRollRad;

};

#endif // LASER_FILTER_H