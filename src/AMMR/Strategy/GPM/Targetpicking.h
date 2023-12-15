#include "AMMR/AMMR.h"
#include <time.h>
#include <string>
#include <thread>
#include <mutex>
// ROS
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "airobots_ammr/Yolo.h"
#include "airobots_ammr/Job.h"
#include <ros/ros.h>

#define DEBUG
#define MOVING
class Targetpicking
{
public:
    Targetpicking(bool *flag);
    ~Targetpicking();
    
    void Terminate(void);
    void StartStrategy(void);
    void MainStrategy(void);
    void Camera2Base(void);

    void GetPlacementPosition(float &placement_x, float &placement_y, float &placement_z, float &placement_oz);

private:
    /* ROS */
    ros::NodeHandle n_;
    void InitialROS(void);
    void Ros_spin(void);
    thread *ros_thread;

    /* Client */
    ros::ServiceClient position_client;
    airobots_ammr::Yolo p_srv;
    bool PositionRequest(const int &demand);

    /* Publish */
    ros::Publisher state_pub;
    ros::Publisher location_pub;
    void Pub_AmmrState(void);
    thread *state_pub_thread;

    /* Server */
    ros::ServiceServer service;
    airobots_ammr::Job debug_srv; 
    bool Get_job(airobots_ammr::Job::Request &req, airobots_ammr::Job::Response &res);
    mutex ammr_job_lock;

    /* Navigation */
    void Navigation(const int &ammr_location);

private:
    AMMR *mpAMMR;
    Manipulator *mpManipulator;
    int ammr_location;
    std::string ammr_status;

    int timer;
    int object_id;
    Eigen::Matrix<float, 4, 1> motor6_position;
    Eigen::Matrix<float, 4, 1> camera_position;
    Eigen::Matrix<float, 4, 1> cameradetectposition;
    Eigen::Matrix<float, 4, 1> target_position;
    float target_orientation;
    int remaining_object_number;
    float placement_x;
    float placement_y;
    float placement_z;
    float placement_oz;

    int desire_ammr_location;

    bool *terminated;
    bool is_getting_position;
    bool is_ammr_stop;
    bool get_next_job;
    bool finish_job;
    /* 1, if table is on the left side of the ammr. 0, if table is on the right side of the ammr.*/
    bool left_or_right;
    std::vector<std::vector<double>> global_ammr_position;

    std::vector<std::vector<double>> placement_position;
    int id_0_count;
    int id_1_count;
    int id_2_count;
};