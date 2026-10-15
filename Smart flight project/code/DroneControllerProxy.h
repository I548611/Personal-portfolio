#ifndef DRONECONTROLLERPROXY_H
#define DRONECONTROLLERPROXY_H

#include <functional>
#include <string>
#include "mockController.h"
#include "Receiver.h"

class DroneControllerProxy 
{
public:
    using CommandHandler = std::function<void(const std::string&)>;

    explicit DroneControllerProxy(CommandHandler handler);
    std::string handleInput(int key);

private:
    Receiver receiver;
    mockController controllerinput;
    CommandHandler handler;

    void processPendingCommands();
};

#endif
