/**
 * @file		main.h
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		Header File for the main programm
 */
#include "xbee.h"
#include "drive.h"
#include "display.h"
#include "n2switchS3.h"

/*
 * @brief Initialize all needed components of the nibo
 */
void init();

/*
 * @brief activates auto mode driving for the nibo
 */
void drive_auto();
