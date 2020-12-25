/*
 * LCD.c
 *
 *  Created on: 25 Dec 2020
 *      Author: hp
 */




#include "LCD.h"
		//LCD
		#define HOME 0x02
		#define TWO_LINE_LCD_EIGHT_BIT_MODE 0x38
		#define CURSUR_OFF 0x0c
		#define CLEAR_SCREEN 0x01
		#define SET_CURSOR_LOCATION 0x80

		void LCD_init(void) //LCD intialize

		{
			DDRC |= (0xff); //PC output
			DDRD=(1<<4) | (1<<5) | (1<<6); //PD4 ,PD5 & PD6 are outputs
			LCD_sendcommand(HOME);
			LCD_sendcommand(TWO_LINE_LCD_EIGHT_BIT_MODE); //use the two line of the LCD
			LCD_sendcommand(CURSUR_OFF); //to close cursor
			LCD_sendcommand(CLEAR_SCREEN); // clear screen
		}
		void LCD_sendcommand(unsigned char command) //sending commands to LCD
		{
			PORTD=PORTD&~(1<<5);
			PORTD=PORTD&~(1<<4);
			PORTC=command;
			_delay_ms(1);
			PORTD=PORTD|(1<<6);
			_delay_ms(1);
			PORTD=PORTD&~(1<<6);
		}
		void LCD_displayCharcter(unsigned char data)//display character
		{
				PORTD=PORTD &~(1<<5);
				PORTD=PORTD|(1<<4);
				PORTC=data;
				_delay_ms(1);
				PORTD=PORTD|(1<<6);
				_delay_ms(1);
				PORTD=PORTD&~(1<<6);
		}
		void LCD_displayString(const char *str) //display string
		{
			unsigned char i=0;
			while (str[i] !='\0') //loop is true until NULL
			{
				LCD_displayCharcter(str[i]); //display characters until NULL
				i++;		//increment i
			}
		}

		void LCD_clearScreen(void)
		{
			LCD_sendcommand(CLEAR_SCREEN); //clear display
		}
		void LCD_goToRowColumn(unsigned char row,unsigned char col)
		{
			unsigned char Address;

			/* first of all calculate the required address */
			switch(row)
			{
				case 0:
						Address=col;
						break;
				case 1:
						Address=col+(0x40);
						break;

			}
			   /*ADDRESS = COL+(0X40*ROW)*/
			/* to write to a specific address in the LCD
			 * we need to apply the corresponding command 0b10000000+Address */
			LCD_sendcommand(Address | SET_CURSOR_LOCATION);
		}



