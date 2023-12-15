/**
 * @file AMR.h
 * @brief AMR header file
 * 
 */

#ifndef AMR_H
#define AMR_H
#include "MotorUnion/MotorUnion.h"

/**
 * @brief Simple Control Enum
 * 
 */
enum class eSimpleControlMode{
    Left_Forward=0,     /**< Left Stop, Right Forward*/
    Forward=1,          /**< Left Forward, Right Forward*/
    Right_Forward=2,    /**< Left Forward, Right Stop*/
    Left_Selfturn=3,    /**< Left Backward, Right Forward*/
    Pause=4,            /**< Left Stop, Right Stop*/
    Right_Selfturn=5,   /**< Left Forward, Right Backward*/
    Left_Backward=6,    /**< Left Stop, Right Backward*/
    Backward=7,         /**< Left Backward, Right Backward*/
    Right_Backward=8    /**< Left Backward, Right Stop*/
};

/**
 * @brief AMMR Type
 * 
 */
enum class eAMMRType{
    Type_AMMR=0, /**<  aiRobots_AMMR*/
    Type_AMR=1, /**<  aiRobots_AMR*/
	Type_AGV=2/**<	aiRobots_AGV*/
};

/**
 * @brief The class for differential drive robot, including aiRobots-AMR and aiRobots-AMMR
 * 
 */
class AMR : public MotorUnion
{
public:

    AMR(const vector<unsigned char> &vcAMR_ID, const vector<string> &vstrAMR_Model, 
                float fWheelRadius, float fTrackWidth, int nLeftDir, int nRightDIR, eAMMRType type);

    // Control
    void SimpleControl(eSimpleControlMode mode, int RPM);
    void SetVelocity(float vel_linear, float vel_angular);
    // Getter
    int GetLeftIdx();
    int GetRightIdx();
    void GetVelocity(float &fVelLinear, float &fVelAngular);
    bool GetExecuteState();

    // Conveyor Control(AGV Only)
    void RotateConveyor(const float &direction);
    void Put(const int &velocity);

    // Start/Stop
    void Start();
    void Stop();

    const unsigned char conveyor_R;
	const unsigned char conveyor;

private:
    eAMMRType type_;
    bool mbExecute;
    float mfWheelRadius, mfTrackWidth;
    int mnLeftDir, mnRightDir;
    int mnLeftMotorIdx, mnRightMotorIdx;
};

#endif // AMR_H
