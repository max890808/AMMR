#include "Targetpicking.h"

Targetpicking::Targetpicking(bool *flag)
    : is_getting_position(false),
      is_ammr_stop(false),
      get_next_job(false),
      ammr_location(9),
      ammr_status("idle"),
      object_id(0),
      remaining_object_number(0),
      finish_job(true),
      left_or_right(0),
      placement_x(420.f),
      placement_y(0.f),
      placement_z(320.f),
      placement_oz(0.f),
      global_ammr_position(
        {
            {  -0.4,  1.31,  -M_PI/2}, // 1
            {  -0.9,  1.65,  -M_PI/2}, // 2
            {  -0.4,  2.06,  -M_PI/2}, // 3
            {  1.44,  2.65,   M_PI/2}, // 4
            {  1.88,  2.20,   M_PI/2}, // 5
            {  1.44,  1.84,   M_PI/2}, // 6
            { -0.58,  4.14,  -M_PI/2}, // 7
            { -0.58,  4.14,  -M_PI/2}, // 8 
            { -0.58,  4.14,  -M_PI/2}, // 9
            { -0.58,  4.14,  -M_PI/2}, // 10
            {   0.49, 3.81,     M_PI}, // 11
            {   0.45, 0.14,        0}, // 12 
        }
      ),
      placement_position(
        {
            {570, -80, 200,  0},
            {570,  80, 200,  0},
            {390,  80, 150, 90}, 
            {270,  80, 150, 90}, 
            {330, -80, 220,  0},
        }
      ),
      id_0_count(0),
      id_1_count(0),
      id_2_count(0)
{
    mpAMMR = AMMR::GetAMMR(eAMMRType::Type_AMMR);
    mpAMMR->mpControlInterface->SetMoveBaseClient(true, 10, "map", false, "aiRobots_AMR/action_goal"); // In order to track the control from rviz
    mpAMMR->mpControlInterface->SubControlFromTwist("/cmd_vel");
    mpAMMR->mpControlInterface->SubPosFromTF("map", "base");
    mpAMMR->mpVisionInterface->StartSubFromRGBD("/camera/color/image_raw", "/camera/aligned_depth_to_color/image_raw", 
                                        "/camera/color/camera_info", "/camera/aligned_depth_to_color/camera_info");
    mpAMMR->mpLiDARInterface1->StartSubFromLiDAR("/scan_front");
    mpAMMR->mpLiDARInterface2->StartSubFromLiDAR("/scan_rear");
    mpManipulator  = mpAMMR->mpManipulator;
    terminated = flag;
    cameradetectposition << 0.0, 0.0, 0.0, 0.0;
    target_position << 0.0, 0.0, 0.0, 0.0;
    StartStrategy();
}

Targetpicking::~Targetpicking()
{
    Terminate();
    ros_thread->join();
    state_pub_thread->join();
    delete ros_thread, state_pub_thread;
}

void Targetpicking::Terminate()
{
    cout << "\033[1;33m[INFO] Strategy Terminating\033[0m" << endl;
    #ifdef MOVING
    mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 320);
    mpManipulator->RotateSixArm(0);
    mpManipulator->SetArmVelocity(0, 0, 0, 0, 0, 0);
    mpManipulator->PneumaticOff();
    #endif
    *terminated = true;
}

void Targetpicking::StartStrategy()
{
    InitialROS();
    MainStrategy();
}

void Targetpicking::InitialROS()
{   
    service = this->n_.advertiseService("Job", &Targetpicking::Get_job, this);
    position_client = this->n_.serviceClient<airobots_ammr::Yolo>("Target_pose");
    state_pub = this->n_.advertise<std_msgs::String>("airobots/status",1);
    location_pub = this->n_.advertise<std_msgs::Int32>("airobots/position",1);
    ros_thread = new std::thread(&Targetpicking::Ros_spin,this);
    state_pub_thread = new std::thread(&Targetpicking::Pub_AmmrState,this);
}

void Targetpicking::Pub_AmmrState(void)
{
    while(!*terminated)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000)));
        std_msgs::String p_state;
        std_msgs::Int32 p_location;
        p_state.data = ammr_status;
        p_location.data = ammr_location;
        state_pub.publish(p_state);
        location_pub.publish(p_location);
    }
}

