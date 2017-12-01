/**
 * @file		xbee.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		File Library for wireless communication
 */
#include "xbee.h"
#include "display.h"

/*
 * @brief Initialize UART0 Module
 */
void initUART0(){
	uart0_set_baudrate(default_baudrate);
	uart0_enable();
}
/*
 * @brief Send a command to the PC
 * @param c the command
 */
void sendCmd(char c){
	while(uart0_txfull());
	uart0_putchar(c);
}
/*
 * @brief Receive a command from the PC
 * @return the received command
 */
uint8_t getCmd(){
	if(!uart0_rxempty()) return uart0_getchar();
	return 255;
}
