#include "AMMR/AMMR.h"

class Test
{
    public:
        Test(bool *pTerminate);
        ~Test();
        Eigen::Matrix<float, 4, 4> StartStrategy();

    private:
        AMMR *mpRobot;
        bool *mpbTerminate;
};