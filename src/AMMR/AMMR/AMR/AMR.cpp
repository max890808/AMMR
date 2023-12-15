#include "AMR.h"

/**
 * @brief The function that Initializes instance for AMR
 * 
 * @param vcAMR_ID The ID of the motors, {Right motor ID, Left motor ID}
 * @param vstrAMR_Model The model type of the motors, {Right motor model, Left motor model}
 * @param fWheelRadius The radius of the wheel
 * @param fTrackWidth The track width of the robot
 * @param nLeftDir The direction of the left motor
 * @param nRightDIR The direction of the right motor
 */
AMR::AMR(const vector<unsigned char> &vcAMR_ID, const vector<string> &vstrAMR_Model, 
						float fWheelRadius, float fTrackWidth, int nLeftDir, int nRightDIR, eAMMRType type) : 
	MotorUnion(vcAMR_ID, vstrAMR_Model),
	mfWheelRadius(fWheelRadius), mfTrackWidth(fTrackWidth),
	type_(type),
	conveyor(3),
	conveyor_R(2)
{
	mnLeftDir = (nLeftDir>0)?1:-1;
	mnRightDir = (nRightDIR>0)?1:-1;

    mnLeftMotorIdx = 1;
    mnRightMotorIdx = 0;
	
	SetAllMotorsTorqueEnable(true);

    SetMotor_Operating_Mode(mnLeftMotorIdx, 1);
    SetMotor_Operating_Mode(mnRightMotorIdx, 1);

	// Need RPS/(RPMM/3600) to reach RPS valocity
    SetMotor_AccelRPMM(mnRightMotorIdx, 1500);
    SetMotor_AccelRPMM(mnLeftMotorIdx, 1500);

	if (type_ == eAMMRType::Type_AGV)
	{
		SetMotor_Operating_Mode(conveyor, 1);
		SetMotor_Operating_Mode(conveyor_R, 3);
		SetMotor_Velocity(conveyor_R, 10);
		SetMotor_Profile_Velocity(conveyor_R, 10);
		SetMotor_Angle(conveyor_R, 0);
	}

	mbExecute = true;
}

/**
 * @brief The function that control the robot using simple control mode
 * 
 * @param mode Moving Mode, @ref eSimpleControlMode
 * @param RPM RPM of the motor
 */
void AMR::SimpleControl(eSimpleControlMode mode, int RPM)
{
	int LeftSpeed  = int(RPM / GetMotor_Scale2RPM(mnLeftMotorIdx ));
	int RightSpeed = int(RPM / GetMotor_Scale2RPM(mnRightMotorIdx));
	switch(mode)
	{
		case eSimpleControlMode::Left_Forward:
		{
			LeftSpeed = 0;
			RightSpeed = RightSpeed;
			break;
		}
		case eSimpleControlMode::Forward:
		{
			LeftSpeed = LeftSpeed;
			RightSpeed = RightSpeed;
			break;
		}
		case eSimpleControlMode::Right_Forward:
		{
			LeftSpeed = LeftSpeed;
			RightSpeed = 0;
			break;
		}
		case eSimpleControlMode::Left_Selfturn:
		{
			LeftSpeed = -1 * LeftSpeed;
			RightSpeed = RightSpeed;
			break;
		}
		case eSimpleControlMode::Pause:
		{
			LeftSpeed = 0;
			RightSpeed = 0;
			break;
		}
		case eSimpleControlMode::Right_Selfturn:
		{
			LeftSpeed =  LeftSpeed;
			RightSpeed = -1 * RightSpeed;
			break;
		}
		case eSimpleControlMode::Left_Backward:
		{
			LeftSpeed = 0;
			RightSpeed = -1 * RightSpeed;
			break;
		}
		case eSimpleControlMode::Backward:
		{
			LeftSpeed = -1 * LeftSpeed;
			RightSpeed = -1 * RightSpeed;
			break;
		}
		case eSimpleControlMode::Right_Backward:
		{
			LeftSpeed = -1 * LeftSpeed;
			RightSpeed = 0;
			break;
		}
	}

	// Left motor is opposite
	LeftSpeed = mnLeftDir * LeftSpeed;
	RightSpeed = mnRightDir * RightSpeed;

	SetMotor_Velocity(mnLeftMotorIdx,  LeftSpeed);
	SetMotor_Velocity(mnRightMotorIdx, RightSpeed);
}

