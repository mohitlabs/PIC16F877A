#include<pic.h>
#include<htc.h>
void delay(unsigned int);
void main()
{
	TRISB0=0;
	while(1)
	{
		RB0=1;
		delay(20);
		RB0=0;
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