// AGVRobotStrategy.cpp
#include "AGVRobotStrategy.h"

AGVRobotStrategy::AGVRobotStrategy() {}

AGVRobotStrategy::~AGVRobotStrategy() {}

void AGVRobotStrategy::configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) {
    pAMR = new AMR({0, 1, 2, 3}, {"Mx106", "Mx106", "Mx106", "Mx106"}, 0.075, 0.260, 1, -1, eAMMRType::Type_AGV);
    pControlInterface->SetAMR(pAMR);
    pManipulator = nullptr;
}