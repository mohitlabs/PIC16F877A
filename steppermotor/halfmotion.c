#include<pic.h>
#include<htc.h>
void delay(unsigned int);
unsigned int k,pattern[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
void main()
{
	for(k=0;1;k++)
	{
		TRISB=0x00;
        if(k>7)
		{
			k=0;
		}
		PORTB=pattern[k];
		delay(50);
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