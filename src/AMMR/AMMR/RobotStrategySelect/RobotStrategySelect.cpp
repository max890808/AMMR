// RobotStrategySelect.cpp
#include "RobotStrategySelect.h"
#include "AGVRobotStrategy/AGVRobotStrategy.h"
#include "AMMRRobotStrategy/AMMRRobotStrategy.h"
#include "AMRRobotStrategy/AMRRobotStrategy.h"

RobotStrategySelect::RobotStrategySelect(eAMMRType nAMMRType) : strategy(nullptr)
{
    // 選擇策略
    switch (nAMMRType) {
        case eAMMRType::Type_AMMR:
            strategy = new AMMRRobotStrategy();
            break;
        case eAMMRType::Type_AMR:
            strategy = new AMRRobotStrategy();
            break;
        case eAMMRType::Type_AGV:
            strategy = new AGVRobotStrategy();
            break;
    }
}

RobotStrategySelect::~RobotStrategySelect()
{
    delete strategy;
}

void RobotStrategySelect::configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator)
{
    if (strategy) {
        strategy->configureRobot(pAMR, pControlInterface, pManipulator);
    }
}