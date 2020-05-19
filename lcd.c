#include"lcd.h"

void Lcd1602_Delay1ms(uint c)   
{
    uchar a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
    	
}

#ifndef 	LCD1602_4PINS	 
void LcdWriteCom(uchar com)	
{
	LCD1602_E = 0;   
	LCD1602_RS = 0;	 
	LCD1602_RW = 0;	
	
	LCD1602_DATAPINS = com;   
	Lcd1602_Delay1ms(1);	

	LCD1602_E = 1;	
	Lcd1602_Delay1ms(5);	 
	LCD1602_E = 0;
}
#else 
void LcdWriteCom(uchar com)	  
{
	LCD1602_E = 0;	
	LCD1602_RS = 0;	 
	LCD1602_RW = 0;	 

	LCD1602_DATAPINS = com;	
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

//	Lcd1602_Delay1ms(1);
	LCD1602_DATAPINS = com << 4; 
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif
	   
#ifndef 	LCD1602_4PINS		   
void LcdWriteData(uchar dat)		
{
	LCD1602_E = 0;	
	LCD1602_RS = 1;	
	LCD1602_RW = 0;

	LCD1602_DATAPINS = dat;
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;  
	Lcd1602_Delay1ms(5); 
	LCD1602_E = 0;
}
#else
void LcdWriteData(uchar dat)			
{
	LCD1602_E = 0;	
	LCD1602_RS = 1;	  
	LCD1602_RW = 0;	

	LCD1602_DATAPINS = dat;	
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

	LCD1602_DATAPINS = dat << 4; 
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif
		   
#ifndef		LCD1602_4PINS
void LcdInit()		
{
 	LcdWriteCom(0x38);  
	LcdWriteCom(0x0c); 
	LcdWriteCom(0x06); 
	LcdWriteCom(0x01);
	LcdWriteCom(0x80); 
}
#else
void LcdInit()		
{
	LcdWriteCom(0x32);	 
	LcdWriteCom(0x28);	 
	LcdWriteCom(0x0c);  
	LcdWriteCom(0x06); 
	LcdWriteCom(0x01);  
	LcdWriteCom(0x80);  
}
#endif

void LcdSetCursor(unsigned char x,unsigned char y) 
{
    unsigned char addr;
    if(y == 0)
        addr = 0x00 + x;
    else
        addr = 0x40 + x;
    
    LcdWriteCom(addr|0x80);
}


void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData)
{
	Y &= 0x1;
	X &= 0xF;
	if (Y) X |= 0x40; 
	X |= 0x80; 
	LcdWriteCom(X);
	LcdWriteData(DData);
}


void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str)    
{
    LcdSetCursor(x,y); 
    while(*str != '\0')
    {
        LcdWriteData(*str++);
    }
}
