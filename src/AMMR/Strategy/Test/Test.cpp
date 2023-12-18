#include "Test.h"

Test::Test(bool *pTerminate)
{
    // Start Setup something
    mpRobot = AMMR::GetAMMR(eAMMRType::Type_AMMR);

    // End Setup something
    
    mpbTerminate = pTerminate;
    StartStrategy();
}

Eigen::Matrix<float, 4, 4> Test::StartStrategy()
{
    Eigen::Matrix<float, 4, 4> transform_matrix;
    transform_matrix = mpRobot->mpManipulator->GetTransformMatrix(0.0, 0.0, 0.0, 0.0);
    std :: cout << transform_matrix << std::endl;
    return transform_matrix;
}

Test::~Test()
{

}