/**
 * @brief The function that control the robot using linear and angular velocity
 * 
 * @param vel_linear Linear velocity
 * @param vel_angular Angular velocity
 */
void AMR::SetVelocity(float vel_linear, float vel_angular)
{
	float fRads2RPM = 1.0f * 60.0f / (2.0f * M_PI);
	float UrUlSum = 2 * vel_linear / mfWheelRadius;
	float UrUlSub = vel_angular * mfTrackWidth / mfWheelRadius;
	float TargetUrSi = (UrUlSum + UrUlSub) / 2; // Velocity in Radius/Second
	float TargetUlSi = (UrUlSum - UrUlSub) / 2; // Velocity in Radius/Second

	int RightSpeed = mnRightDir * int(TargetUrSi * fRads2RPM / GetMotor_Scale2RPM(mnRightMotorIdx));
	int LeftSpeed  = mnLeftDir * int(TargetUlSi * fRads2RPM / GetMotor_Scale2RPM(mnLeftMotorIdx ));
	
	SetMotor_Velocity(mnLeftMotorIdx,  LeftSpeed);
	SetMotor_Velocity(mnRightMotorIdx, RightSpeed);
}

/**
 * @brief The function that get the motor index (not ID) of the left robot
 * 
 * @return Left motor index
 */
int AMR::GetLeftIdx()
{
	return mnLeftMotorIdx;
}

/**
 * @brief The function that get the motor index (not ID) of the right robot
 * 
 * @return Right motor index
 */
int AMR::GetRightIdx()
{
	return mnRightMotorIdx;
}

/**
 * @brief The function that get the current velocity of the robot
 * 
 * @param fVelLinear Output Linear Velocity
 * @param fVelAngular Output Angular Velocity
 */
void AMR::GetVelocity(float &fVelLinear, float &fVelAngular)
{
	float fDiameter =  2 * mfWheelRadius * M_PI;
	float fRightVelocity = mnRightDir * GetMotor_PresentVelocityRPM(mnRightMotorIdx) / 60 * fDiameter;
	float fLeftVelocity = mnLeftDir * GetMotor_PresentVelocityRPM(mnLeftMotorIdx) / 60 * fDiameter;
	fVelLinear = (fRightVelocity + fLeftVelocity)/2;
	fVelAngular = (fRightVelocity - fLeftVelocity)/mfTrackWidth;
}

/**
 * @brief The function that get the connect state of the robot
 * @note Note that this is the internal state, we the real motor state
 * 
 * @return true 
 * @return false 
 */
bool AMR::GetExecuteState()
{
	return mbExecute;
}

/**
 * @brief The function that set the torque of the motor ON.
 * 
 */
void AMR::Start()
{
	mbExecute = true;
	SetAllMotorsTorqueEnable(true);
	if (type_ == eAMMRType::Type_AGV)
	{
		SetMotor_Operating_Mode(conveyor, 1);
		SetMotor_Operating_Mode(conveyor_R, 3);
		SetMotor_Velocity(conveyor_R, 80);
		SetMotor_Angle(conveyor_R, 0);
	}
}

/**
 * @brief The function that set the torque of the motor OFF.
 * 
 */
void AMR::Stop()
{
	mbExecute = false;
    SetAllMotorsTorqueEnable(false);
}

void AMR::RotateConveyor(const float &direction)
{
    SetMotor_Angle(conveyor_R, direction);
}

void AMR::Put(const int &velocity)
{
    SetMotor_Velocity(conveyor, velocity);
    this_thread::sleep_for(std::chrono::seconds(5));
    SetMotor_Velocity(conveyor, 0);
}
