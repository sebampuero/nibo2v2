/**
 * @file		display.h
 * @author		Sebastian Ampuero
 * @date		20.11.2017
 * @brief		Header File Library for the display
 */

/**
 * defines
 */
#define terminal_lines 5

/**
 * includes nibo
 */
#include <nibo/niboconfig.h>
#include <nibo/display.h>
#include <nibo/gfx.h>
#include <nibo/bot.h>

/**
 *includes avr
 */
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

/**
 * includes other
 */
#include <stdio.h>
#include "string.h"

/**
 *	@brief initializes the advanced Display library
 */
void displayInit();

/**
 *	@brief appends a line to the advDisplay terminal -> display can show the last #terminal_lines lines
 *	@param txt string to append
 */
void appendLine(char *txt);

/**
 * @brief prints the current Voltage on the display
 */
void printVoltage();

void clear();