#include<pic.h>
#include<htc.h>
void main()
{
	T1CON=0x31;
	TRISC2=1;
	CCPR1L=0x00;
	CCPR1H=0x00;
	CCP1CON=0x04;
	CCP1IE=1;
	INTCON=0xc0;
	TRISB0=0;
	RB0=0;
	while(1)
	{
	}
}
void interrupt isr()
{
	if(CCP1IF==1)
	{
		RB0=~RB0;
		CCP1IF=0;
	}
}