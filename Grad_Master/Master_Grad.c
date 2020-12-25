	/*
	 * main.c
	 *
	 *  Created on: 18 Dec 2020
	 *      Author: hp
	 */

		#include "SPI.h" //include SPI header file
		#include "USART.h"	//include USART header file

		#define Grad_Master			//Master

#include "USART.h"

		int main(void)

		{
		#ifdef Grad_Master //Master SPI

			char Input;			/* declaration of input */
			DDRB = 0xff;
			USART_Init(9600);	/* initialize USART with 9600 baud rate */
			SPI_initMaster();	/* initialize SPI */

				while(1)
				{
					Input = USART_RxChar(); 	/*recieving from the bluetooth*/

					if (Input =='1')	/*if input is =1 send the byte that will turn led 1 on*/
					{
						USART_SendString("LED1_ON/OFF \n"); //sending to bluetooth device
						SPI_sendByte(0x01);	/*using led at port0 so sending 0b00000001*/
					}
					else if (Input =='2')	/*if input is =1 send the byte that will turn led 1 on*/
					{
						USART_SendString("LED2_ON/OFF \n"); ////sending to bluetooth device
						SPI_sendByte(0x04);/*using led at port2 so sending 0b00000100*/
					}
				}
		}
#endif

