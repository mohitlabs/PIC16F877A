#include<pic.h>
#include<htc.h>
#define RS RB0
#define RW RB1
#define EN RB2
void delay(unsigned int);
void lcdinit(void);
void lcdcmd(int);
void lcddata(char);
void lcdcmddata(int,char*);
void main()
{
	TRISB0=0;
	TRISB1=0;
	TRISB2=0;
	TRISC=0x00;
	lcdinit();
	while(1)
	{
		lcdcmddata(0x80,"DSPL");
		lcdcmddata(0xc0,"India");
		delay(10);
		lcdcmd(0x01);
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
void lcdcmddata(int c,char *d)
{
	lcdcmd(c);
	while(*d)
	{
		lcddata(*d++);
	}
}