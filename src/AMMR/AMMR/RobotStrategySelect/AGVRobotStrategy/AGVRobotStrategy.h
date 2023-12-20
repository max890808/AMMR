// AGVRobotStrategy.h
#ifndef AGV_ROBOT_STRATEGY_H
#define AGV_ROBOT_STRATEGY_H

#include "RobotStrategy/RobotStrategy.h"

class AGVRobotStrategy : public RobotStrategy {
public:
    AGVRobotStrategy();
    ~AGVRobotStrategy();

    void configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) override;
};

#endif // AGV_ROBOT_STRATEGY_H