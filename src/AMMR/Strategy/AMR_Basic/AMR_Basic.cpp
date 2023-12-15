#include "AMR_Basic.h"

AMR_Basic::AMR_Basic(bool *pTerminate)
{
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMR);
    mpRobot->mpControlInterface->SetMoveBaseClient(true, 10, "map", false, "aiRobots_AMR/action_goal"); // In order to track the control from rviz
    mpRobot->mpControlInterface->SubControlFromTwist("/cmd_vel");
    mpRobot->mpVisionInterface->StartSubFromRGBD("/camera/color/image_raw", "/camera/aligned_depth_to_color/image_raw", 
                                        "/camera/color/camera_info", "/camera/aligned_depth_to_color/camera_info");
    mpRobot->mpLiDARInterface1->StartSubFromLiDAR("/slamware_ros_sdk_server_node/scan");

    mpbTerminate = pTerminate;
    StartStrategy();
}

void AMR_Basic::StartStrategy()
{
    std::string strMoveBaseState = "";

    // This is an example for setting the goal
    if(mpRobot->mpControlInterface->mpMBClient->isIdle())
    {
        mpRobot->mpControlInterface->mpMBClient->SendGoal(3.20140576363, 4.59099626541, 0, 0, 0, 0.171033384118, 0.985265234095);
    }

    while(!*mpbTerminate){
        std::string current_state = mpRobot->mpControlInterface->mpMBClient->GetState();
        if(strMoveBaseState != current_state)
        {
            strMoveBaseState = current_state;
            std::cout << "[AMR_Basic] Current State: " << strMoveBaseState << std::endl;
        }
    }
    std::cout << "[AMR_Basic] Strategy End." << std::endl;
}

AMR_Basic::~AMR_Basic()
{

}
