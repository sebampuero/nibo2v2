/**
 * @file		xbee.h
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Header file Library for wireless communication
 */

#ifndef XBEE_H
#define XBEE_H

#include <stdio.h>
#include <stdint.h>
#include "uart0.h"
#include <avr/interrupt.h>
#include <nibo/niboconfig.h>

#define default_baudrate 9600
//Enumeration of nibo modes
enum modes {manual, autonom, forward, backwards, half_right, half_left, right, left, voltage };

/*
 * @brief Initialize UART0 Module
 */
void initUART0();

/*
 * @brief Send a command to the PC
 * @param c the command
 */
void sendCmd(char c);

/*
 * @brief Receive a command from the PC
 * @return the received command
 */
uint8_t getCmd();

#endif // XBEE_H
