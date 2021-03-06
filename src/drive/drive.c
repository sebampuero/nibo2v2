
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



/*
 * @brief sets the nibo in backwards mode temporarily
 */
void backwards_mode(){
	sendCmd(backwards+'0'); //send a signal to the pc
	while(side_sensors_too_close()){
		all_blocked();
		copro_update();
		copro_setSpeed(-10,-10);
	}
	delay(1500);
	all_leds_off();
	copro_stop();
	if(is_left_side_too_close()){
		//turn right
		sendCmd(right+'0');
		drive_turn_right();
		going_right();
	}else if(is_right_side_too_close()){
		//turn left
		sendCmd(left+'0');
		drive_turn_left();
		going_left();
	}
	delay(2000);
}

/*
 * @brief Drives the nibo automatically avoiding obstacles using its IR-Distance Sensors
 */
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
		if(side_sensors_too_close()){
			backwards_mode();
		}
		else if(is_left_side_too_close()){
			//turn right
			sendCmd(half_right+'0');
			drive_turn_halfRight();
			going_right();
		}else if(is_right_side_too_close()){
			//turn left
			sendCmd(half_left+'0');
			drive_turn_halfLeft();
			going_left();
		}
		delay(1500);
	}
	else if(copro_distance[FRONT_LEFT]/256 > T_SIDES){
		//if the nibo approaches a wall to the side, avoid it calculating the corresponding speed
		//for each wheel of the nibo
		r = (copro_distance[FRONT_LEFT]/256) / 22; //ritchie 22  / 12
		l = (copro_distance[FRONT_LEFT]/256) / 12; // jul e
		copro_setSpeed(l,r);
		going_half_right();
	}
	else if(copro_distance[FRONT_RIGHT]/256 > T_SIDES){
		//if the nibo approaches a wall to the side, avoid it calculating the corresponding speed
		//for each wheel of the nibo
		r = (copro_distance[FRONT_RIGHT]/256) / 12; //ritchie 22 / 12
		l = (copro_distance[FRONT_RIGHT]/256) / 22; //jul e
		copro_setSpeed(l,r);
		going_half_left();
	}
}

/*
 * @brief Evaluates if side sensors are too close
 * @return true if they are too close, false otherwise
 */
uint8_t side_sensors_too_close(){
	copro_update();
	if(copro_distance[LEFT_SIDE]/256 > T_SIDES_90 && copro_distance[RIGHT_SIDE]/256 > T_SIDES_90){
		return 1;
	}else{
		return 0;
	}
}

/*
 * @brief Evaluates if the left sensor is too close
 * @return true if it is too close, false otherwise
 */
uint8_t is_left_side_too_close(){
	copro_update();
	if(copro_distance[LEFT_SIDE]/256 > copro_distance[RIGHT_SIDE]/256){
		return 1;
	}else{
		return 0;
	}
}

/*
 * @brief Evaluates if the right sensor is too close
 * @return true if it is too close, false otherwise
 */
uint8_t is_right_side_too_close(){
	copro_update();
	if(copro_distance[RIGHT_SIDE]/256 > copro_distance[LEFT_SIDE]/256){
		return 1;
	}else{
		return 0;
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
	copro_setTargetRel(-13, 13, 10);
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
	copro_setTargetRel(13, -13, 10);
}

/**
 @brief turns the nibo 180 degree to the left
 */

void drive_turn_around(){
	copro_setTargetRel(-53, 53, 10);
}

/*
 * @brief Drives the Nibo forward with a given speed
 * @param speed the speed the nibo drives at
 * @return true if the nibo drives without encountering an obstacle, false otherwise
 */
uint8_t drive_forward(uint8_t speed){
	copro_setSpeed(speed,speed);
	copro_update();
	if(copro_distance[FRONT]/256 > 200 || copro_distance[FRONT_LEFT]/256 > 200
			|| copro_distance[FRONT_RIGHT]/256 > 200){
		return 0;
	}else{
		return 1;
	}
}

/*
 * @brief Stops the nibo instantly and completely
 */
void stop_completely(){
	copro_stop();
}
