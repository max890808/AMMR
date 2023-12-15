#include "AMMR/AMMR.h"

class AMR_SLAMTEC
{
    public:
        AMR_SLAMTEC(bool *pTerminate);
        ~AMR_SLAMTEC();
        void StartStrategy();

    private:
        AMMR *mpRobot;

        bool *mpbTerminate;
};