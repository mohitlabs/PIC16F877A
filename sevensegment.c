#include<pic.h>
#include<htc.h>
void delay(unsigned int);
unsigned int a,i,j,k,length,hex[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void main()
{
	TRISB=0;
	length=(sizeof(hex)/sizeof(hex[0]))-1;
	PORTB=0xff;
	for(k=0;1;k++)
	{
		if(k>length)
		{
			k=0;
		}
		PORTB=hex[k];
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