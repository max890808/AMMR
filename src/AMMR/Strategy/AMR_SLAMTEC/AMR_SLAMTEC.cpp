/**
 * @file AMR_SLAMTEC.cpp
 * @brief This example shows you how to control aiRobots-AMR with SLAMTEC Mapper.
 * @brief The state of MoveBase is not tracked. We only subscribe to twist message.
 * 
 */

#include "AMR_SLAMTEC.h"

AMR_SLAMTEC::AMR_SLAMTEC(bool *pTerminate)
{
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMR);
    mpRobot->mpControlInterface->SubControlFromTwist("/cmd_vel");

    mpbTerminate = pTerminate;
    StartStrategy();
}

void AMR_SLAMTEC::StartStrategy()
{
    while(!*mpbTerminate){

    }
    std::cout << "[AMR_SLAMTEC] Strategy End." << std::endl;
}

AMR_SLAMTEC::~AMR_SLAMTEC()
{

}
