/*
 * SPI.c
 *
 *  Created on: Dec 18, 2020
 *      Author: hp
 */
// SPI (Serial  peripheral interface)

#include "SPI.h" //include SPI header file

void SPI_initMaster(void)
{
	DDRB = ((1<<4) | (1<<5) | (1<<7)); /* SS(4), MOSI(5) ,SCK(7) are outputs */
	DDRB &= ~(1<<6); /* MISO(6) is input*/

	SPCR = ((1<<6) | (1<<5) | (1<<4) | (1<<1) | (1<<0));
	SPSR |= (1<<0);
	/*SPI(6) enabled, dataorder(5) LSB,
	 master selected(4),*/
	/* SPCR bit (1)&(0) with SPSR bit (0) (Fosc/64)*/

}

void SPI_initSlave(void)
{
	DDRB &= ~((1<<4) | (1<<5) | (1<<7));/* SS(4), MOSI(5) ,SCK(7) are inputs */
	DDRB |= (1<<6); /* MISO(6) is output*/

	SPCR = ((1<<6) | (1<<5) | (1<<1) | (1<<0));
	SPSR |= (1<<0);
	/*SPI(6) enabled, dataorder(5) LSB*/
	/* SPCR bit (1)&(0) with SPSR bit (0) (Fosc/64)*/
}

void SPI_sendByte(const unsigned char data)
{
	SPDR = data;  //SPDR = Data Register
	while(!(SPSR & (1<<7))) //wait until Flag =1
	{}
}

unsigned char SPI_receiveByte(void)
{
	while(!(SPSR & (1<<7))) //wait until Flag =1
	{}
	return SPDR; //SPDR = Data Register
}

void SPI_sendString(const unsigned char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0') //loop is true until null
	{
		SPI_sendByte(Str[i]);		/* Send each char of string till the NULL */
		i++;						//increment i
	}
}

void SPI_receiveString(unsigned char *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_receiveByte();//send first character
	while(Str[i] != '#') //loop is true until #
	{
		i++;
		Str[i] = SPI_receiveByte();/* receive each char of string till the # */
	}
	Str[i] = '\0'; //changing the # to null
}
