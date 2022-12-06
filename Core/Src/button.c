/*
 * button.c
 *
 *  Created on: Dec 6, 2022
 *      Author: DELL
 */
#include "button.h"

int KeyBuffer1[NUMBER_OF_BUTTONS];
int KeyBuffer2[NUMBER_OF_BUTTONS];
int KeyBuffer3[NUMBER_OF_BUTTONS];
int KeyBuffer4[NUMBER_OF_BUTTONS];

int flagForButtons[NUMBER_OF_BUTTONS];
int flagForButtonsLongPressed[NUMBER_OF_BUTTONS];
int timerForKeyPress[NUMBER_OF_BUTTONS] = {300, 300, 300, 300};

int isButtonPressed(int index){
	if(index > NUMBER_OF_BUTTONS){
		return 0;
	}
	if(flagForButtons[index] == 1){
		flagForButtons[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int index){
	if(index > NUMBER_OF_BUTTONS){
		return 0;
	}
	if(flagForButtonsLongPressed[index] == 1){
		flagForButtonsLongPressed[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for(int i = 0; i < NUMBER_OF_BUTTONS; i++){
		KeyBuffer1[i] = KeyBuffer2[i];
		KeyBuffer2[i] = KeyBuffer3[i];
		switch(i){
		//Button 1
		case 0:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(B1_GPIO_Port,	B1_Pin);
			break;
		//Button 2
		case 1:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(B2_GPIO_Port, B2_Pin);
			break;
		//Button 3
		case 2:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(B3_GPIO_Port, B3_Pin);
			break;
		//Pedestrian button
		case 3:
			KeyBuffer3[i] = HAL_GPIO_ReadPin(B0_GPIO_Port, B0_Pin);
			break;
		default:
			break;
		}
		if((KeyBuffer1[i] == KeyBuffer2[i]) && (KeyBuffer2[i] == KeyBuffer3[i])){
			if(KeyBuffer3[i] != KeyBuffer4[i]){
				KeyBuffer4[i] = KeyBuffer3[i];

				if(KeyBuffer3[i] == PRESSED_STATE){
					timerForKeyPress[i] = 300;
					flagForButtons[i] = 1;
				}
			}else{
				timerForKeyPress[i]--;
				if(timerForKeyPress[i] == 0){
					if(KeyBuffer3[i] == PRESSED_STATE){
						flagForButtons[i] = 1;
						flagForButtonsLongPressed[i] = 1;
					}
					timerForKeyPress[i] = 100;
				}
			}
		}
	}
}
