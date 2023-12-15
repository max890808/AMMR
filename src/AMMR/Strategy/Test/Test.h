#include "AMMR/AMMR.h"

class Test
{
    public:
        Test(bool *pTerminate);
        ~Test();
        void StartStrategy();

    private:
        AMMR *mpRobot;
        bool *mpbTerminate;
};