#include "mockController.h"
#include <string>
#include <iostream>
#ifdef _WIN32
#include <conio.h>
#endif

mockController::mockController(IReceiver& receiver)
    : receiver(receiver)
{
    printControls();
}

std::string mockController::forwardMovement()
{
    receiver.send("FORWARD");
    return "Forward movement";
}

std::string mockController::backwardMovement()
{
    receiver.send("BACKWARD");
    return "Backward movement";
}

std::string mockController::leftMovement()
{
    receiver.send("LEFT");
    return "Left movement";
}

std::string mockController::rightMovement()
{
    receiver.send("RIGHT");
    return "Right movement";
}

std::string mockController::upwardMovement()
{
    receiver.send("UP");
    return "Upward movement";
}

std::string mockController::downwardMovement()
{
    receiver.send("DOWN");
    return "Downward movement";
}

void mockController::printControls() const
{
    std::cout << "The controls are:\n"
              << " -w = move forward\n"
              << " -s = move backward\n"
              << " -a = move left\n"
              << " -d = move right\n"
              << " -u = move up\n"
              << " -j = move down\n"
              << " -q = landing the drone and shutting it off\n";
}
