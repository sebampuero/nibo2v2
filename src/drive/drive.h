/*
 @file drive.h
 @author Tichaona Kadzinga, Sebastian Ampuero
 @date 12.11.2017
 @brief header file for the movement of the nibo2 robot
 */

#ifndef DRIVE_H
#define DRIVE_H

#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>
#include <nibo/copro.h>
#include <nibo/spi.h>
#include <nibo/delay.h>
#include <stdint.h>
#include "../leds/nibo_leds.h"
#include "../xbee/xbee.h"

// Define copro_sensor identifiers
#define FRONT_LEFT       3

#define FRONT_RIGHT      1

#define FRONT      2

#define LEFT_SIDE  4

#define RIGHT_SIDE 0

//Threshold values for copro sensors
// Threshold for the front sensor
#define T_FRONT    150
//Threshold for front-side sensors
#define T_SIDES    140
//Threshold for side sensors
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

/*
 * @brief sets the nibo in backwards mode temporarily
 */
void backwards_mode();

/*
 * @brief Evaluates if side sensors are too close
 * @return true if they are too close, false otherwise
 */
uint8_t side_sensors_too_close();

/*
 * @brief Evaluates if the right sensor is too close
 * @return true if it is too close, false otherwise
 */
uint8_t is_right_side_too_close();

/*
 * @brief Evaluates if the left sensor is too close
 * @return true if it is too close, false otherwise
 */
uint8_t is_left_side_too_close();

/*
 * @brief Drives the nibo automatically avoiding obstacles using its IR-Distance Sensors
 */
void auto_mode_drive();

/*
 * @brief Drives the Nibo forward with a given speed
 * @param speed the speed the nibo drives at
 * @return true if the nibo drives without encountering an obstacle, false otherwise
 */
uint8_t drive_forward(uint8_t speed);

/*
 * @brief Stops the nibo instantly and completely
 */
void stop_completely();

#endif /* DRIVE_H */
