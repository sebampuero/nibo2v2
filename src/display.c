/**
 * @file		display.c
 * @author		Sebastian Ampuero
 * @date		20.11.2017
 * @brief		Library for the display
 */

/**
 * includes
 */
#include "display.h"


/**
 * array of strings holds the lines appended to the terminal
 */
char display_text[terminal_lines][20] = {"", "", "", "", ""};

/**
 * index of the first line in terminal_text
 */
int line_index = 0;

/**
 * number of lines in the terminal
 * only increases until maximum never decreases
 */
int counter = 0;

/**
 * @brief prints the current Voltage on the display
 */
void printVoltage(){
		char output[20] = "";
		double volt = 0;

		//get current voltage value
		bot_update();
		//calculate the voltage from adc-value
		volt = 0.0166 * bot_supply -1.19;
		//concat output string
		sprintf(output, "VCC: %2.1f V", volt);

		//move to the position on the display where to write
		gfx_move(0,0);

		//draw text
		gfx_print_text(output);
}

/**
 *	@brief initializes the display
 */
void displayInit(){
	//init diplay an graphics lib
	display_init();
	gfx_init();
}

/**
 *	@brief appends a line to the display terminal -> display can show the last #terminal_lines lines
 *	@param txt string to append
 */
void appendLine(char *txt){

	//calculate index for the new line in terminal_text
	int index = (line_index + counter)%terminal_lines;

	//copy the line into terminal_text array at calculated index
	strcpy(display_text[index], txt);

	if(counter < 5){
		counter++;
	}
	else{
		line_index = (line_index++)%terminal_lines;
	}
	//refresh the terminal output on the display
	printDisplay();
}

/**
 * @brief prints all lines in terminal_text to the display
 */
void printDisplay(){
	int i;
	int index;

	for(i = 0; i < counter;i++){

		//clear line
		gfx_move(0,10 + 10*i);
		gfx_print_text("                      ");

		//print line
		index = (line_index + i)%terminal_lines;
		gfx_move(0,10 + 10*i);
		gfx_print_text(display_text[index]);
		delay(10);
	}
}
/**
 * @brief clears the whole display
 */
void clear(){
	gfx_fill(0);
	gfx_move(0,0);
}
