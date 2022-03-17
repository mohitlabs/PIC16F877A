#include<pic.h>
#include<htc.h>
void delay(int);
void main()
{
	TRISB0=0;
	while(1)
	{
		RB0=1;
		delay(1);
		RB0=0;
		delay(1);
	}
}
void delay(int count)
{
	unsigned int i;
	for(i=0;i<count;i++)
	{
		TMR1L=0x01;
		TMR1H=0x00;
		T1CON=0x31;
		if(TMR1IF)
		{
			TMR1IF=0;
		}
	}
}