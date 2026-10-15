#ifndef MOTOR_H
#define MOTOR_H

#include "IMotor.h"

#define MAX_POWER 100
#define MIN_POWER 0

class Motor : public IMotor
{
public:
    Motor();
    void setMotorPower(int power) override;
    int getMotorPower() const override;

private:
    int power;
};
#endif
