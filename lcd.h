#ifndef __LCD_H_
#define __LCD_H_
/**********************************
?????4??????????,
??8???????
**********************************/
//#define LCD1602_4PINS

/**********************************
?????
**********************************/
#include <reg52.h>

//---??????---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN???
**********************************/
#define LCD1602_DATAPINS P2
sbit LCD1602_E=P1^6;
sbit LCD1602_RW=P1^5;
sbit LCD1602_RS=P1^4;

/**********************************
????
**********************************/
/*?51???12MHZ????????*/
void Lcd1602_Delay1ms(uint c);   //?? 0us
/*LCD1602??8??????*/
void LcdWriteCom(uchar com);
/*LCD1602??8??????*/	
void LcdWriteData(uchar dat)	;
/*LCD1602??????*/		
void LcdInit();	
void LcdSetCursor(unsigned char x,unsigned char y);  //????
void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str);     //?????
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);
					  

#endif
