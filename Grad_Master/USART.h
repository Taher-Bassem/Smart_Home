/*
 * USART_RS232_H_file.h
 * http://www.electronicwings.com
 *
 */


#ifndef USART_H_
#define USART_H_

#define F_CPU 16000000UL						/* Define CPU clock Frequencyits 16MHz */
#include <avr/io.h>
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	/*prescale value */

void USART_Init(unsigned long);				/* USART initialize function */
char USART_RxChar();						/* Data receiving function */
void USART_TxChar(char);					/* Data transmitting function */
void USART_SendString(char*);				/* Send string of USART data function */


#endif										/* USART_H_ */
