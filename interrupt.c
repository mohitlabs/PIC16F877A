#include<pic.h>
#include<htc.h>
void interruptinit(void);
void interruptprogram(void);
void delay(int);
void main()
{
	interruptinit();
	TRISB7=0;
	TRISC0=0;
	TRISC7=1;
	TRISD0=0;
	RB7=0;
	while(1)
	{
		RC0=1;
		delay(20);
		RC0=0;
		delay(20);
		interruptprogram();
	}
}
void interruptinit()
{
	INTCON=0x90;
	OPTION_REG=0x40;
}
void interrupt isr(void)
{
	if(INTF)
	{
		RB7=~RB7;
	}
	INTF=0;
}
void interruptprogram()
{
	while(RC7==1)
	{
		RD0=0;
		delay(20);
		RD0=1;
		delay(20);
	}
}
void delay(int a)
{
	unsigned int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}