/*
 * global.h
 *
 *  Created on: Dec 5, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "led_color.h"
#include "fsm_manual.h"

#define INIT 			1
#define AUTO_RED 		2
#define AUTO_YELLOW		3
#define AUTO_GREEN		4
#define PEDES			5
#define MANUAL			6
#define MAN_RED			7
#define MAN_GREEN		8
#define MAN_YELLOW		9
#define TIME_CHANGE     10
#define TIME_RED        12
#define TIME_GREEN      13
#define TIME_YELLOW     14
#define WAITTING		15

#define RED				20
#define YELLOW			21
#define GREEN			22
#define OFF				23
#define SETTING_RED		24
#define SETTING_GREEN 	25
#define SETTING_YELLOW	26

extern int color;
extern int status;
extern int status1;
extern int timer1_counter;
extern int timer1_flag;
//extern int check;
extern int timer_counter;
extern int red_init;
extern int green_init;
extern int yellow_init;
#endif /* INC_GLOBAL_H_ */
