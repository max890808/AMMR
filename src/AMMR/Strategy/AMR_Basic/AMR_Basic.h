#include "AMMR/AMMR.h"


class AMR_Basic
{
    public:
        AMR_Basic(bool *pTerminate);
        ~AMR_Basic();
        void StartStrategy();

    private:
        AMMR *mpRobot;

        bool *mpbTerminate;
};