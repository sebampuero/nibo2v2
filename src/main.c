/**
 * @file		main.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Main Programm
 */
#include "main.h"
uint8_t mode = nibo_auto;
uint8_t last_cmd = 15;
uint8_t drive_result;
uint8_t auto_flag = 0;

void init(){
	sei();
	bot_init();
	spi_init();
	leds_init();
	pwm_init();
	display_init();
	gfx_init();
	copro_ir_startMeasure();
}
char text[20] = "";

int main(){

	init();
	initUART0();
	displayInit();
	printVoltage();
	while (1)
	{
		while(mode == nibo_auto){
			drive_auto();
			delay(100);
		}//manual mode
		while(mode == nibo_manual){
			sendCmd(0x00);
			while((last_cmd=getCmd())==0);
			sprintf(text,"CMD: %d",last_cmd);
			appendLine(text);
			if(last_cmd==nibo_auto){
				mode = nibo_auto;
			}else if(last_cmd == nibo_forward){
				while(drive_forward(15));
			}else if(last_cmd == nibo_left){
				drive_turn_left();
				going_left();
				delay(500);
				all_leds_off();
			}else if(last_cmd == nibo_right){
				drive_turn_right();
				going_right();
				delay(500);
				all_leds_off();
			}else if(last_cmd == nibo_half_left){
				drive_turn_halfLeft();
				going_left();
				delay(500);
				all_leds_off();
			}else if(last_cmd == nibo_half_right){
				drive_turn_halfRight();
				going_right();
				delay(500);
				all_leds_off();
			}else if(last_cmd == nibo_turn_around){
				drive_turn_around();
			}else if(last_cmd == nibo_print_voltage){
				printVoltage();
			}
		}

	}

	return 0;
}

void drive_auto(){
	if(s3_was_pressed()){
		if(auto_flag == 1){
			auto_flag = 0;
			mode = nibo_manual;
			appendLine("MANUAL MODE");
			stop_completely();
			return;
		}else{
			auto_flag = 1;
	     	mode = nibo_auto;
			appendLine("AUTO MODE");
			return;
			}
		}
	auto_mode_drive();
}

