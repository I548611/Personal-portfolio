#include "drone.h"

#include "MGps.h"
#include "MMotor.h"
#include "../fakeGps.h"

using ::testing::InSequence;
using ::testing::_;

#include <gtest/gtest.h>

class DroneTest : public ::testing::Test
{
protected:
    DroneTest() {}
    virtual ~DroneTest() {}

    MGps gps;
    MMotor MotorRB;
    MMotor MotorLB;
    MMotor MotorRF;
    MMotor MotorLF;
};

TEST_F(DroneTest, StartDrone_startup_test)
{
    EXPECT_CALL(MotorRB, setMotorPower(MOTOR_STARTUP_POWER));
    EXPECT_CALL(MotorLB, setMotorPower(MOTOR_STARTUP_POWER));
    EXPECT_CALL(MotorRF, setMotorPower(MOTOR_STARTUP_POWER));
    EXPECT_CALL(MotorLF, setMotorPower(MOTOR_STARTUP_POWER));

    EXPECT_CALL(MotorRB, setMotorPower(MOTOR_FLOATING_POWER));
    EXPECT_CALL(MotorLB, setMotorPower(MOTOR_FLOATING_POWER));
    EXPECT_CALL(MotorRF, setMotorPower(MOTOR_FLOATING_POWER));
    EXPECT_CALL(MotorLF, setMotorPower(MOTOR_FLOATING_POWER));

    EXPECT_CALL(gps, updatePosition(0, 0, 5));

    StartDrone(gps, MotorRB, MotorLB, MotorRF, MotorLF);
}

TEST_F(DroneTest, StopDrone_landing_test)
{
    EXPECT_CALL(MotorRB, setMotorPower(MOTOR_LANDING_POWER));
    EXPECT_CALL(MotorLB, setMotorPower(MOTOR_LANDING_POWER));
    EXPECT_CALL(MotorRF, setMotorPower(MOTOR_LANDING_POWER));
    EXPECT_CALL(MotorLF, setMotorPower(MOTOR_LANDING_POWER));

    EXPECT_CALL(MotorRB, setMotorPower(MOTOR_OFF));
    EXPECT_CALL(MotorLB, setMotorPower(MOTOR_OFF));
    EXPECT_CALL(MotorRF, setMotorPower(MOTOR_OFF));
    EXPECT_CALL(MotorLF, setMotorPower(MOTOR_OFF));

    EXPECT_CALL(gps, landing());

    StopDrone(gps, MotorRB, MotorLB, MotorRF, MotorLF);
}

TEST(DroneTest, Initial_Value_Test)
{
    fakeGps g;
    EXPECT_EQ(0, g.getX());
    EXPECT_EQ(0, g.getY());
    EXPECT_EQ(0, g.getHeight());
}

TEST(DroneTest, Update_Position_Applies_Changes_Test)
{
    fakeGps g;
    g.updatePosition(64, 98, 12);
    EXPECT_EQ(64, g.getX());
    EXPECT_EQ(98, g.getY());
    EXPECT_EQ(12, g.getHeight());
}

TEST(DroneTest, Enforce_Min_Height_Test)
{
    fakeGps g;
    g.updatePosition(0, 0, -5);
    EXPECT_EQ(5, g.getHeight());
}

TEST(DroneTest, Landing_Coordinates_Test)
{
    fakeGps g;
    g.updatePosition(12, 12, 10);
    g.landing();

    EXPECT_EQ(12, g.getX());
    EXPECT_EQ(12, g.getY());
    EXPECT_EQ(0, g.getHeight());
}