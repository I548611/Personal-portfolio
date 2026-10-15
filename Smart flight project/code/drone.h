#ifndef DRONE_H
#define DRONE_H

#include "IGps.h"
#include "IMotor.h"

#define MOVE_FORWARD 1
#define MOVE_BACKWARD -1
#define MOVE_RIGHT 1
#define MOVE_LEFT -1
#define MOVE_UP 1
#define MOVE_DOWN -1

#define STRONG_MOTOR_POWER_FORWARD 50
#define SOFT_MOTOR_POWER_FORWARD 25

#define STRONG_MOTOR_POWER_BACKWARD 50
#define SOFT_MOTOR_POWER_BACKWARD 25

#define STRONG_MOTOR_POWER_LEFT 50
#define SOFT_MOTOR_POWER_LEFT 25

#define STRONG_MOTOR_POWER_RIGHT 50
#define SOFT_MOTOR_POWER_RIGHT 25

#define MOTOR_UP_POWER 50

#define MOTOR_DOWN_POWER 10

#define MOTOR_STARTUP_POWER 40

#define MOTOR_FLOATING_POWER 20

#define MOTOR_LANDING_POWER 5

#define MOTOR_OFF 0

void StartDrone(IGps& gps, IMotor& MotorRB, IMotor& MotorLB, IMotor& MotorRF, IMotor& MotorLF);
void StopDrone(IGps& gps, IMotor& MotorRB, IMotor& MotorLB, IMotor& MotorRF, IMotor& MotorLF);

#endif
