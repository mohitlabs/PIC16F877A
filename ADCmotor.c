#include<pic.h>
#include<htc.h>
#define RS RB0
#define RW RB1
#define EN RB2
void delay(unsigned int);
void ADC_Init(void);
unsigned int ADC_Read(unsigned int);
void main()
{
	TRISA=0xff;
	TRISB=0x00;
	ADC_Init();
	int a;
	while(1)
	{
		a=ADC_Read(1);
		if(a>600)
		{
			PORTB=0x40;
		}
		else
		{
			PORTB=0x00;
		}
	}
}
void delay(unsigned int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
		}
}
void ADC_Init()
{
	ADCON0=0x81;
	ADCON1=0xc0;
}
unsigned int ADC_Read(unsigned int channel)
{
	if(channel>7)
	{
		return 0;
	}
	ADCON0|=channel<<3;
	delay(5);
	GO_nDONE=1;
	while(GO_nDONE)
	{
		return ((ADRESH<<8)+ADRESL);
	}
}