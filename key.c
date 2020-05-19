#include "key.h"
#include "lcd.h"

uchar number=0;
uchar flag,flag0,flag1;

void delay_ms(uint i)
{
 uchar x,y;
	for(x=i;x>0;x--)
	 for(y=110;y>0;y--);
}

void key_scan0()
{
	uchar temp;
  P3=0x0f;
	if(P3!=0x0f)
 {
	 delay_ms(10);
	 if(P3!=0x0f)
	 {
     P3=0x0f;
		 temp=P3;
		 flag0=temp;
	 }
 }
}

void key_scan1()
{
	uchar temp;
  P3=0xf0;
	if(P3!=0xf0)
 {
	 delay_ms(10);
	 if(P3!=0xf0)
	 {
     P3=0xf0;
		 temp=P3;
     flag1=temp;
		 flag=flag0+flag1;
	 }
 }
}

void key_judge()
{
	switch(flag)
	{		
    case 0x77: number='1';break;
    case 0x7b: number='2';break;
    case 0x7d: number='3';break;
    case 0x7e: number='A';break;
    case 0xb7: number='4';break;
    case 0xbb: number='5';break;
    case 0xbd: number='6';break;
    case 0xbe: number='B';break;
    case 0xd7: number='7';break;
    case 0xdb: number='8';break;
    case 0xdd: number='9';break;
    case 0xde: number='C';break;
    case 0xe7: number='*';break;
    case 0xeb: number='0';break;
    case 0xed: number='#';break;
    case 0xee: number='D';break;
  }
	flag=0;
}
