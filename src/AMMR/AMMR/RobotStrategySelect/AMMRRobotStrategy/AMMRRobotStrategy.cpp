// AMMRRobotStrategy.cpp
#include "AMMRRobotStrategy.h"

AMMRRobotStrategy::AMMRRobotStrategy() {}

AMMRRobotStrategy::~AMMRRobotStrategy() {}

void AMMRRobotStrategy::configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) {
    pAMR = new AMR({0, 1}, {"Pro200", "Pro200"}, 0.075, 0.475, 1, -1, eAMMRType::Type_AMMR);
    pControlInterface->SetAMR(pAMR);
    pManipulator = Manipulator::GetManipulator();
}