bool Targetpicking::Get_job(airobots_ammr::Job::Request &req, airobots_ammr::Job::Response &res){
    while(!finish_job){};
    while(timer==0){};
    std::unique_lock<std::mutex> lock(ammr_job_lock);
    std::cout << "\033[1;33m[INFO] Get Job!\033[0m" << std::endl;
    desire_ammr_location = req.ammr_location;
    res.ok = 1;
    get_next_job = true;
    finish_job = false;
    return true;
}

bool Targetpicking::PositionRequest(const int &demand)
{
    is_getting_position = false; 
    p_srv.request.id = object_id;
    p_srv.request.demand = demand;
    int times = 0;
    while(true)
    {
        position_client.call(p_srv);
        if(p_srv.response.position[3] == 1.0){
            is_getting_position = true;
            break;
        } 
        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
        if(times >= 5){
            is_getting_position = false;
            std::cout<< "\033[1;31m[INFO] Can't find target. Wait for next job!!!\033[0m" << std::endl;
            break;
        }
        times++;
    }
   
    if(is_getting_position == true){
        object_id = p_srv.response.id;
        // remaining_object_number = p_srv.response.remaining_object_number; 
        cameradetectposition << p_srv.response.position[0], p_srv.response.position[1], p_srv.response.position[2], p_srv.response.position[3];
        target_orientation = p_srv.response.orientation;
        Camera2Base();
        return true;
    }
    else if(is_getting_position == false){
        get_next_job = false;
        finish_job = true;
        return false;
    }
}

void Targetpicking::Ros_spin()
{
    while(!*terminated)
    {
        ros::spinOnce();
        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
    }
}

void Targetpicking::MainStrategy()
{
    #ifdef MOVING
    mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
    std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
    mpManipulator->RotateSixArm(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
    #endif
    
    timer = 0;

    while(!*terminated)
    {   
        ammr_status = "idle";

        is_ammr_stop = false;
        float height = 0.f;
        float z_shift = 0.f;
        std:: cout << "get_next_job: " << get_next_job << std::endl;
        if (get_next_job == true)
        {
            Navigation(desire_ammr_location);
            std:: cout << "stop!! " << std::endl;
            if(is_ammr_stop && ammr_location != 7 && ammr_location != 8 && ammr_location != 9 && ammr_location != 10)
            {
                // remaining_object_number = 1;
                while(1)
                {
                    ammr_status = "process";
                    std::cout << "\033[1;33m[INFO] AMMR_Manipulator is ready to move.\033[0m" << std::endl;
                    #ifdef MOVING
                    if(left_or_right == 1) mpManipulator->RotateSixArm(90); // left
                    else mpManipulator->RotateSixArm(-90); // right
                    std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
                    mpManipulator->TrajectoryPlanning(0, 0, 0, 550, 0, 300);
                    std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                    #endif

                    if(!PositionRequest(1)) 
                    {
                        #ifdef MOVING
                        mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
                        mpManipulator->RotateSixArm(0);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
                        #endif
                        is_getting_position = false;
                        is_ammr_stop = false;
                        get_next_job = false;
                        finish_job = true;
                        break;;
                    }
                    else
                    {
                        if (object_id == 2 || object_id == 0)
                        {
                            height = 270+50;
                            z_shift = -12;
                        }
                        else if (object_id == 1)
                        {
                            height = 270;
                            z_shift = -4;
                        }
                    }

                    if(is_getting_position)
                    {   
                        #ifdef MOVING
                        mpManipulator->PneumaticOff();
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        // arm close to target
                        // first close
                        mpManipulator->TrajectoryPlanning(0, 0, 0,target_position[0]-100, target_position[1], height);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        #endif

                        // second close
                        if(!PositionRequest(2)){
                            #ifdef MOVING
                            mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
                            mpManipulator->RotateSixArm(0);
                            std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
                            #endif
                            is_getting_position = false;
                            is_ammr_stop = false;
                            get_next_job = false;
                            finish_job = true;
                            break;
                        }

                        #ifdef MOVING
                        mpManipulator->TrajectoryPlanning(0, 0, 0, target_position[0]-100, target_position[1], height);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        #endif

                        // get target position and orientation
                        if(!PositionRequest(2)){
                            #ifdef MOVING
                            mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
                            mpManipulator->RotateSixArm(0);
                            std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
                            #endif
                            is_getting_position = false;
                            is_ammr_stop = false;
                            get_next_job = false;
                            finish_job = true;
                            break;
                        }

                        #ifdef MOVING
                        // change end effector orientation and close to the target
                        float orientation = 0;
                        if(p_srv.response.orientation > 0) orientation = 90 - target_orientation;
                        else if(p_srv.response.orientation < 0) orientation = (90 + target_orientation)*-1;
                        mpManipulator->TrajectoryPlanning(0, 0, 0, target_position[0], target_position[1], height);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0-orientation, target_position[0], target_position[1], height);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0-orientation, target_position[0], target_position[1], target_position[2]+z_shift);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        #endif

                        #ifdef MOVING
                        // pick the target
                        mpManipulator->PneumaticOn();
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(500)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0-orientation, target_position[0], target_position[1], height);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0, target_position[0], target_position[1], height);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0, 550, 0, 300);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->RotateSixArm(0);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
                        GetPlacementPosition(placement_x, placement_y, placement_z, placement_oz);
                        mpManipulator->TrajectoryPlanning(0, 0, placement_oz, placement_x, placement_y, 300);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, placement_oz, placement_x, placement_y, placement_z);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->PneumaticOff();
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(1500)));
                        mpManipulator->TrajectoryPlanning(0, 0, placement_oz, placement_x, placement_y, 300);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                        mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
                        std::this_thread::sleep_for(std::chrono::milliseconds(int(1000)));
                        #endif
                        is_getting_position = false;
                        is_ammr_stop = false;
                        get_next_job = false;
                        std::cout<< "\033[1;33m[INFO] Mission is complete!\033[0m" << std::endl;
                        timer = 0;
                    }
                }
            }
            else timer = 0;
        }
        else if (timer == 0)
        {
            is_getting_position = false;
            is_ammr_stop = false;
            std::unique_lock<std::mutex> lock(ammr_job_lock);
            get_next_job = false;
            finish_job = true;
            ammr_job_lock.unlock();
            std::cout<< "\033[1;33m[INFO] Mission is complete!\033[0m" << std::endl;
            timer++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(int(500)));
    }
    #ifdef MOVING
    mpManipulator->TrajectoryPlanning(0, 0, 0, 420, 0, 300);
    std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
    mpManipulator->RotateSixArm(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(int(3500)));
    #endif
}

