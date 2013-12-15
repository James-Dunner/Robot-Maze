#include <msp430.h>
#include "sensor_library.h"
#include "robot_motion_library.h"

/*
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;										// Stop watchdog timer
	
    initRobot();

    clearLeftMotor();
    clearRightMotor();

    P1DIR |= BIT0;

    while(1)
    {
    	if(wallLeftDetected() == 0)
    	{
    		bigLeftTurn();
    		_delay_cycles(20000);
    	}

    	if(wallLeftDetected() == 1)
    	{
    		bigRightTurn();
    		_delay_cycles(20000);
    	}

    	if(wallFrontDetected() == 1 && wallLeftDetected() == 1)
    	{
    		_delay_cycles(50000);
    		stopBothMotors();
    		smallRightTurn();
    		_delay_cycles(500000);
    	}

    	else
    	{
    		moveForward();
    	}
    }
}

