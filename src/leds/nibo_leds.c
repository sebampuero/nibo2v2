/**
 * @file		nibo_leds.c
 * @author		Sebastian Ampuero, Tichaona Kadzinga
 * @date		10.11.2017
 * @brief		Library for leds display according to function of nibo
 */


#include "nibo_leds.h"

/*
 * @brief Turn on the headlights, it can be dangerous at night
 */
void going_front(){
	all_leds_off();
	leds_set_headlights(1024);
}
/*
 * @brief Turn on right leds in green when turning 90° to the right
 */
void going_right(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,7);
}
/*
 * @brief Turn on left leds in green when turning 90° to the left
 */
void going_left(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,2);
}
/*
 * @brief Turn on all leds in red when nibo has no escape
 */
void all_blocked(){
	int i;
	for(i = 2; i <= 7; i++){
		leds_set_status(LEDS_RED,i);
	}
}
/*
 * @brief Turn on front-left leds in green when turning 45° to the left
 */
void going_half_left(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,3);
}
/*
 * @brief Turn on front-right leds in green when turning 45° to the right
 */
void going_half_right(){
	all_leds_off();
	leds_set_status(LEDS_GREEN,6);
}

/*
 * @brief Turn off all leds
 */
void all_leds_off(){
	int i;
	for(i=1;i<=8;i++){
		leds_set_status(LEDS_OFF,i);
	}
}


