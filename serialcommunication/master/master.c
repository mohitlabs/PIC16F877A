#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 8000000
#include"../uart.h"
void main()
{
	OPTION_REG=0x00;
	TRISB=0xff;
	UART_Init(9600);
	while(1)
	{
		UART_Write(PORTB);
		__delay_ms(50);
	}
}