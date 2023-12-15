
#include "MoveBaseClient.h"

/**
 * @brief Construct a new Move Base Client instance
 * 
 * @param bSpinThread If true, then the @ref MoveBaseClient starts its own spin thread.
 * @param nUpdateRate The state update rate of the @ref MoveBaseClient
 * @param strMapFrame The name of the global frame when path planning
 * @param bWaitForServer If true, then the function blocks until the movebase server is connected
 * 
 */
MoveBaseClient::MoveBaseClient(bool bSpinThread, int nUpdateRate, std::string strMapFrame, bool bWaitForServer) : 
                                mbSpinThread(bSpinThread), mnUpdateRate(nUpdateRate), mbPending(false), mstrMapFrame(strMapFrame)
{
    mpMBClient = new ActionMoveBaseClient("move_base", mbSpinThread);
    if(bWaitForServer)
    {
        while(!mpMBClient->waitForServer(ros::Duration(5.0))){
            ROS_INFO("Waiting for the move_base action server to come up");
        }
    }

    mstrState = std::string("");
    mUpdateThread = std::thread(&MoveBaseClient::Update_state, this);
}

/**
 * @brief Destroy the Move Base Clien instance
 * 
 */
MoveBaseClient::~MoveBaseClient()
{
    mUpdateThread.join();
    delete mpMBClient;
}

/**
 * @brief The function that set the subscribe topic of goal.
 * 
 * @param strFromTopic 
 */
void MoveBaseClient::StartSubSimpleGoal(std::string strFromTopic)
{
    mstrFromTopic = strFromTopic;
    sub_SimpleGoal_  = n_.subscribe(mstrFromTopic, 1, &MoveBaseClient::SimpleGoal_Callback, this);
}

/**
 * @brief The function that check if the goal is successed.
 * 
 * @return true if the state is "SUCCEEDED"
 * @return false 
 */
bool MoveBaseClient::isSuccess()
{
    std::unique_lock<std::mutex> lock(mlockData);
    return mstrState=="SUCCEEDED";
}


/**
 * @brief The function that check if the movebase server is Idle.
 * 
 * @return true if the state is not "PENDING" and "ACTIVE"
 * @return false if the server is either PENDING or ACTIVE
 */
bool MoveBaseClient::isIdle()
{
    std::unique_lock<std::mutex> lock(mlockData);
    return mstrState !="PENDING" && mstrState !="ACTIVE";
}

/**
 * @brief The function that return the state of the movebase server
 * 
 * @return std::string The state of the movebase client
 */
std::string MoveBaseClient::GetState()
{
    std::unique_lock<std::mutex> lock(mlockData);
    return mstrState;
}

/**
 * @brief The function that set the goal
 * 
 * @param dx The x value (meter)
 * @param dy The y value (meter)
 * @param dz The z value (meter)
 * @param dQx The x value of quaternion
 * @param dQy The y value of quaternion
 * @param dQz The z value of quaternion
 * @param dQw The w value of quaternion
 */
void MoveBaseClient::SendGoal(double dx, double dy, double dz, double dQx, double dQy, double dQz, double dQw)
{
    std::cout << "[MoveBaseClient] Waiting for setting new goal" << std::endl;
    std::unique_lock<std::mutex> lock(mlockData);
    mPoseMSG.header.frame_id = mstrMapFrame;
    mPoseMSG.pose.position.x = dx;
    mPoseMSG.pose.position.y = dy;
    mPoseMSG.pose.position.z = dz;
    mPoseMSG.pose.orientation.x = dQx;
    mPoseMSG.pose.orientation.y = dQy;
    mPoseMSG.pose.orientation.z = dQz;
    mPoseMSG.pose.orientation.w = dQw;
    mbPending = true;
}

/**
 * @brief The function that cancel the goal
 * 
 */
void MoveBaseClient::CancelGoal()
{
    if(mpMBClient->isServerConnected() && mpMBClient->getState() !=  actionlib::SimpleClientGoalState::LOST)
    {
        mpMBClient->cancelAllGoals();
    }
}

/**
 * @brief The callback function of the goal topic 
 * 
 * @param msg The ROS geometry_msgs::PoseStamped message
 */
void MoveBaseClient::SimpleGoal_Callback(geometry_msgs::PoseStamped msg)
{
    std::unique_lock<std::mutex> lock(mlockData);
    mPoseMSG = msg;
    mbPending = true;
}

/**
 * @brief The function that periodically get the state and send goal to the movebase server.
 * @note The update rate can be configured in @ref MoveBaseClient()
 * 
 */
void MoveBaseClient::Update_state()
{
    ros::Rate loop_rate(mnUpdateRate);
    while (ros::ok())
    {
        if(mpMBClient->isServerConnected())
        {
            std::unique_lock<std::mutex> lock(mlockData);
            // If new goal unprocessed, cancel previous goal and set new
            if(mbPending)
            {
                if(mpMBClient->getState().isDone())
                {
                    mbPending = false;
                    move_base_msgs::MoveBaseGoal goal;
                    goal.target_pose=mPoseMSG;
                    goal.target_pose.header.stamp = ros::Time::now();
                    std::cout << "[MoveBaseClient] Set New Goal" << std::endl;
                    mpMBClient->sendGoal(goal);
                }
                else
                {
                    std::cout << "[MoveBaseClient] Cancel Goal" << std::endl;
                    mpMBClient->cancelAllGoals();
                }
            }
            // If processed, update state
            mstrState = mpMBClient->getState().toString();
        }
        else
        {
            mpMBClient->waitForServer(ros::Duration(5.0));
            // ROS_INFO("Waiting for the move_base action server to come up");
        }
        loop_rate.sleep();
    }
}
