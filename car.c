#include<pic.h>
#include<htc.h>
#define swforward 0x81
#define swleft 0x82
#define swright 0x84
#define swbackward 0x88
#define moveforward 0x06
#define moveleft 0x04
#define moveright 0x02
#define movebackward 0x09
#define stop 0x00
void interruptinit(void);
void interruptprogram(void);
void delay(int);
int k,pattern[]={0x06,0x00,0x02,0x00};
void main()
{
	interruptinit();
	TRISB0=1;
	TRISB7=0;
	TRISC=0xff;
	TRISD=0x00;
	RB7=0;
	for(k=0;1;k++)
	{
		if(k>3)
		{
			k=0;
		}
		PORTD=pattern[k];
		delay(50);
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
		if(PORTC==swforward||swleft||swright||swbackward)
		{
			switch(PORTC)
			{
				case swforward:
				while(PORTC==swforward)
				{
					PORTD=moveforward;
				}
				break;
				case swleft:
				while(PORTC==swleft)
				{
					PORTD=moveleft;
				}
				break;
				case swright:
				while(PORTC==swright)
				{
					PORTD=moveright;
				}
				break;
				case swbackward:
				while(PORTC==swbackward)
				{
					PORTD=movebackward;
				}
			}
		}
		PORTD=stop;
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