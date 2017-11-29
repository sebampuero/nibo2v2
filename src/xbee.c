/**
 * @file		xbee.c
 * @author		Sebastian Ampuero
 * @date		10.11.2017
 * @brief		File Library for wireless communication
 */
#include "xbee.h"

void initUART0(){
	uart0_set_baudrate(default_baudrate);
	uart0_enable();
}

void sendCmd(uint8_t c){
	while(uart0_txfull());
	uart0_putchar(c);
}

uint8_t getCmd(){
	if(!uart0_rxempty()) return uart0_getchar();
	return 0;
}
