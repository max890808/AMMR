// AMMRRobotStrategy.h
#ifndef AMMR_ROBOT_STRATEGY_H
#define AMMR_ROBOT_STRATEGY_H

#include "RobotStrategy/RobotStrategy.h"

class AMMRRobotStrategy : public RobotStrategy {
public:
    AMMRRobotStrategy();
    ~AMMRRobotStrategy();

    void configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) override;
};

#endif // AMMR_ROBOT_STRATEGY_H
