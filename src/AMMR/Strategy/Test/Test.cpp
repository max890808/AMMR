#include "Test.h"

Test::Test(bool *pTerminate)
{
    // End Setup something
    
    mpbTerminate = pTerminate;
    StartStrategy1();
    StartStrategy2();
    StartStrategy3();
}

Eigen::Matrix<float, 4, 4> Test::StartStrategy1()
{
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMMR);
    Eigen::Matrix<float, 4, 4> transform_matrix;
    transform_matrix = mpRobot->mpManipulator->GetTransformMatrix(0.0, 0.0, 0.0, 0.0);
    std :: cout << transform_matrix << std::endl;
    return transform_matrix;
}

bool Test::StartStrategy2()
{
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMR);
    bool AMRExecuteState;
    AMRExecuteState = mpRobot->mpAMR->GetExecuteState();
    std :: cout << AMRExecuteState << std::endl;
    return AMRExecuteState;
}

bool Test::StartStrategy3()
{
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AGV);
    bool AMRExecuteState;
    AMRExecuteState = mpRobot->mpAMR->GetExecuteState();
    std :: cout << AMRExecuteState << std::endl;
    return AMRExecuteState;
}

Test::~Test()
{

}