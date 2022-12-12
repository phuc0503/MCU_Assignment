/*
 * fsm_setTime.c
 *
 *  Created on: Dec 12, 2022
 *      Author: DELL
 */

#include "fsm_setTime.h"

void checkbutton3()
{
    if(isButtonPressed(1))
    {
        status = INIT;
        status1 = INIT;
    }
}

void fsm_setTime_run()
{
    switch(status){
    case TIME_CHANGE:
        status = TIME_RED;
        setTimer1(500);
        setLed1(OFF);
        setLed2(OFF);
        setLed_Pedes(OFF);
        break;

    case TIME_RED:
        checkbutton3();
        if(isButtonPressed(0)){
        	status = TIME_GREEN;
        	setLed1(OFF);
        	setLed2(OFF);
        	setLed_Pedes(OFF);
        }
        //TODO
        if(timer1_flag == 1)
        {
        	setLed1(SETTING_RED);
        	setLed2(SETTING_RED);
            setTimer1(500);
        }
        if(isButtonPressed(2)){
        	if(red_init == 20){
        		red_init = 1;
        	}else{
        		red_init++;
        	}
        }
        if(isButtonPressed(3)){
        	if(red_init == 1){
        		red_init = 20;
        	}else{
        		red_init--;
        	}
        }
        break;

    case TIME_GREEN:
    	checkbutton3();
    	if(isButtonPressed(0)){
			status = TIME_YELLOW;
			setLed1(OFF);
			setLed2(OFF);
			setLed_Pedes(OFF);
		}
    	//TODO
        if(timer1_flag == 1)
        {
        	setLed1(SETTING_GREEN);
        	setLed2(SETTING_GREEN);
            setTimer1(500);
        }
        if(isButtonPressed(2)){
			if(green_init == 20){
				green_init = 1;
			}else{
				green_init++;
			}
		}
		if(isButtonPressed(3)){
			if(green_init == 1){
				green_init = 20;
			}else{
				green_init--;
			}
		}
        break;
    case TIME_YELLOW:
    	checkbutton3();
		if(isButtonPressed(0)){
			status = TIME_RED;
			setLed1(OFF);
			setLed2(OFF);
			setLed_Pedes(OFF);
		}
		//TODO
        if(timer1_flag == 1)
        {
        	setLed1(SETTING_YELLOW);
			setLed2(SETTING_YELLOW);
            setTimer1(500);
        }
        if(isButtonPressed(2)){
			if(yellow_init == 20){
				yellow_init = 1;
			}else{
				yellow_init++;
			}
		}
		if(isButtonPressed(3)){
			if(yellow_init == 1){
				yellow_init = 20;
			}else{
				yellow_init--;
			}
		}
        break;
    }
}
