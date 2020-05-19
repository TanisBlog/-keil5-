#include "ds1302.h"
#include <intrins.h>

uchar time_buf[8] = {0x20,0x20,0x01,0x31,0x16,0x59,0x55,0x05};
uchar dis_time_buf[16]={0};

void Delay_xms(uint x)
{
  uint i,j;
  for(i=0;i<x;i++)
    for(j=0;j<112;j++);
}

void Delay_xus(uint t)	  		 		
{ 
  for(;t>0;t--)
   {
	 _nop_();
   }
}

void ds1302_init() 
{
	RST=0;
	SCK=0;			
}

void ds1302_write_byte(uchar addr, uchar d) 
{
	uchar i;
	RST=1;	
	addr = addr & 0xFE;   
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;      
		SCK=0;
		addr = addr >> 1;
		}	
	for (i = 0; i < 8; i ++) {
		if (d & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;    
		SCK=0;
		d = d >> 1;
		}
	RST=0;
}

uchar ds1302_read_byte(uchar addr) {

	uchar i,temp;	
	RST=1;					
	addr = addr | 0x01;    
	for (i = 0; i < 8; i ++) {
		if (addr & 0x01) {
			IO=1;
			}
		else {
			IO=0;
			}
		SCK=1;
		SCK=0;
		addr = addr >> 1;
		}	
	for (i = 0; i < 8; i ++) {
		temp = temp >> 1;
		if (IO) {
			temp |= 0x80;
			}
		else {
			temp &= 0x7F;
			}
		SCK=1;
		SCK=0;
		}	
	RST=0;
	return temp;
}

void ds1302_write_time() 
{
	ds1302_write_byte(ds1302_control_add,0x00);			
	ds1302_write_byte(ds1302_sec_add,0x80);			
	//ds1302_write_byte(ds1302_charger_add,0xa9);	    
	ds1302_write_byte(ds1302_year_add,time_buf[1]);		
	ds1302_write_byte(ds1302_month_add,time_buf[2]);	
	ds1302_write_byte(ds1302_date_add,time_buf[3]);		
	ds1302_write_byte(ds1302_hr_add,time_buf[4]);		
	ds1302_write_byte(ds1302_min_add,time_buf[5]);		
	ds1302_write_byte(ds1302_sec_add,time_buf[6]);		
	ds1302_write_byte(ds1302_day_add,time_buf[7]);		
	ds1302_write_byte(ds1302_control_add,0x80);			
}

void ds1302_read_time()  
{
	time_buf[1]=ds1302_read_byte(ds1302_year_add);		
	time_buf[2]=ds1302_read_byte(ds1302_month_add);		
	time_buf[3]=ds1302_read_byte(ds1302_date_add);		
	time_buf[4]=ds1302_read_byte(ds1302_hr_add);		
	time_buf[5]=ds1302_read_byte(ds1302_min_add);		
	time_buf[6]=(ds1302_read_byte(ds1302_sec_add))&0x7f;
	time_buf[7]=ds1302_read_byte(ds1302_day_add);		
}

void datapros()
{
   ds1302_read_time();  
   dis_time_buf[0]=(time_buf[0]>>4);    
   dis_time_buf[1]=(time_buf[0]&0x0f);
   
   dis_time_buf[2]=(time_buf[1]>>4);   
   dis_time_buf[3]=(time_buf[1]&0x0f);
  

   
   
   dis_time_buf[4]=(time_buf[2]>>4);   
   dis_time_buf[5]=(time_buf[2]&0x0f);
   

   dis_time_buf[6]=(time_buf[3]>>4);    
   dis_time_buf[7]=(time_buf[3]&0x0f);
   
   dis_time_buf[14]=(time_buf[7]&0x07); 
   
     
   dis_time_buf[8]=(time_buf[4]>>4);   
   dis_time_buf[9]=(time_buf[4]&0x0f);   

  

   dis_time_buf[10]=(time_buf[5]>>4);    
   dis_time_buf[11]=(time_buf[5]&0x0f);   

   dis_time_buf[12]=(time_buf[6]>>4);   
   dis_time_buf[13]=(time_buf[6]&0x0f);
   
}
