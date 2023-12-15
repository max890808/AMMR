#include "AMMR/AMMR.h"


class AMMR_Basic
{
    public:
        AMMR_Basic(bool *pTerminate);
        ~AMMR_Basic();
        void StartStrategy();

    private:
        AMMR *mpRobot;

        bool *mpbTerminate;
};