#include <iostream>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif
#include "DroneControllerProxy.h"
#include "drone.h"
#include <memory>

int main()
{
    auto Gps = createGps();
    auto MotorRB = createMotor();
    auto MotorLB = createMotor();
    auto MotorRF = createMotor();
    auto MotorLF = createMotor();
    StartDrone(*Gps, *MotorRB, *MotorLB, *MotorRF, *MotorLF);

    DroneControllerProxy proxy([&](const std::string& cmd) 
    {
        if (cmd == "FORWARD") 
        {
            Gps->updatePosition(MOVE_FORWARD, 0, 0);
            MotorRB->setMotorPower(STRONG_MOTOR_POWER_FORWARD);
            MotorLB->setMotorPower(STRONG_MOTOR_POWER_FORWARD);
            MotorRF->setMotorPower(SOFT_MOTOR_POWER_FORWARD);
            MotorLF->setMotorPower(SOFT_MOTOR_POWER_FORWARD);
        } 
        else if (cmd == "BACKWARD") 
        {
            Gps->updatePosition(MOVE_BACKWARD, 0, 0);
            MotorRB->setMotorPower(SOFT_MOTOR_POWER_BACKWARD);
            MotorLB->setMotorPower(SOFT_MOTOR_POWER_BACKWARD);
            MotorRF->setMotorPower(STRONG_MOTOR_POWER_BACKWARD);
            MotorLF->setMotorPower(STRONG_MOTOR_POWER_BACKWARD);
        } 
        else if (cmd == "LEFT") 
        {
            Gps->updatePosition(0, MOVE_LEFT, 0);
            MotorRB->setMotorPower(STRONG_MOTOR_POWER_LEFT);
            MotorLB->setMotorPower(SOFT_MOTOR_POWER_LEFT);
            MotorRF->setMotorPower(STRONG_MOTOR_POWER_LEFT);
            MotorLF->setMotorPower(SOFT_MOTOR_POWER_LEFT);
        } 
        else if (cmd == "RIGHT") 
        {
            Gps->updatePosition(0, MOVE_RIGHT, 0);
            MotorRB->setMotorPower(SOFT_MOTOR_POWER_RIGHT);
            MotorLB->setMotorPower(STRONG_MOTOR_POWER_RIGHT);
            MotorRF->setMotorPower(SOFT_MOTOR_POWER_RIGHT);
            MotorLF->setMotorPower(STRONG_MOTOR_POWER_RIGHT);
        } 
        else if (cmd == "UP") 
        {
            Gps->updatePosition(0, 0, MOVE_UP);
            MotorRB->setMotorPower(MOTOR_UP_POWER);
            MotorRF->setMotorPower(MOTOR_UP_POWER);
            MotorLB->setMotorPower(MOTOR_UP_POWER);
            MotorLF->setMotorPower(MOTOR_UP_POWER);
        } 
        else if (cmd == "DOWN") 
        {
            Gps->updatePosition(0, 0, MOVE_DOWN);
            MotorRB->setMotorPower(MOTOR_DOWN_POWER);
            MotorRF->setMotorPower(MOTOR_DOWN_POWER);
            MotorLB->setMotorPower(MOTOR_DOWN_POWER);
            MotorLF->setMotorPower(MOTOR_DOWN_POWER);
        }
    });

    while (true)
    {
        int key = _getch();
        if (key == 'q' || key == 'Q')
        {
            StopDrone(*Gps, *MotorRB, *MotorLB, *MotorRF, *MotorLF);
            break;
        }

        std::string message = proxy.handleInput(key);
        std::cout << message << "\n";

        std::cout << "Position: x=" << Gps->getX()
                  << " y=" << Gps->getY()
                  << " Height=" << Gps->getHeight() << "\n";
        std::cout << "Motors - RB: " << MotorRB->getMotorPower() 
                  << " LB: " << MotorLB->getMotorPower()
                  << " RF: " << MotorRF->getMotorPower()
                  << " LF: " << MotorLF->getMotorPower() << "\n";
    }

    return 0;
}

void StartDrone(IGps& gps, IMotor& MotorRB, IMotor& MotorLB, IMotor& MotorRF, IMotor& MotorLF)
{
    std::cout << "Drone starting up \n";
    MotorRB.setMotorPower(MOTOR_STARTUP_POWER);
    MotorLB.setMotorPower(MOTOR_STARTUP_POWER);
    MotorRF.setMotorPower(MOTOR_STARTUP_POWER);
    MotorLF.setMotorPower(MOTOR_STARTUP_POWER);
    std::cout   << "Motors - RB: " << MotorRB.getMotorPower()
                << " LB: " << MotorLB.getMotorPower()
                << " RF: " << MotorRF.getMotorPower()
                << " LF: " << MotorLF.getMotorPower() << "\n";
    Sleep(1000);
    MotorRB.setMotorPower(MOTOR_FLOATING_POWER);
    MotorLB.setMotorPower(MOTOR_FLOATING_POWER);
    MotorRF.setMotorPower(MOTOR_FLOATING_POWER);
    MotorLF.setMotorPower(MOTOR_FLOATING_POWER);
    gps.updatePosition(0, 0, 5);
    std::cout << "Drone has reached starting position: x=" << gps.getX()
              << " y=" << gps.getY()
              << " Height=" << gps.getHeight() << "\n";
    std::cout   << "Motors - RB: " << MotorRB.getMotorPower()
                << " LB: " << MotorLB.getMotorPower()
                << " RF: " << MotorRF.getMotorPower()
                << " LF: " << MotorLF.getMotorPower() << "\n";
}

void StopDrone(IGps& gps, IMotor& MotorRB, IMotor& MotorLB, IMotor& MotorRF, IMotor& MotorLF)
{
    std::cout << "Drone starting to land \n";
    MotorRB.setMotorPower(MOTOR_LANDING_POWER);
    MotorLB.setMotorPower(MOTOR_LANDING_POWER);
    MotorRF.setMotorPower(MOTOR_LANDING_POWER);
    MotorLF.setMotorPower(MOTOR_LANDING_POWER);
    std::cout   << "Motors - RB: " << MotorRB.getMotorPower()
                << " LB: " << MotorLB.getMotorPower()
                << " RF: " << MotorRF.getMotorPower()
                << " LF: " << MotorLF.getMotorPower() << "\n";
    Sleep(1000);
    std::cout << "Drone has landed\n";
    MotorRB.setMotorPower(MOTOR_OFF);
    MotorLB.setMotorPower(MOTOR_OFF);
    MotorRF.setMotorPower(MOTOR_OFF);
    MotorLF.setMotorPower(MOTOR_OFF);
    std::cout   << "Motors - RB: Off LB: Off RF: Off LF: Off\n";
    gps.landing();
    std::cout << "Landing position: X=" << gps.getX()
              << " Y=" << gps.getY()
              << " Height=" << gps.getHeight() << "\n";
}