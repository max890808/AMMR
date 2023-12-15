#include "Strategy.h"

// Include Strategy Below
#include "AMR_ArUco/AMR_ArUco.h"
#include "AMR_Basic/AMR_Basic.h"
#include "AMR_SLAMTEC/AMR_SLAMTEC.h"
#include "AMMR_Basic/AMMR_Basic.h"
#include "GPM/Targetpicking.h"
#include "Test/Test.h"

// Constructor
Strategy::Strategy()
{
    isStrategyRunning = false;
    mbTerminated = false;
}

// Destructor
Strategy::~Strategy() {}

/**
 * Run choosen strategy
 * 
 * @param strategy_name - the strategy name choosen by user
 */
void Strategy::select_strategy(std::string strategy_name)
{
    isStrategyRunning = true;
    mbTerminated = false;
    while (isStrategyRunning)
    {
        // add strategy below !!!!!!!!
        // If the strategy name match the cases, execute the strategy
        if (strategy_name == "Demo")
        {
            /* The parameter &mbTerminated is required for soft interrupt!! */
            // Demo *pStrategy = new Demo(&mbTerminated);
            // delete pStrategy;
            
            /* If the strategy only execute once, then set isStrategyRunning flag to false */
            // isStrategyRunning = false;
        }
        else if (strategy_name == "AMR_ArUco")
        {
            AMR_ArUco *pStrategy = new AMR_ArUco(&mbTerminated);
            delete pStrategy;
            isStrategyRunning = false;
        }
        else if (strategy_name == "AMR_Basic")
        {
            AMR_Basic *pStrategy = new AMR_Basic(&mbTerminated);
            delete pStrategy;
            isStrategyRunning = false;
        }
        else if (strategy_name == "AMR_SLAMTEC_DEMO")
        {
            AMR_SLAMTEC *pStrategy = new AMR_SLAMTEC(&mbTerminated);
            delete pStrategy;
            isStrategyRunning = false;
        }
        else if (strategy_name == "AMMR_Basic")
        {
            AMMR_Basic *pStrategy = new AMMR_Basic(&mbTerminated);
            delete pStrategy;
            isStrategyRunning = false;
        }
        else if (strategy_name == "Targetpicking")
        {
            Targetpicking *pTargetpicking = new Targetpicking(&mbTerminated);
            delete pTargetpicking;
            isStrategyRunning = false;
        }
        else if (strategy_name == "Test")
        {
            Test *pStrategy = new Test(&mbTerminated);
            delete pStrategy;
            isStrategyRunning = false;
        }        
        else
        {

        }
    }
}