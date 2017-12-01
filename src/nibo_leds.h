/**
 * @file		nibo_leds.h
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Header File Library for leds display according to function of nibo
 */
#include <nibo/leds.h>
#include <nibo/pwm.h>
#include <nibo/niboconfig.h>

/*
 * @brief Turn on the headlights, it can be dangerous at night
 */
void going_front();

/*
 * @brief Turn on right leds in green when turning 90° to the right
 */
void going_right();

/*
 * @brief Turn on left leds in green when turning 90° to the left
 */
void going_left();

/*
 * @brief Turn on all leds in red when nibo has no escape
 */
void all_blocked();

/*
 * @brief Turn on front-left leds in green when turning 45° to the left
 */
void going_half_left();

/*
 * @brief Turn on front-right leds in green when turning 45° to the right
 */
void going_half_right();

