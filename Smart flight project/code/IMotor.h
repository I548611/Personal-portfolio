#ifndef IMOTOR_H
#define IMOTOR_H
#include <memory>

class IMotor
{
public:
    virtual ~IMotor() = default;
    virtual void setMotorPower(int power) = 0;
    virtual int getMotorPower() const = 0;
};

std::unique_ptr<IMotor> createMotor();

#endif
