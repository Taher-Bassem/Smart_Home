/*
 * lcd.h
 *
 *  Created on: 12 Nov 2020
 *      Author: hp
 */

#ifndef LCD_H_
#define LCD_H_

		#include <avr/io.h> //include avr std library
		#include <util/delay.h> //include delay library
		#include<avr/interrupt.h> //include interrupt library
		#include "stdlib.h"

#define F_CPU 16000000UL

void LCD_init (void); //LCD initialize
void LCD_sendcommand (unsigned char command); // sending command to LCD
void LCD_displayCharcter(unsigned char data); // display character
void LCD_displayString(const char *str); //display string
void LCD_goToRowColumn(unsigned char row,unsigned char col); //choosing row and column to write
void LCD_clearScreen(void); //clear screen

#endif /* LCD_H_ */
