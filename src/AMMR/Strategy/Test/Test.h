#include "AMMR/AMMR.h"

class Test
{
    public:
        Test(bool *pTerminate);
        ~Test();
        Eigen::Matrix<float, 4, 4> StartStrategy1();
        bool StartStrategy2();
        bool StartStrategy3();

    private:
        bool *mpbTerminate;
        AMMR *mpRobot;
};