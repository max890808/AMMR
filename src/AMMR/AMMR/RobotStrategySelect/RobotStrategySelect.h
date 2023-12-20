// RobotStrategySelect.h
#ifndef ROBOT_STRATEGY_SELECT_H
#define ROBOT_STRATEGY_SELECT_H

#include "RobotStrategy/RobotStrategy.h"

class RobotStrategySelect
{
    public:
        RobotStrategySelect(eAMMRType nAMMRType);
        ~RobotStrategySelect();

        virtual void configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator);
    
    private:
        RobotStrategy* strategy;
};

#endif //ROBOT_STRATEGY_SELECT_H