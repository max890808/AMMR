
  
#include "AMMR/AMMR.h"
#include <tf2_ros/transform_listener.h>

class AMR_ArUco
{
    public:
        AMR_ArUco(bool *pTerminate);
        ~AMR_ArUco();
        void StartStrategy1();
        void StartStrategy2();


    private:
        AMMR *mpAMMR;

        bool *mpbTerminate;

    private:
        tf2_ros::Buffer mTFBuffer;
        tf2_ros::TransformListener *mpTFListener;
};