#include<pic.h>
#include<htc.h>
#define RS RC0
#define RW RC1
#define EN RC2
#define r1 RD0
#define r2 RD1
#define r3 RD2
#define r4 RD3
#define c1 RD4
#define c2 RD5
#define c3 RD6
#define c4 RD7
void delay(unsigned int);
void lcdinit(void);
void lcdcmd(int);
void lcddata(char);
char getkey(void);
char keypaddata(void);
void main()
{char key;
	TRISB=0x00;
	TRISC=0x00;
	TRISD=0xf0;
	lcdinit();

	while(1)
	{key=keypaddata();
		lcddata(key);
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
	
	lcdcmd(0x0c);
	lcdcmd(0x01);
lcdcmd(0x80);
}
void lcdcmd(int c)
{
	PORTB=c;
	RS=0;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
}
void lcddata(char d)
{
	PORTB=d;
	RS=1;
	RW=0;
	EN=1;
	delay(10);
	EN=0;
}

char getkey(void)
{
	r1=0;
	r2=1;
	r3=1;
	r4=1;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return '7';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return '8';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return '9';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return '/';
	}
	r1=1;
	r2=0;
	r3=1;
	r4=1;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return '4';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return '5';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return '6';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return 'X';
	}
	r1=1;
	r2=1;
	r3=0;
	r4=1;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return '1';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return '2';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return'3';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return'-';
	}
	r1=1;
	r2=1;
	r3=1;
	r4=0;
	if(c1==0)
	{
		delay(10);
		while(c1==0);
		return'C';
	}
	if(c2==0)
	{
		delay(10);
		while(c2==0);
		return'0';
	}
	if(c3==0)
	{
		delay(10);
		while(c3==0);
		return'=';
	}
	if(c4==0)
	{
		delay(10);
		while(c4==0);
		return'+';
	}
else
return 'n';
}
char keypaddata(void)
{
	char key='n';
	while(key=='n')
	{
		key=getkey();
	}
	return key;
}