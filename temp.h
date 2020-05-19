#ifndef __TEMP_H_
#define __TEMP_H_

#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit DSPORT=P1^0;

void Delay1ms(uint );
uchar Ds18b20Init();
void Ds18b20WriteByte(uchar com);
uchar Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
int Ds18b20ReadTemp();

#endif
