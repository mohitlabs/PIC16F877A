#include<pic.h>
#include<htc.h>
void delay(unsigned int);
void main()
{
	TRISB=0x00;
	while(1)
	{
		PORTB=0xff;
		delay(20);
		PORTB=0x00;
		delay(20);
	}
}
void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<100;j++);
	}
}