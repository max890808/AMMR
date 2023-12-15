#include "Test.h"

void　Test::Test(bool *pTerminate)
{
    // Start Setup something
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMR);
    // End Setup something
    
    mpbTerminate = pTerminate;
    StartStrategy();
}

void Demo::StartStrategy()
{
    while(!*mpbTerminate){
        // Do something
    }
}