// AMRRobotStrategy.cpp
#include "AMRRobotStrategy.h"

AMRRobotStrategy::AMRRobotStrategy() {}

AMRRobotStrategy::~AMRRobotStrategy() {}

void AMRRobotStrategy::configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) {
    pAMR = new AMR({1, 2}, {"Mx106", "Mx106"}, 0.075, 0.335, -1, 1, eAMMRType::Type_AMR);
    pControlInterface->SetAMR(pAMR);
    pManipulator = nullptr;
}