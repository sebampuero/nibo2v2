/*
 @file drive.h
 @author Tichaona Kadzinga, Sebastian Ampuero
 @date 12.11.2017
 @brief header file for the movement of the nibo2 robot
 */
#ifndef DRIVE_H_
#define DRIVE_H_
// Includes
#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>
#include <nibo/copro.h>
#include <nibo/spi.h>
#include <nibo/delay.h>
#include <stdint.h>
#include "nibo_leds.h"

#define FRONT_LEFT       1

#define FRONT_RIGHT      3

#define FRONT      2

#define LEFT_SIDE  0

#define RIGHT_SIDE 4

#define T_FRONT    150

#define T_SIDES    160

#define T_SIDES_90 80





/**
 @brief turns the nibo 90 degrees to the left
 */
void drive_turn_left();

/**
 @brief turns the nibo 45 degrees to the left
 */
void drive_turn_halfLeft();

/**
 @brief turns the nibo 90 degree to the right
 */
void drive_turn_right();

/**
 @brief turns the nibo 45 degrees to the right
 */
void drive_turn_halfRight();

/**
 @brief turns the nibo 180 degree to the right
 */
void drive_turn_around();

void backwards_mode();

uint8_t side_sensors_too_close();

void auto_mode_drive();

uint8_t drive_forward(uint8_t speed);

void stop_completely();

#endif /* DRIVE_H_ */
