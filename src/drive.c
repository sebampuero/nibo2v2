
/*
 @file drive.c
 @author Tichaona Kadzinga, Sebastian Ampuero
 @date 12.11.2017
 @brief library for the movement of the nibo2 robot
 */
#include "drive.h"


uint8_t distance = 0;
uint8_t r = 0;
uint8_t l = 0;

void backwards_mode(){
	while(copro_distance[LEFT_SIDE]/256 > T_SIDES_90 && copro_distance[RIGHT_SIDE]/256 > T_SIDES_90){
		all_blocked();
		copro_update();
		copro_setSpeed(-10,-10);
	}
	delay(1500);
	all_leds_off();
	copro_stop();
	if((copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256) >
		(copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256)){
		//turn left
		copro_setTargetRel(-27,27,10);
		going_left();
	}else if((copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256) >
		(copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256)){
		//turn right
		copro_setTargetRel(27,-27,10);
		going_right();
	}
	delay(2000);
}


void auto_mode_drive(){
	copro_update();
	for(int i=0;i<5;i++){
		distance = copro_distance[i]/256;
		if(distance < 150){
			copro_setSpeed(14,14);
			going_front();
		}
	}
	if(copro_distance[FRONT]/256 > T_FRONT){
		copro_stop();
		delay(200);
		if(copro_distance[LEFT_SIDE]/256 > T_SIDES_90 && copro_distance[RIGHT_SIDE]/256 > T_SIDES_90){
			backwards_mode();
		}
		else if((copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256) >
		(copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256)){
			//turn left
			copro_setTargetRel(-20,20,12);
			going_left();
		}else if((copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256) >
		(copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256)){
			//turn right
			copro_setTargetRel(20,-20,12);
			going_right();
		}
		delay(1700);
	}
	else if(copro_distance[FRONT_LEFT]/256 > T_SIDES){
		r = (copro_distance[FRONT_LEFT]/256) / 8;
		l = (copro_distance[FRONT_LEFT]/256) / 19;
		copro_setSpeed(l,r);
		going_half_right();
	}
	else if(copro_distance[FRONT_RIGHT]/256 > T_SIDES){
		r = (copro_distance[FRONT_RIGHT]/256) / 19;
		l = (copro_distance[FRONT_RIGHT]/256) / 8;
		copro_setSpeed(l,r);
		going_half_left();
	}
}



/**
 @brief turns the nibo 90 degrees to the left
 */
void drive_turn_left(){
	copro_setTargetRel(-27, 27, 10);
}

/**
 @brief turns the nibo 45 degrees to the left
 */
void drive_turn_halfLeft(){
	copro_setTargetRel(-8, 10, 10);
}

/**
 @brief turns the nibo 90 degree to the right
 */
void drive_turn_right(){
	copro_setTargetRel(27, -27, 10);
}

/**
 @brief turns the nibo 45 degrees to the right
 */
void drive_turn_halfRight(){
	copro_setTargetRel(10, -8, 10);
}

/**
 @brief turns the nibo 180 degree to the left
 */

void drive_turn_around(){
	copro_setTargetRel(-53, 53, 10);
}

uint8_t drive_forward(uint8_t speed){
	copro_setSpeed(speed,speed);
	if(copro_distance[FRONT]/256 > T_FRONT){
		return 0;
	}else{
		return 1;
	}
}

void stop_completely(){
	copro_stop();
}
