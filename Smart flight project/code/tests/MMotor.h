#ifndef MMOTOR_H
#define MMOTOR_H

#include "IMotor.h"

#include <gmock/gmock.h>

class MMotor : public IMotor 
{
public:
	MOCK_METHOD1(setMotorPower, void(int power));
	MOCK_CONST_METHOD0(getMotorPower, int());
};

#endif
