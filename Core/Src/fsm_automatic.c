/*
 * fsm_automatic.c
 *
 *  Created on: Dec 5, 2022
 *      Author: DELL
 */

#include "fsm_automatic.h"

void checkbutton()
{
	if(isButtonPressed(1))
	{
		status = MANUAL;
		status1 = MANUAL;
	}
//	if(isButtonPressed(0)){
//		setLed_Pedes(GREEN);
//	}
}

void fsm_automatic_run1(){
	switch(status){
	case INIT:
		status = AUTO_RED;
		setTimer1(red_init*1000);
		break;
	case AUTO_RED:
		if(timer1_flag == 1)
		{
			status = AUTO_GREEN;
			setTimer1(green_init*1000);
		}
		if(timer1_counter == 2000)
		{
			setTimer3(500);
			buzzer();
		}
		if(timer1_counter < 2000)
		{
			buzzer();
		}
		setLed1(RED);
		setLed_Pedes(GREEN);
		checkbutton();
		break;
	case AUTO_YELLOW:
		if(timer1_flag == 1)
		{
			status = AUTO_RED;
			setTimer1(red_init*1000);
		}
		// To Do
		setLed1(YELLOW);
		setLed_Pedes(RED);
		checkbutton();
		break;
	case AUTO_GREEN:
		if(timer1_flag == 1)
		{
			status = AUTO_YELLOW;
			setTimer1(yellow_init*1000);
		}
		setLed1(GREEN);
		setLed_Pedes(RED);
		checkbutton();
		break;
	case MANUAL:
		if(isButtonPressed(1))
		{
			status = INIT;
			status1 = INIT;
		}
		break;
	}
}

void fsm_automatic_run2(){
	switch(status1){
	case INIT:
		status1 = AUTO_GREEN;
		setTimer2(green_init*1000);
		break;
	case AUTO_RED:
		if(timer2_flag == 1)
		{

			status1 = AUTO_GREEN;
			setTimer2(green_init*1000);
		}
		setLed2(RED);
		break;
	case AUTO_YELLOW:
		if(timer2_flag == 1)
		{

			status1 = AUTO_RED;
			setTimer2(red_init*1000);
		}
		setLed2(YELLOW);
		break;
	case AUTO_GREEN:
		if(timer2_flag == 1)
		{

			status1 = AUTO_YELLOW;
			setTimer2(yellow_init*1000);
		}
		setLed2(GREEN);
		break;
	case MANUAL:
		setLed2(OFF);
		break;
	}
}
