// AMRRobotStrategy.h
#ifndef AMR_ROBOT_STRATEGY_H
#define AMR_ROBOT_STRATEGY_H

#include "RobotStrategy/RobotStrategy.h"

class AMRRobotStrategy : public RobotStrategy {
public:
    AMRRobotStrategy();
    ~AMRRobotStrategy();

    void configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) override;
};

#endif // AMR_ROBOT_STRATEGY_H