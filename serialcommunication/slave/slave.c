#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 8000000
#include"../uart.h"
void main()
{
	TRISB=0x00;
	UART_Init(9600);
	do
	{
		if(UART_Data_Ready())
		{
			PORTB=UART_Read();
			__delay_ms(50);
		}
	}while(1);
}