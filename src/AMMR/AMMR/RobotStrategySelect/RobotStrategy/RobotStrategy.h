// RobotStrategy.h
#ifndef ROBOT_STRATEGY_H
#define ROBOT_STRATEGY_H

#include "ControlInterface/ControlInterface.h"
#include "Manipulator/Manipulator.h"
#include "AMR/AMR.h"

class RobotStrategy 
{
    public:
        RobotStrategy();
        virtual ~RobotStrategy();
        virtual void configureRobot(AMR* pAMR, ControlInterface* pControlInterface, Manipulator* pManipulator) = 0;
};

#endif // ROBOT_STRATEGY_H