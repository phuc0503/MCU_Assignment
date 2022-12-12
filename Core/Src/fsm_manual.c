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

void fsm_manual_run()
{
    switch(status){
    case MANUAL:
        status = MAN_RED;
        setLed1(RED);
		setLed2(GREEN);
        break;

    case MAN_RED:
        if(isButtonPressed(2)){
            status = MAN_GREEN;
            setTimer1(3000);
            setLed2(YELLOW);
        }
        //TODO
        checkbutton2();
        if(timer1_flag == 1){
        	setLed1(RED);
        }
        setLed2(GREEN);
        setLed_Pedes(GREEN);
        break;

    case MAN_GREEN:
    	if(isButtonPressed(2)){
			status = MAN_RED;
			setTimer1(3000);
			setLed1(YELLOW);
		}
    	//TODO
    	checkbutton2();
    	setLed1(GREEN);
    	if(timer1_flag == 1){
    		setLed2(RED);
    	}
        setLed_Pedes(RED);
        break;
    }
}


