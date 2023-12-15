/**
 * @file MoveBaseClient.h
 * @brief Movebase client header file
 * 
 */

#ifndef MOVE_BASE_INTERFACE_H
#define MOVE_BASE_INTERFACE_H

#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <mutex>
#include <ros/ros.h>
#include <thread>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ActionMoveBaseClient;

/**
 * @brief The class for MoveBaseClient
 * @note For more information about MoveBase Actionlib client, please refer to <a href="https://wiki.ros.org/actionlib/DetailedDescription">official document</a> 
 * 
 */
class MoveBaseClient
{

public:
    MoveBaseClient(bool bSpinThread, int nUpdateRate, std::string strMapFrame, bool bWaitForServer);
    ~MoveBaseClient();

    void StartSubSimpleGoal(std::string strFromTopic);
    bool isSuccess();
    bool isIdle();
    std::string GetState();
    void SendGoal(double dx, double dy, double dz, double dQx, double dQy, double dQz, double dQw);
    void CancelGoal();

private:
    void SimpleGoal_Callback(geometry_msgs::PoseStamped msg);
    void Update_state();

private:
    ros::NodeHandle n_; 
    ros::Subscriber sub_SimpleGoal_;
    ActionMoveBaseClient *mpMBClient;
    geometry_msgs::PoseStamped mPoseMSG;

    std::string mstrMapFrame;

    // Lock
    std::mutex mlockData;

    std::thread mUpdateThread;
    std::string mstrState;
    bool mbPending;
    std::string mstrFromTopic;
    bool mbSpinThread;
    int mnUpdateRate;
};



#endif // MOVE_BASE_INTERFACE_H