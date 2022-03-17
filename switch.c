#include<pic.h>
#include<htc.h>
#define load RB0
#define sw RB1
void main()
{
	TRISB0=0;
	TRISB1=1;
	sw=1;
	load=0;
	while(1)
	{
		if(sw==1)
		{
			load=0;
		}
		else
		{
			load=1;
		}
	}
}