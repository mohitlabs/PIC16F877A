#include<pic.h>
#include<htc.h>
void delay(unsigned int);
unsigned int k,pattern[]={0x0a,0x00,0x05,0x00,0x09,0x00,0x06,0x00};
void main()
{
	TRISB=0x00;
	for(k=0;k<8;k++)
	{
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