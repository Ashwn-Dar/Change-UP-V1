#include "main.h"
#include "../include/lib/drive.h"

namespace drive{

float powerSpline(float axisInput){
    float denom = (K + A*(std::exp(C*axisInput)));
    float y = (1/denom);
    return float(y);
}

void operatorControl(bool usingSpline = false){
    int rightAxis = joystick.get_analog(ANALOG_RIGHT_Y);
    int leftAxis = joystick.get_analog(ANALOG_LEFT_Y);
    int rightPower, leftPower;
    
    if(usingSpline){
        if(abs(joystick.get_analog(ANALOG_RIGHT_Y)) > 2)
            rightPower = (powerSpline(rightAxis) - powerSpline(0));
        if(abs(joystick.get_analog(ANALOG_LEFT_Y)) > 2)
            leftPower = (powerSpline(leftAxis) - powerSpline(0));
        else leftPower = 0; 
            driveVoltageAssign(rightPower*95, leftPower*95);
    } 
    else if(!usingSpline){   
        rightPower = rightAxis * 110; 
        leftPower = leftAxis * 110; 
        driveVoltageAssign(rightPower, leftPower);
        }
    }
    //WILL FORMAT LATER // TEMP
    class Drive : public PID : public LinearOdometry{ 
        public: 
            int16_t rightSet, leftSet; 
            int16_t thetaSet; 
            Drive() : rightSet(0), leftSet(0), thetaSet(0);
            void moveRelative(int linearTarget){
                rightSet += linearTarget;
                leftSet += linearTarget;
            }
            void turnRelative(int degrees){
                thetaSet += degrees; 
            }
            void iterate(){
                int rightPidPower = calc(rightSet, rightMotor.get_value()); 
                int leftPidPower = calc(leftSet, leftMotor.get_value()); 
                
                pros::delay( 25 ); 
                
                if(slew) { 
                    int newRPid = calc(rightSet, rightMotor.get_value() ); 
                    int newLPid = calc(leftSet, leftMotor.get_value() ); 
                    if ( abs( newRPid - rightPidPower) > SLEW_LIMIT) 
                        rightPidPower += sgn( newRPid - rightPidPower ) * DRIVE_KA;
                        else rightPidPower = newRPid; 
                    if ( abs( newLPid - leftPidPower) > SLEW_LIMIT)
                        leftPidPower += sgn( newLPid - leftPidPower) * DRIVE_KA; 
                        else leftPidPower = newLPid; 
                }
                
                  int thetaCorrect = THETA_GAIN * calc(thetaSet, IMU.get_yaw());
                  driveMove( rightPidPower + thetaCorrect, leftPidPower - thetaCorrect); 

            }
        
    };

}
