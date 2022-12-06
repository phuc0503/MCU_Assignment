/*
 * led_color.c
 *
 *  Created on: Dec 6, 2022
 *      Author: DELL
 */

#include "led_color.h"

void setLed1(int color){
	switch(color){
	case RED:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, RESET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, SET);
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
		break;
	}
}

void setLed2(int color){
	switch(color){
	case RED:
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
	case YELLOW:
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
		break;
	}
}

void setLed_Pedes(int color)
{
	switch(color){
	case RED:
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
		break;
	case GREEN:
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
		break;
	}
}

void buzzer()
{
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 10);
	HAL_Delay(1000);
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 100);
}
