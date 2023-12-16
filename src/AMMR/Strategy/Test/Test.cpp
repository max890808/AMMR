#include "Test.h"

Test::Test(bool *pTerminate)
{
    // Start Setup something
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMMR);

    // End Setup something
    
    mpbTerminate = pTerminate;
    StartStrategy();
}

void Test::StartStrategy()
{
    Eigen::Matrix<float, 4, 4> transform_matrix;
    transform_matrix = mpRobot->mpManipulator->GetTransformMatrix(0.5, 0.3, 0.1,0.1);
    std :: cout << transform_matrix << std::endl;
    bool AMRExecuteState;
    AMRExecuteState = mpRobot->mpAMR->GetExecuteState();
    std :: cout << AMRExecuteState << std::endl;
}

Test::~Test()
{

}