void Targetpicking::Navigation(const int &desire_ammr_location)
{
    std::cout << "\033[1;33m[INFO] AMMR is ready to move!\033[0m" << std::endl;
    ammr_status = "move";

    bool is_need_following_point = false;
    int tmp_ammr_location = 0;

    double dx, dy, dz, dOz, dOy, dOx;
    bool bGetPos = mpAMMR->mpControlInterface->GetPosZYXFromTF(dx, dy, dz, dOz, dOy, dOx);
    dOz = dOz * 180 / M_PI;
    double distance = sqrt(pow(dx-global_ammr_position[desire_ammr_location-1][0],2)+pow(dy-global_ammr_position[desire_ammr_location-1][1],2));
    if (bGetPos && distance <= 0.05)
    {
        std::cout << "\033[1;33m[INFO] AMMR stop.\033[0m" << std::endl;
        ammr_location = desire_ammr_location;

        is_ammr_stop = true;
        get_next_job = false;
        switch(desire_ammr_location)
        {
            case 1:case 3:case 4:case 6:
                left_or_right = 1;
                break;
            case 2:case 5:
                left_or_right = 0;
                break;
        }
    }
    else
    {
        do
        {
            is_ammr_stop = false;
            switch(desire_ammr_location)
            {
                case 0:
                    mpAMMR->mpControlInterface->SendGoalZYX(0.0, 0.0, 0.0, M_PI/2, 0.0, 0.0);
                    break;
                case 1:
                    if ((ammr_location == 4 || ammr_location == 5 || ammr_location == 6) && tmp_ammr_location != 11)  
                    {
                        mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[10][0], global_ammr_position[10][1], 0.0, global_ammr_position[10][2], 0.0, 0.0);
                        is_need_following_point = true;
                        tmp_ammr_location = 11;
                        break;
                    }
                    is_need_following_point = false;
                    tmp_ammr_location = desire_ammr_location;
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[0][0], global_ammr_position[0][1], 0.0, global_ammr_position[0][2], 0.0, 0.0);
                    left_or_right = 1;
                    cout << "left_or_right: " << left_or_right << endl;
                    break;
                case 2:
                    if ((ammr_location == 4 || ammr_location == 5 || ammr_location == 6) && tmp_ammr_location != 11)  
                    {
                        mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[10][0], global_ammr_position[10][1], 0.0, global_ammr_position[10][2], 0.0, 0.0);
                        is_need_following_point = true;
                        tmp_ammr_location = 11;
                        break;
                    }
                    is_need_following_point = false;
                    tmp_ammr_location = desire_ammr_location;
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[1][0], global_ammr_position[1][1], 0.0, global_ammr_position[1][2], 0.0, 0.0);
                    left_or_right = 0;
                    break;
                case 3: 
                    if ((ammr_location == 4 || ammr_location == 5 || ammr_location == 6) && tmp_ammr_location != 11)  
                    {
                        mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[10][0], global_ammr_position[10][1], 0.0, global_ammr_position[10][2], 0.0, 0.0);
                        is_need_following_point = true;
                        tmp_ammr_location = 11;
                        break;
                    }
                    is_need_following_point = false;
                    tmp_ammr_location = desire_ammr_location;
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[2][0], global_ammr_position[2][1], 0.0, global_ammr_position[2][2], 0.0, 0.0);
                    left_or_right = 1;
                    break;
                case 4: 
                    if ((ammr_location == 1 || ammr_location == 2 || ammr_location == 3) && tmp_ammr_location != 12)
                    {
                        mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[11][0], global_ammr_position[11][1], 0.0, global_ammr_position[11][2], 0.0, 0.0);
                        is_need_following_point = true;
                        tmp_ammr_location = 12;
                        break;
                    }
                    is_need_following_point = false;
                    tmp_ammr_location = desire_ammr_location;
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[3][0], global_ammr_position[3][1], 0.0, global_ammr_position[3][2], 0.0, 0.0);
                    left_or_right = 1;
                    break;
                case 5:
                    if ((ammr_location == 1 || ammr_location == 2 || ammr_location == 3) && tmp_ammr_location != 12)
                    {
                        mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[11][0], global_ammr_position[11][1], 0.0, global_ammr_position[11][2], 0.0, 0.0);
                        is_need_following_point = true;
                        tmp_ammr_location = 12;
                        break;
                    }
                    is_need_following_point = false;
                    tmp_ammr_location = desire_ammr_location;
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[4][0], global_ammr_position[4][1], 0.0, global_ammr_position[4][2], 0.0, 0.0);
                    left_or_right = 0;
                    break;
                case 6:
                    if ((ammr_location == 1 || ammr_location == 2 || ammr_location == 3) && tmp_ammr_location != 12)
                    {
                        mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[11][0], global_ammr_position[11][1], 0.0, global_ammr_position[11][2], 0.0, 0.0);
                        is_need_following_point = true;
                        tmp_ammr_location = 12;
                        break;
                    }
                    is_need_following_point = false;
                    tmp_ammr_location = desire_ammr_location;
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[5][0], global_ammr_position[5][1], 0.0, global_ammr_position[5][2], 0.0, 0.0);
                    left_or_right = 1;
                    break;
                // case 7:
                //     mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[6][0], global_ammr_position[6][1], 0.0, global_ammr_position[6][2], 0.0, 0.0);
                //     tmp_ammr_location = desire_ammr_location;
                //     break;
                // case 8:
                //     mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[7][0], global_ammr_position[7][1], 0.0, global_ammr_position[7][2], 0.0, 0.0);
                //     tmp_ammr_location = desire_ammr_location;
                //     break;
                case 9:
                    mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[8][0], global_ammr_position[8][1], 0.0, global_ammr_position[8][2], 0.0, 0.0);
                    tmp_ammr_location = desire_ammr_location;
                    id_0_count=0;
                    id_1_count=0;
                    id_2_count=0;
                    break;
                // case 10:
                //     mpAMMR->mpControlInterface->SendGoalZYX(global_ammr_position[9][0], global_ammr_position[9][1], 0.0, global_ammr_position[9][2], 0.0, 0.0);
                //     tmp_ammr_location = desire_ammr_location;
                //     break;
            }
            int ammr_stop_times = 0;
            float fVelLinear, fVelAngular;
            while(fVelLinear == 0.f && fVelAngular == 0.f) {mpAMMR->mpAMR->GetVelocity(fVelLinear, fVelAngular);};
            while(!is_ammr_stop)
            {
                while(mpAMMR->mpControlInterface->linear_x != 0.f || mpAMMR->mpControlInterface->angular_z != 0.f) {};
                bGetPos = mpAMMR->mpControlInterface->GetPosZYXFromTF(dx, dy, dz, dOz, dOy, dOx);
                // dOz = dOz * 180 / M_PI;
                distance = sqrt(pow(dx-global_ammr_position[tmp_ammr_location-1][0],2)+pow(dy-global_ammr_position[tmp_ammr_location-1][1],2));   
                // mpAMMR->mpAMR->GetVelocity(fVelLinear, fVelAngular);
                if (mpAMMR->mpControlInterface->linear_x == 0.f && mpAMMR->mpControlInterface->angular_z == 0.f) ammr_stop_times++;
                else ammr_stop_times = 0;
                std::this_thread::sleep_for(std::chrono::milliseconds(int(100)));
                if (ammr_stop_times == 50 && bGetPos && distance <= 0.05) 
                {
                    mpAMMR->mpControlInterface->mpMBClient->CancelGoal();
                    std::cout << "\033[1;33m[INFO] AMMR stop.\033[0m" << std::endl;
                    
                    if (!is_need_following_point) 
                    {
                        ammr_location = desire_ammr_location;
                    }
                    is_ammr_stop = true;
                    if (tmp_ammr_location == 11 || tmp_ammr_location == 12) std::this_thread::sleep_for(std::chrono::milliseconds(int(5000)));
                }

                else if (ammr_stop_times == 50)
                {
                    std::cout << "\033[1;31m[INFO] AMMR Navigation Fail!!!\033[0m" << std::endl;
                    std::cout << "\033[1;33m[INFO] AMMR stop.\033[0m" << std::endl;
                    mpAMMR->mpControlInterface->mpMBClient->CancelGoal();
                    is_ammr_stop = false;
                    break;
                }
            }
            get_next_job = false;
            std::cout<< "\033[1;33m[INFO] is_need_following_point: " << is_need_following_point << "\033[0m" << std::endl;
        } while(is_need_following_point);
    }
    std::cout<< "\033[1;33m[INFO] Navigation is complete!\033[0m" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(int(1000)));
}

