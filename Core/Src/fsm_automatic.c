/*
 * fsm_automatic.c
 *
 *  Created on: Dec 5, 2022
 *      Author: DELL
 */

#include "fsm_automatic.h"

void fsm_automatic_run1(){
	switch(status){
	case INIT:
		status = AUTO_RED;
		setTimer1(5000);
		break;
	case AUTO_RED:
		setLed1(RED);
		setLed_Pedes(GREEN);
		status = AUTO_GREEN;
		setTimer1(3000);
		if(timer1_counter = 2000)
		{
			buzzer();
		}
		if(tim)
		break;
	case AUTO_YELLOW:
		setLed2(YELLOW);
		setLed_Pedes(RED);
		status = AUTO_RED;
		setTimer1(2000);
		break;
	case AUTO_GREEN:
		setLed1(GREEN);
		setLed_Pedes(RED);
		status = INIT;
		break;
	}
}

void fsm_automatic_run2(){
	switch(status){
	case INIT:
		status = AUTO_GREEN;
		setTimer1(3000);
		break;
	case AUTO_RED:
		setLed2(RED);
		status = AUTO_GREEN;
		setTimer1(3000);
		break;
	case AUTO_YELLOW:
		setLed2(YELLOW);
		status = AUTO_RED;
		setTimer1(2000);
		break;
	case AUTO_GREEN:
		setLed2(GREEN);
		status = AUTO_RED;
		setTimer1(5000);
		break;
	}
}
