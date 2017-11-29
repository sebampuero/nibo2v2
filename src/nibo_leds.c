/**
 * @file		nibo_leds.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Library for leds display according to function of nibo
 */
#include "nibo_leds.h"

void going_front(){
	all_leds_off();
	leds_set_headlights(1024);
}

void going_right(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,7);
}

void going_left(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,2);
}

void all_blocked(){
	int i;
	for(i = 2; i <= 7; i++){
		leds_set_status(LEDS_RED,i);
	}
}

void going_half_left(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,3);
}

void going_half_right(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,6);
}

void all_leds_off(){
	int i;
	for(i=1;i<=8;i++){
		leds_set_status(LEDS_OFF,i);
	}
}
