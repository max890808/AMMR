#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include "MotorUnion/MotorUnion.h"

#include <Poco/Net/SocketStream.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/LU>
#include <vector>
#include <math.h>
#include <thread>

class Manipulator : public MotorUnion
{
public:
    /* Constructor */
    static Manipulator *GetManipulator();
    Manipulator();
    ~Manipulator() { inst_ = nullptr; };

    void Start();
    void Stop();
    /* CORE function */
    void CalculateJacobianMatrix(void);
    void TrajectoryPlanning(const float &ox, const float &oy, const float &oz, const float &px, const float &py, const float &pz);
    void ImpedanceControl(const float &om, const float &ob, const float &ok, const float &pm, const float &pb, const float &pk,
                          const float &ox, const float &oy, const float &oz, const float &px, const float &py, const float &pz);

    /* Get data function */
    Eigen::Matrix<float, 4, 4> GetTransformMatrix(const float &theta, const float &alpha, const float &a, const float &d);
    Eigen::Matrix<float, 3, 3> GetRotationMatrix(const int &axis_index, const float &theta);
    Eigen::Matrix<float, 6, 6> GetJacobianMatrix(void);
    Eigen::Matrix<float, 4, 4> GetT05(void);
    float Getmotor6angle(void);
    float GetCurrentPosition(int index);
    float GetCurrentOrientation(int index);
    bool GetWorkingState(void);

    /* Set data function */
    void SetArmVelocity(float v0, float v1, float v2, float v3, float v4, float v5);

    /* Gripper */
    void PneumaticOn(void);
    void PneumaticOff(void);

    /* Functional */
    int Sign(float x);
    float RootMeanSquareError(Eigen::Matrix<float, 3, 1> target_data, Eigen::Matrix<float, 3, 1> current_data);  
    Eigen::Matrix<float, 6, 1> CheckMotorVelocity(Eigen::Matrix<float, 6, 1> motor_velocity);  

    /* Rotation Platform */
    void RotateSixArm(const float &angle);

    const float pro_radpersec2scale_;   
    const unsigned char FIRST_HAND_ID_;
    const unsigned char ROTATE_PLATFORM_ID_;
private:
    static Manipulator *inst_;
    Eigen::Matrix<float, 4, 4> t05;
    Eigen::Matrix<float, 6, 6> jacobian_matrix_;
    Eigen::Matrix<float, 6, 6> inverse_jacobian_matrix_;

    Eigen::Matrix<float, 3, 1> current_position_;
    Eigen::Matrix<float, 3, 1> current_orientation_;
    float motor6angle;

    const float END_EFFECTOR_LENGTH_;
    const int DELAY_TIME_;

    FILE *port_file_;
    
    bool is_out_of_limit_;
    bool is_working_;

    // Poco::Net::SocketAddress addr;
    // Poco::Net::StreamSocket socket;
};

#endif // MANIPULATOR_H

