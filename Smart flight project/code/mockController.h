#ifndef MOCKCONTROLLER_H
#define MOCKCONTROLLER_H

#include "IReceiver.h"

class mockController 
{
public:
    explicit mockController(IReceiver& receiver);
    std::string forwardMovement();
    std::string backwardMovement();
    std::string leftMovement();
    std::string rightMovement();
    std::string upwardMovement();
    std::string downwardMovement();

private:
    IReceiver& receiver;
    void printControls() const;
};

#endif
