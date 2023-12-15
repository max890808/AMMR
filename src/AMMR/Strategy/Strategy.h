#ifndef STRATEGY_H
#define STRATEGY_H

#include <string>

class Strategy {
public:
    Strategy();
    ~Strategy();

    void select_strategy(std::string strategy_name);
    void terminate_strategy() { isStrategyRunning = false; mbTerminated = true; }

private:
    bool isStrategyRunning;
    bool mbTerminated;
};
#endif // STRATEGY_H
