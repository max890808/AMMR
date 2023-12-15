#include "AMMR_Basic.h"

AMMR_Basic::AMMR_Basic(bool *pTerminate)
{
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMMR);
    mpRobot->mpControlInterface->SetMoveBaseClient(true, 10, "map", false, "aiRobots_AMR/action_goal"); // In order to track the control from rviz
    mpRobot->mpControlInterface->SubControlFromTwist("/cmd_vel");
    mpRobot->mpControlInterface->SubPosFromTF("map", "base");
    mpRobot->mpVisionInterface->StartSubFromRGBD("/camera/color/image_raw", "/camera/aligned_depth_to_color/image_raw", 
                                        "/camera/color/camera_info", "/camera/aligned_depth_to_color/camera_info");
    mpRobot->mpLiDARInterface1->StartSubFromLiDAR("/scan_front");
    mpRobot->mpLiDARInterface2->StartSubFromLiDAR("/scan_rear");

    mpbTerminate = pTerminate;
    StartStrategy();
}

void AMMR_Basic::StartStrategy()
{
    // if(mpRobot->mpControlInterface->mpMBClient->isIdle())
    // {
    //     mpRobot->mpControlInterface->SendGoalQuat(0, 0, 0, 0, 0, 0, 1);
    // }

    std::string strMoveBaseState = "";
    while(!*mpbTerminate){
        std::string current_state = mpRobot->mpControlInterface->mpMBClient->GetState();
        if(strMoveBaseState != current_state)
        {
            strMoveBaseState = current_state;
            std::cout << "[AMMR_Basic] Current State: " << strMoveBaseState << std::endl;
        }
    }
    std::cout << "[AMMR_Basic] Strategy End." << std::endl;
}

AMMR_Basic::~AMMR_Basic()
{

}
