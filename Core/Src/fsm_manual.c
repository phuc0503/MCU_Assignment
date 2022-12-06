/*
 * fsm_manual.c
 *
 *  Created on: Dec 6, 2022
 *      Author: DELL
 */

#include "fsm_manual.h"

void fsm_manual_run()
{
	switch(status){
	case MANUAL:
		if(isButtonPressed(2)){
			status = MAN_RED;
		}
		break;

	case MAN_RED:
		if(isButtonPressed(2)){
			status = MAN_GREEN;
		}
		if(isButtonPressed(1))
		{
			status = INIT;
			status1 = INIT;
		}
		setLed1(RED);
		setLed2(GREEN);
		break;

	case MAN_GREEN:
		setLed2(RED);
		setLed1(GREEN);
		if(isButtonPressed(2)){
			status = MAN_RED;
		}
		if(isButtonPressed(1))
		{
			status = INIT;
			status1 = INIT;
		}
		break;

	case MAN_YELLOW:
		break;
	}
}
