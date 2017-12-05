/**
 * @file		main.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Main Programm
 */
#include "main.h"
uint8_t last_cmd;
uint8_t auto_flag = 1;
enum modes nibo_mode;

/*
 * @brief Initialize all needed components of the nibo
 */
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

int main(){
	nibo_mode = autonom;
	init();
	initUART0();
	displayInit();
	printVoltage();
	appendLine("Initisialitierung NXB2...");
	delay(10000);
	appendLine("NIBO Ready");
	while (1)
	{
		while(nibo_mode == autonom){
			drive_auto();
			delay(100);
		}//manual mode
		while(nibo_mode == manual){
			stop_completely();
			sendCmd(manual+'0'); //let the pc know the nibo is requesting commands
			while((last_cmd=getCmd())==255); //wait until a signal from pc comes
			if(last_cmd==autonom){
				nibo_mode = autonom;
				auto_flag = 1;
				appendLine("AUTO MODE");
			}else if(last_cmd == forward){
				while(drive_forward(15));
			}else if(last_cmd == left){
				drive_turn_left();
				going_left();
				delay(1800);
				all_leds_off();
			}else if(last_cmd == right){
				drive_turn_right();
				going_right();
				delay(1800);
				all_leds_off();
			}else if(last_cmd == half_left){
				drive_turn_halfLeft();
				going_left();
				delay(1500);
				all_leds_off();
			}else if(last_cmd == half_right){
				drive_turn_halfRight();
				going_right();
				delay(1500);
				all_leds_off();
			}else if(last_cmd == backwards){
				drive_turn_around();
				delay(3000);
			}else if(last_cmd == voltage){
				printVoltage();
			}
		}

	}

	return 0;
}

/*
 * @brief activates auto mode driving for the nibo
 */
void drive_auto(){
	if(s3_was_pressed()){
		if(auto_flag == 1){
			auto_flag = 0;
			nibo_mode = manual;
			appendLine("MANUAL MODE");
			stop_completely();
			return;
		}
	}
	auto_mode_drive();
}