void Targetpicking::Camera2Base()
{
    Eigen::Matrix<float, 4, 4> T05 = mpManipulator->GetT05();
    float motor6angle = mpManipulator->Getmotor6angle();
    Eigen::Matrix<float, 4, 4> T5C1 = mpManipulator->GetTransformMatrix(motor6angle, 0, 75.08, 167.9);
    // Eigen::Matrix<float, 4, 4> T5C1 = mpManipulator->GetTransformMatrix(0, 0, 75.08, 170);
    Eigen::Matrix<float, 4, 4> TC1C2 = mpManipulator->GetTransformMatrix(M_PI/2, 0, 0, 0);
    Eigen::Matrix<float, 4, 4> T0C = T05*T5C1*TC1C2; 
    #ifdef DEBUG
    motor6_position << T05(0,3), T05(1,3), T05(2,3), 1.0;
    camera_position << T0C(0,3), T0C(1,3), T0C(2,3), 1.0;
    #endif
    target_position = T0C*cameradetectposition;
}

void Targetpicking::GetPlacementPosition(float &placement_x, float &placement_y, float &placement_z, float &placement_oz)
{
    switch (object_id)
    {
        case 0:
            if (id_0_count == 2) break;
            placement_x = placement_position[id_0_count][0];
            placement_y = placement_position[id_0_count][1];
            placement_z = placement_position[id_0_count][2];
            placement_oz = placement_position[id_0_count][3];
            id_0_count++;
            break;
        case 1:
            if (id_1_count == 2) break;
            placement_x = placement_position[id_1_count+2][0];
            placement_y = placement_position[id_1_count+2][1];
            placement_z = placement_position[id_1_count+2][2];
            placement_oz = placement_position[id_1_count+2][3];
            id_1_count++;
            break;
        case 2:
            if (id_2_count == 1) break;
            placement_x = placement_position[id_2_count+4][0];
            placement_y = placement_position[id_2_count+4][1];
            placement_z = placement_position[id_2_count+4][2];
            placement_oz = placement_position[id_2_count+4][3];
            id_2_count++; 
            break;
    }
}