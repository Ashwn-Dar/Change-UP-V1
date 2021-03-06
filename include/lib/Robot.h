#include "main.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#ifndef ROBOT_H
#define ROBOT_H

using namespace pros; 

int sgn(int x);
// REDACTED: void driveVoltageAssign(int rightPower, int leftPower);
void moveChassis(int rightSidePower, int leftSidePower); 
void moveIntake(int rightSidePower, int leftSidePower);
void moveFlywheel(int uptakePower, int flyWheelPower); 


#define DEGREES E_MOTOR_ENCODER_DEGREES
#define GREEN E_MOTOR_GEARSET_18
#define RED E_MOTOR_GEARSET_36
#define DRIVE_RIGHT_1 1 
#define DRIVE_LEFT_1 3
#define DRIVE_RIGHT_2 2
#define DRIVE_LEFT_2 4

#define LIFT_LEFT 10
#define LIFT_RIGHT 9

#define INTAKE_RIGHT 12
#define INTAKE_LEFT 11

#define ENC_RIGHT 'a'
#define ENC_LEFT 'c'
#define LINE_SENSOR_1 'e'
#define LINE_SENSOR_2 'f'

extern Controller joystick;
extern Motor rm1; 
extern Motor rm2; 
extern Motor lm1; 
extern Motor lm2; 

extern Motor liftL, liftR; 
extern Motor intakeL, intakeR; 

extern ADIEncoder rEnc;
extern ADIEncoder lEnc; 
extern Imu mainIMU; 




#endif
