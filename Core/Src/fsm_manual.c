/*
 * fsm_manual.c
 *
 *  Created on: Dec 6, 2022
 *      Author: DELL
 */

#include "fsm_manual.h"

void checkbutton2()
{
	if(isButtonPressed(1))
	{
		status = TIME_CHANGE;
		status1 = TIME_CHANGE;
	}
}
void checkbutton3()
{
	if(isButtonPressed(1))
	{
		status = INIT;
		status1 = INIT;
	}
}

void fsm_manual_run()
{
	switch(status){
	case MANUAL:
		status = MAN_RED;
		break;

	case MAN_RED:
		if(isButtonPressed(2)){
			status = MAN_GREEN;
		}
		checkbutton2();
		setLed1(RED);
		setLed2(GREEN);
		break;

	case MAN_GREEN:
		setLed2(RED);
		setLed1(GREEN);
		if(isButtonPressed(2)){
			status = MAN_RED;
		}
		checkbutton2();
		break;
	}
}

void fsm_time()
{
	switch(status){
	case TIME_CHANGE:
		status = TIME_RED;
		setTimer1(500);
		break;

	case TIME_RED:
		checkbutton3();
		if(timer1_flag == 1)
		{

			setTimer1(500);
		}
		break;

	case TIME_GREEN:
		if(timer1_flag == 1)
		{

			setTimer1(500);
		}
		checkbutton3();
		break;
	case TIME_YELLOW:
		if(timer1_flag == 1)
		{

			setTimer1(500);
		}
		checkbutton3();
		break;
	}
}
