/*
 * SPI.h
 *
 *  Created on: Dec 18, 2020
 *      Author: hp
 */

#ifndef SPI_H_
#define SPI_H_

		#include <avr/io.h> //include avr std library
		#include <util/delay.h> //include delay library
		#include<avr/interrupt.h> //include interrupt library
		#include "stdlib.h"

		#define F_CPU 16000000UL //Define CPU clock Frequency 16MHz

void SPI_initMaster(void);  //SPI initialize master
void SPI_initSlave(void);	//SPI initialize slave
void SPI_sendByte(const unsigned char data); //sending byte function
unsigned char SPI_receiveByte(void);	//receiving byte function
void SPI_sendString(const unsigned char *Str); //sending string function
void SPI_receiveString(unsigned char *Str); //receiving string function

#endif /* SPI_H_ */
