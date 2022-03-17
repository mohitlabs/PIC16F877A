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
		TMR2=0x00;
		PR2=0xff;
		T2CON=0xff;
		if(TMR2IF)
		{
			TMR2IF=0;
		}
	}
}