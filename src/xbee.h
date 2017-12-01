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

enum modes {manual, autonom, forward, backwards, half_right, half_left, right, left, voltage };

void initUART0();

void sendCmd(char c);

uint8_t getCmd();

