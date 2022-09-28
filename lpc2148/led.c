#include<LPC214x.h>
void delay(unsigned int n);

int main(void)
{
	IODIR0=0xFF<<16;
	PINSEL1=0x00000000;
	while(1){
		IOPIN0=0xFF<<16;
		delay(1000);
		IOPIN0=0x00<<16;
		delay(1000);
	}
}

void delay(unsigned int n){
	unsigned int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=10000;j++);
		
}	
