#ifndef __DS1302_H__
#define __DS1302_H__

#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int

sbit RST=P1^1;
sbit IO=P1^2;
sbit SCK=P1^3;
#define ds1302_sec_add			0x80		
#define ds1302_min_add			0x82	
#define ds1302_hr_add			0x84
#define ds1302_date_add			0x86
#define ds1302_month_add		0x88
#define ds1302_day_add			0x8a
#define ds1302_year_add			0x8c
#define ds1302_control_add		0x8e		
#define ds1302_charger_add		0x90 					 
#define ds1302_clkburst_add		0xbe

extern uchar time_buf[8];
extern uchar dis_time_buf[16];

void Delay_xms(uint x);
void Delay_xus(uint t);
void Init_timer0();
void ds1302_read_time();
void ds1302_write_time();
uchar ds1302_read_byte(uchar addr);
void ds1302_write_byte(uchar addr, uchar d);
void ds1302_init();
void datapros();

#endif
