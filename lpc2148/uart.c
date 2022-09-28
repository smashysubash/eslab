#include<LPC214x.h>
void urt0_write(unsigned char x);
unsigned char urt_0_read(void);
void serial0_string_write(unsigned char *p);
void urt0_init(void);
int main(){
	urt0_init();
	serial0_string_write("NEC WELCOMES YOU");
}

void urt0_init(){
	PINSEL0=0x00000005;
	U0LCR=0x83;
	U0DLM=0x00;
	U0DLL=0x61;
	U0LCR=0x03;
	
}

void urt0_write(unsigned char x){
	while((U0LSR & 0x20)!=0x20);
	U0THR=x;
}

unsigned char urt_0_read(){
	unsigned char value;
	while((U0LSR & 0x01)!=0x01);
	value=U0RBR;
	return value;
}
void serial0_string_write(unsigned char *p)
{
	while(*p!='\0')
	{
		urt0_write(*p);
		p=p+1;
	}
}
