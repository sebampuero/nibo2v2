/**
 * @file		xbee.h
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Header file Library for wireless communication
 */
#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>
#include <nibo/display.h>
#include <nibo/gfx.h>
#include <nibo/copro.h>
#include <stdio.h>
#include <stdint.h>
#include "uart0.h"
#include <nibo/delay.h>
#include <nibo/spi.h>
#include <avr/interrupt.h>

#define default_baudrate 9600

#define nibo_manual 1
#define nibo_auto 2
#define nibo_forward 3
#define nibo_turn_around 4
#define nibo_half_right 5
#define nibo_half_left 6
#define nibo_right 7
#define nibo_left 8
#define nibo_print_voltage 9

void initUART0();

void sendCmd(uint8_t c);

uint8_t getCmd();

