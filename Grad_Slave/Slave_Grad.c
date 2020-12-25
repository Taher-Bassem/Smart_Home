	/*
	 * main.c
	 *
	 *  Created on: 18 Dec 2020
	 *      Author: hp
	 */

		#include "SPI.h" //include SPI header file
		#include "LCD.h" //include LCD header file

#define Grad_slave
		//GRAD

		int main(void)
		{
#ifdef Grad_slave

			SPI_initSlave(); //initialize SPI slave
			LCD_init();		 //initialize LCD

			DDRA |= (1<<0); //PA0 output
			DDRD |= (1<<2); //PD2 output

			PORTA &= ~(1<<0); //led is initially OFF
			PORTD &= ~(1<<2); //led is initially OFF

			SREG |= (1<<7); //enable global interrupt
			SPCR |= (1<<7); //SPI Interrupt Enable

			char z[]="enter 1 or 2";
			LCD_displayString(z); //display z
			while(1){}

			}
			ISR (SPI_STC_vect)
				{if ( SPI_receiveByte() == 0x01)
					{
						LCD_clearScreen(); //LCD clear screen

						PORTA ^= (0x01); //toggle with 0b00000001

						char x[]="LED1_ON/OFF";
						LCD_displayString(x); //display x

						LCD_goToRowColumn(1,0); //go to next row

						char y[]="reenter 1 or 2";
						LCD_displayString(y); //display y
					}
				else
					{
						LCD_clearScreen(); //LCD clear screen

						PORTD ^= (0x04); //toggle with 0b00000100

						char x[]="LED2_ON/OFF";
						LCD_displayString(x); //display x

						LCD_goToRowColumn(1,0); //go to next row

						char y[]="reenter 1 or 2";
						LCD_displayString(y); //display y
					}

				}
#endif

