/**
 * @file ControlInterface.h
 * @brief Control Interface header file
 * 
 */

#ifndef CONTROL_INTERFACE_H
#define CONTROL_INTERFACE_H

// ROS
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/Twist.h>

// Standard
#include <thread>

// Others
#include "AMR/AMR.h"
#include "ControlInterface.h"
#include "MoveBaseClient/MoveBaseClient.h"

/**
 * @brief The class for Control interface
 * 
 */
class ControlInterface
{
public:
    ControlInterface();
    ~ControlInterface();

    void SetAMR(AMR *pAMR);
    void SetMoveBaseClient(bool bSpinThread, int nUpdateRate, std::string strMapFrame, bool bWaitForServer, std::string strFromTopic="");
    void SendGoalZYX(double dx, double dy, double dz, double dOz, double dOy, double dOx);
    void SendGoalQuat(double dx, double dy, double dz, double dQx, double dQy, double dQz, double dQw);
    void SubControlFromTwist(string strCmdVelTopic);
    void SubPosFromTF(string parent, string child);
    bool GetPosQuatFromTF(double &dx, double &dy, double &dz, double &dQx, double &dQy, double &dQz, double &dQw);
    bool GetPosZYXFromTF(double &dx, double &dy, double &dz, double &dOz, double &dOy, double &dOx);
    string GetMovingState();

    MoveBaseClient* mpMBClient;
    float linear_x;
    float angular_z;

private:
    AMR *mpAMR;

    void CmdVelCb(const geometry_msgs::TwistConstPtr &msg);

	// Ros
	ros::NodeHandle nh_;
	ros::Subscriber vel_sub_;

    // MoveBase
    bool mbUseMoveBase;

    // Pos
    bool mbSubTF;
    string mstrParent, mstrChild;
    tf2_ros::Buffer mTFBuffer;
    tf2_ros::TransformListener *mpTFListener;
};

#endif // CONTROL_INTERFACE_H