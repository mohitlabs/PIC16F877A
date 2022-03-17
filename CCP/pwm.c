#include<pic.h>
#include<htc.h>
#define _XTAL_FREQ 20000000
void InitPWM(void);
void SetPWMDutyCycle(unsigned int);
void main()
{
	InitPWM();
	SetPWMDutyCycle(511);
	while(1)
	{
	}
}
void InitPWM()
{
	TRISC2=0;
	CCP1CON=0x0c;
	PR2=0xff;
	T2CON=0xff;
}
void SetPWMDutyCycle(unsigned int DutyCycle)
{
	CCPR1L=(DutyCycle&0x3fc)>>2;
	CCP1CON|=(0x30&(DutyCycle<<4));
}