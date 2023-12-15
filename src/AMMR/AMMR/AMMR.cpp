#include "AMMR.h"

AMMR *AMMR::inst_ = nullptr;

/**
 * @brief The function that get the constructed AMMR
 * 
 * @return Pointer about AMMR
 */
AMMR *AMMR::GetAMMR()
{
    if (inst_ != nullptr)
    {
        return inst_;
    }
    else
    {
        std::cout << "[AMMR] AMMR not created, please provide parameters" << std::endl;
        return nullptr;
    }
}

/**
 * @brief The function that get the AMMR with given type
 * @note If the type is different from the already created type, then old one is disconnected and a new robot is created
 * @note If the type is same as the already created type, then the already created instance is returned.
 * 
 * @param nAMMRType The type of the robot, see also @ref eAMMRType
 * @return Pointer about AMMR
 */
AMMR *AMMR::GetAMMR(eAMMRType nAMMRType)
{
    if (inst_ == nullptr)
    {
        inst_ = new AMMR(nAMMRType);
    }
    else if (inst_->GetType() != nAMMRType)
    {
        std::cout << "[AMMR] Recreate different type of robot... type: " << int(nAMMRType) << std::endl;
        AMMR *tmp = inst_;
        inst_ = new AMMR(nAMMRType);
        delete tmp;
    }
    else
    {
        std::cout << "[AMMR] Robot already created, use previous instance... type: " << int(nAMMRType) << std::endl;
    }
    return inst_;
}

/**
 * @brief Construct a new AMMR instance with given type @ref eAMMRType
 * 
 * @param nAMMRType The type of the robot, see also @ref eAMMRType
 */
AMMR::AMMR(eAMMRType nAMMRType) : mnAMMRType(nAMMRType)
{
    mbROSLoopStarted = false;
    mbStopRequest = false;

    mpVisionInterface = new VisionInterface();
    mpLiDARInterface1 = new LiDARInterface();
    mpLiDARInterface2 = new LiDARInterface();
    mpControlInterface = new ControlInterface();

    switch(mnAMMRType)
    {
        case eAMMRType::Type_AMMR:
        {
            // Moving Platform Setting
            mpAMR = new AMR({0, 1}, {"Pro200", "Pro200"}, 0.075, 0.475, 1, -1, eAMMRType::Type_AMMR);
            mpControlInterface->SetAMR(mpAMR);

            // Manipulator Setting
            mpManipulator = Manipulator::GetManipulator();
            break;
        }
        case eAMMRType::Type_AMR:
        {
            // Moving Platform Setting
            mpAMR = new AMR({1, 2}, {"Mx106", "Mx106"}, 0.075, 0.335, -1, 1, eAMMRType::Type_AMR);
            mpControlInterface->SetAMR(mpAMR);

            mpManipulator = nullptr;
            break;
        }
        case eAMMRType::Type_AGV:
        {
            mpAMR = new AMR({0, 1, 2, 3}, {"Mx106", "Mx106", "Mx106", "Mx106"}, 0.075, 0.260, 1, -1, eAMMRType::Type_AGV);
            mpControlInterface->SetAMR(mpAMR);
            
            mpManipulator = nullptr;
            break;
        }
    }

    StartROSLoop();

    cout << "[AMMR] AMMR constructed" << endl;
    cout << "================================================================================" << endl;
}

/**
 * @brief The function that get the type of current created robot
 * 
 * @return The type of the robot, see also @ref eAMMRType
 */
eAMMRType AMMR::GetType()
{
    return mnAMMRType;
}

/**
 * @brief The function that start a ROS spin thread
 * 
 */
void AMMR::StartROSLoop()
{
    mbROSLoopStarted = true;
    mtROSLoop = std::thread(&AMMR::ROSLoop, this);
}

/**
 * @brief The function that keep spinning
 * 
 */
void AMMR::ROSLoop()
{
	while(ros::ok() && !mbStopRequest)
	{
		ros::spinOnce();
	}
}

/**
 * @brief Destroy the AMMR object
 * 
 */
AMMR::~AMMR()
{
    // Stop ROS thread
    mbStopRequest = true;
    mtROSLoop.join();

    // Delete Component
	delete mpAMR;
    delete mpVisionInterface;
    delete mpLiDARInterface1;
    delete mpLiDARInterface2;
}

/**
 * @brief The function that reconnect the @ref AMR and @ref Manipulator
 * 
 */
void AMMR::Reconnect()
{
    delete mpAMR;
    delete mpManipulator;
	MotorUnion::allport = {0, 1, 2, 3, 4, 5, 6};

    switch(mnAMMRType)
    {
        case eAMMRType::Type_AMMR:
        {
            mpAMR = new AMR({0, 1}, {"Pro200", "Pro200"}, 0.075, 0.475, 1, -1, eAMMRType::Type_AMMR);
            mpManipulator = Manipulator::GetManipulator();

            mpControlInterface->SetAMR(mpAMR);
            break;
        }
        case eAMMRType::Type_AMR:
        {
            mpAMR = new AMR({1, 2}, {"Mx106", "Mx106"}, 0.075, 0.335, -1, 1, eAMMRType::Type_AMR);

            mpControlInterface->SetAMR(mpAMR);
            break;
        }
        case eAMMRType::Type_AGV:
        {
            mpAMR = new AMR({0, 1, 2, 3}, {"Mx106", "Mx106", "Mx106", "Mx106"}, 0.075, 0.260, 1, -1, eAMMRType::Type_AGV);
            
            mpControlInterface->SetAMR(mpAMR);
            break;
        }
    }
}