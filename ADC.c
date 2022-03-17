#include<pic.h>
#include<htc.h>
#define RS RB0
#define RW RB1
#define EN RB2
void delay(unsigned int);
void lcdinit(void);
void lcdcmd(int);
void lcddata(char);
void ADC_Init(void);
unsigned int ADC_Read(unsigned int);
void main()
{
	TRISB=0x00;
	TRISC=0x00;
	TRISA=0xff;
	ADC_Init();
	int a;
	lcdinit();
	int digit1,digit2,digit3,digit4;
	while(1)
	{
		a=ADC_Read(1);
		digit1=(a/1000);
		digit2=((a-digit1*1000)/100);
		digit3=((a-(digit1*1000+digit2*100))/10);
		digit4=(a-(digit1*1000+digit2*100+digit3*10));
		lcdcmd(0x80);
		lcddata(digit1+0x30);
		lcddata(digit2+0x30);
		lcddata(digit3+0x30);
		lcddata(digit4+0x30);
		delay(10);
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
void lcdinit()
{
	lcdcmd(0x38);
	lcdcmd(0x08);
	lcdcmd(0x0c);
	lcdcmd(0x01);
}
void lcdcmd(int c)
{
	PORTC=c;
	RS=0;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void lcddata(char d)
{
	PORTC=d;
	RS=1;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
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