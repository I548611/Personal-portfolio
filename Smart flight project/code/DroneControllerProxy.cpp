
#include "DroneControllerProxy.h"

DroneControllerProxy::DroneControllerProxy(CommandHandler handler)
    : receiver(), controllerinput(receiver), handler(std::move(handler))
{
}

std::string DroneControllerProxy::handleInput(int key) 
{
    std::string message;
    switch (key) 
    {
        case 'w':
        case 'W':
            message = controllerinput.forwardMovement();
            break;
        case 's':
        case 'S':
            message = controllerinput.backwardMovement();
            break;
        case 'a':
        case 'A':
            message = controllerinput.leftMovement();
            break;
        case 'd':
        case 'D':
            message = controllerinput.rightMovement();
            break;
        case 'u':
        case 'U':
            message = controllerinput.upwardMovement();
            break;
        case 'j':
        case 'J':
            message = controllerinput.downwardMovement();
            break;
        default:
            message = "Unknown key. Use w/s/a/d/u/j or q to quit.";
            break;
    }

    if (message != "Unknown key. Use w/s/a/d/u/j or q to quit.") 
    {
        processPendingCommands();
    }

    return message;
}

void DroneControllerProxy::processPendingCommands() 
{
    while (receiver.hasMessage()) 
    {
        handler(receiver.receive());
    }
}


