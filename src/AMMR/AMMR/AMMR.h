/**
 * @file AMMR.h
 * @brief AMMR header file
 * 
 */

#ifndef AMMR_H
#define AMMR_H

#include "AMR/AMR.h"
#include "Manipulator/Manipulator.h"
#include "ControlInterface/ControlInterface.h"
#include "VisionInterface/VisionInterface.h"
#include "LiDARInterface/LiDARInterface.h"

// /**
//  * @brief AMMR Type
//  * 
//  */
// enum class eAMMRType{
//     Type_AMMR=0, /**<  aiRobots_AMMR*/
//     Type_AMR=1, /**<  aiRobots_AMR*/
// 	Type_AGV=2/**<	aiRobots_AGV*/
// };

/**
 * @brief The class for AMR and AMMR
 * 
 */
class AMMR
{
public:
	static AMMR *GetAMMR();
	static AMMR *GetAMMR(eAMMRType nAMMRType);

	~AMMR();
	void StartROSLoop();
	void Reconnect();
	eAMMRType GetType();
	
	AMR *mpAMR;
	Manipulator *mpManipulator;
	ControlInterface *mpControlInterface;
	VisionInterface *mpVisionInterface;
	LiDARInterface *mpLiDARInterface1;
	LiDARInterface *mpLiDARInterface2;

private:
	AMMR(eAMMRType nAMMRType);

	eAMMRType mnAMMRType;

	// ROS
	void ROSLoop();
	std::thread mtROSLoop;
	bool mbROSLoopStarted;
	bool mbStopRequest;

private:
	static AMMR *inst_;

};

#endif // AMMR_H