#include<pic.h>
#include<htc.h>
void main()
{
	TMR1L=0x00;
	TMR1H=0x00;
	T1CON=0x31;
	CCPR1L=0x03;
	CCPR1H=0x00;
	CCP1CON=0x0a;
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