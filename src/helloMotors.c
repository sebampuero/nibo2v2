#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>
#include <nibo/display.h>
#include <nibo/gfx.h>
#include <nibo/delay.h>
#include <nibo/copro.h>
#include <nibo/spi.h>
#include <avr/interrupt.h>
#include <stdio.h>

#define FRONT_LEFT       1

#define FRONT_RIGHT      3

#define FRONT      2

#define LEFT_SIDE  0

#define RIGHT_SIDE 4

#define T_FRONT    150

#define T_SIDES    160

#define T_SIDES_90 120

char output[20] = "";
int current_distance = 0;
int distance = 0;
int r = 0;
int l = 0;
void init(){
	sei();
	bot_init();
	spi_init();
	display_init();
	gfx_init();
	copro_ir_startMeasure();
}

void distances(){
	gfx_fill(0);
	gfx_move(0, 0);
	gfx_print_text("Distanzen");
	copro_update();
	current_distance = copro_distance[0]/256;
	sprintf(output, "%3i ", current_distance);
	gfx_move(0, 10);
	gfx_print_text(output);
	for(int i = 1; i < 5; i++){
	   	current_distance = copro_distance[i]/256;
	    sprintf(output, "%3i", current_distance);
		gfx_move(23*i, 10);
		gfx_print_text(output);
	}
}
void backwards_mode(){
	while(copro_distance[LEFT_SIDE]/256 > T_SIDES_90 && copro_distance[RIGHT_SIDE]/256 > T_SIDES_90){
		copro_update();
		copro_setSpeed(-10,-10);
	}
	delay(1500);
	copro_stop();
	if((copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256) >
		(copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256)){
		//turn left
		copro_setTargetRel(-27,27,10);
	}else if((copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256) >
		(copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256)){
		//turn right
		copro_setTargetRel(27,-27,10);
	}
	delay(2000);
}


void check_sensors(){
	copro_update();
	for(int i=0;i<5;i++){
		distance = copro_distance[i]/256;
		if(distance < 150){
			copro_setSpeed(14,14);
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
		}else if((copro_distance[FRONT_RIGHT]/256) + (copro_distance[RIGHT_SIDE]/256) >
		(copro_distance[FRONT_LEFT]/256) + (copro_distance[LEFT_SIDE]/256)){
			//turn right
			copro_setTargetRel(20,-20,12);
		}
		delay(1700);
	}
	else if(copro_distance[FRONT_LEFT]/256 > T_SIDES){
		r = (copro_distance[FRONT_LEFT]/256) / 8;
		l = (copro_distance[FRONT_LEFT]/256) / 19;
		copro_setSpeed(l,r);
	}
	else if(copro_distance[FRONT_RIGHT]/256 > T_SIDES){
		r = (copro_distance[FRONT_RIGHT]/256) / 19;
		l = (copro_distance[FRONT_RIGHT]/256) / 8;
		copro_setSpeed(l,r);
	}
}

int main(){
	init();
	while(1){
		distances();
		check_sensors();
		delay(100);
	}
}
