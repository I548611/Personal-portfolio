#include "Motor.h"

#include <memory>

Motor::Motor()
    : power(MIN_POWER)
{
}

void Motor::setMotorPower(int power)
{
    if (power < MIN_POWER)
        this->power = MIN_POWER;
    else if (power > MAX_POWER)
        this->power = MAX_POWER;
    else
        this->power = power;
}

int Motor::getMotorPower() const
{
    return power;
}

std::unique_ptr<IMotor> createMotor()
{
    return std::make_unique<Motor>();
}