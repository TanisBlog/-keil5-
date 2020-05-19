#include <reg52.h>
#include "display.h"
#include "ds1302.h"
#include "lcd.h"
#include "temp.h"
//#include "__TIME__"
#define uchar unsigned char
#define uint unsigned int
#define true 1
//const  unsigned char cRevisionTime[16] = __TIME__;
int ssd=0;
uchar table0[]={0x04,0x0A,0x0E,0x0E,0x15,0x00,0x11,0x0E,0x00,0x1B,0x11,0x00,0x0E,0x15,0x11,0x0E,0x07,0x05,0x07,0x00,0x00,0x00,0x00,0x00};
uchar table1[]={0x00,0x01,0x02};
uchar time_base;

extern uchar dis_time_buf[16];
extern uchar time_buf[8];
extern uchar code mima[4];
extern uchar table[4];
extern uchar x,y,z,t;
extern uchar twinkle;
extern uchar window;
extern uchar place[4];
extern uchar hour0,minute0,second0,hour1,minute1,second1,h0,h1,m0,m1,s0,s1;
extern uchar A,R,C,D,E,F,G,H,I,J,K,L,M,N,O;
	
void datapros0(int temp) 	 
{
   	float tp;  
	if(temp<0)
  	{
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		ssd=temp;
  	}
 	else
  	{			
		tp=temp;
		temp=tp*0.0625*100+0.5;
    ssd=temp;			
	  }
}

void display()
{
	switch(window)
	{
  case 0:
		datapros();
		DisplayOneChar(0,0,' ');
		DisplayOneChar(1,0,' ');
		DisplayOneChar(2,0,' ');
		DisplayOneChar(3,0,dis_time_buf[0]+'0');
    DisplayOneChar(4,0,dis_time_buf[1]+'0');
    DisplayOneChar(5,0,dis_time_buf[2]+'0');
    DisplayOneChar(6,0,dis_time_buf[3]+'0');
    DisplayOneChar(7,0,'-');
    DisplayOneChar(8,0,dis_time_buf[4]+'0');
    DisplayOneChar(9,0,dis_time_buf[5]+'0');
    DisplayOneChar(10,0,'-');
    DisplayOneChar(11,0,dis_time_buf[6]+'0');
    DisplayOneChar(12,0,dis_time_buf[7]+'0');
  
	  DisplayOneChar(15,0,dis_time_buf[14]+'0');
	  
		DisplayOneChar(3,1,' ');
    DisplayOneChar(4,1,dis_time_buf[8]+'0');
    DisplayOneChar(5,1,dis_time_buf[9]+'0');
    DisplayOneChar(6,1,':');
    DisplayOneChar(7,1,dis_time_buf[10]+'0');
    DisplayOneChar(8,1,dis_time_buf[11]+'0');
    DisplayOneChar(9,1,':');
    DisplayOneChar(10,1,dis_time_buf[12]+'0');
	  DisplayOneChar(11,1,dis_time_buf[13]+'0');
	break;
	case 1:
		if(twinkle)
		{
		DisplayOneChar(0,0,'S');
    DisplayOneChar(1,0,'e');
    DisplayOneChar(2,0,'t');
    DisplayOneChar(3,0,' ');			
		DisplayOneChar(4,0,'C');
    DisplayOneChar(5,0,'l');
    DisplayOneChar(6,0,'o');
    DisplayOneChar(7,0,'c');
    DisplayOneChar(8,0,'k');
    DisplayOneChar(9,0,':');
		DisplayOneChar(10,0,' ');
		DisplayOneChar(11,0,' ');
		DisplayOneChar(12,0,' ');
		DisplayOneChar(15,0,' ');
			
    DisplayOneChar(4,1,hour0+'0');
	  DisplayOneChar(5,1,hour1+'0');
	  DisplayOneChar(6,1,':');
    DisplayOneChar(7,1,minute0+'0');
    DisplayOneChar(8,1,minute1+'0');
    DisplayOneChar(9,1,':');
    DisplayOneChar(10,1,second0+'0');
    DisplayOneChar(11,1,second1+'0');
		delay();
		twinkle=!twinkle;
		}
		if(!twinkle)
		{
	   DisplayOneChar(0,0,'S');
     DisplayOneChar(1,0,'e');
     DisplayOneChar(2,0,'t');
     DisplayOneChar(3,0,' ');			
	 	 DisplayOneChar(4,0,'C');
     DisplayOneChar(5,0,'l');
     DisplayOneChar(6,0,'o');
     DisplayOneChar(7,0,'c');
     DisplayOneChar(8,0,'k');
     DisplayOneChar(9,0,':');
		 DisplayOneChar(10,0,' ');
		 DisplayOneChar(11,0,' ');
		 DisplayOneChar(12,0,' ');
		 DisplayOneChar(15,0,' ');
			
     DisplayOneChar(4,1,hour0+'0');
	   DisplayOneChar(5,1,hour1+'0');
	   DisplayOneChar(6,1,':');
     DisplayOneChar(7,1,minute0+'0');
     DisplayOneChar(8,1,minute1+'0');
     DisplayOneChar(9,1,':');
     DisplayOneChar(10,1,second0+'0');
     DisplayOneChar(11,1,second1+'0');
		 DisplayOneChar(place[0],place[1],'_');
		 delay();
		 twinkle=!twinkle;
		}
	break;
	case 2:
		datapros0(Ds18b20ReadTemp());
		DisplayOneChar(0,0,' ');
		DisplayOneChar(3,0,0x00);
    DisplayOneChar(4,0,ssd%10000/1000+'0');
    DisplayOneChar(5,0,ssd%1000/100+'0');
    DisplayOneChar(6,0,'.');
    DisplayOneChar(7,0,ssd%100/10+'0');
    DisplayOneChar(8,0,ssd%10+'0');
		DisplayOneChar(9,0,0x02);
    DisplayOneChar(10,0,'C');
		DisplayOneChar(11,0,' ');
		DisplayOneChar(12,0,' ');
		DisplayOneChar(15,0,' ');
		
		DisplayOneChar(3,1,0x01);
    DisplayOneChar(4,1,h0+'0');
	  DisplayOneChar(5,1,h1+'0');
	  DisplayOneChar(6,1,':');
    DisplayOneChar(7,1,m0+'0');
    DisplayOneChar(8,1,m1+'0');
    DisplayOneChar(9,1,':');
    DisplayOneChar(10,1,s0+'0');
    DisplayOneChar(11,1,s1+'0');
	break;
	case 3:
		 if(twinkle)
		 { 
		 DisplayOneChar(0,0,'R');
		 DisplayOneChar(1,0,'O');
		 DisplayOneChar(2,0,'O');
		 DisplayOneChar(3,0,'T');
		 DisplayOneChar(4,0,':');
		 DisplayOneChar(5,0,x);
		 DisplayOneChar(6,0,y);
		 DisplayOneChar(7,0,z);
		 DisplayOneChar(8,0,t);
		 DisplayOneChar(9,0,' ');
		 DisplayOneChar(10,0,' ');
		 DisplayOneChar(10,0,' ');
     DisplayOneChar(11,0,' ');
     DisplayOneChar(12,0,' ');
	   DisplayOneChar(15,0,' ');
		 DisplayOneChar(3,1,' ');
     DisplayOneChar(4,1,' ');
     DisplayOneChar(5,1,' ');
     DisplayOneChar(6,1,' ');
     DisplayOneChar(7,1,' ');
     DisplayOneChar(8,1,' ');
     DisplayOneChar(9,1,' ');
     DisplayOneChar(10,1,' ');
	   DisplayOneChar(11,1,' ');
		 delay();
		 twinkle=!twinkle;
		 }
		 if(!twinkle)
	  {
		 DisplayOneChar(0,0,'R');
		 DisplayOneChar(1,0,'O');
		 DisplayOneChar(2,0,'O');
		 DisplayOneChar(3,0,'T');
		 DisplayOneChar(4,0,':');
		 DisplayOneChar(5,0,x);
		 DisplayOneChar(6,0,y);
		 DisplayOneChar(7,0,z);
		 DisplayOneChar(8,0,t);
		 DisplayOneChar(9,0,' ');
		 DisplayOneChar(10,0,' ');
		 DisplayOneChar(10,0,' ');
     DisplayOneChar(11,0,' ');
     DisplayOneChar(12,0,' ');
	   DisplayOneChar(15,0,' ');
		 DisplayOneChar(3,1,' ');
     DisplayOneChar(4,1,' ');
     DisplayOneChar(5,1,' ');
     DisplayOneChar(6,1,' ');
     DisplayOneChar(7,1,' ');
     DisplayOneChar(8,1,' ');
     DisplayOneChar(9,1,' ');
     DisplayOneChar(10,1,' ');
	   DisplayOneChar(11,1,' ');
		 DisplayOneChar(place[2],0,' ');
		 delay();
		 twinkle=!twinkle;
		}
	break;
	case 4:
		if(twinkle)
		{
		DisplayOneChar(0,0,' ');
    DisplayOneChar(1,0,' ');
    DisplayOneChar(2,0,' ');
	  DisplayOneChar(3,0,A+'0');
    DisplayOneChar(4,0,R+'0');
    DisplayOneChar(5,0,C+'0');
    DisplayOneChar(6,0,D+'0');
		DisplayOneChar(7,0,'-');
    DisplayOneChar(8,0,E+'0');
    DisplayOneChar(9,0,F+'0');
		DisplayOneChar(10,0,'-');
    DisplayOneChar(11,0,G+'0');
    DisplayOneChar(12,0,H+'0');
  
	  DisplayOneChar(15,0,I+'0');
	
    DisplayOneChar(4,1,J+'0');
    DisplayOneChar(5,1,K+'0');
		DisplayOneChar(6,1,':');
    DisplayOneChar(7,1,L+'0');
    DisplayOneChar(8,1,M+'0');
		DisplayOneChar(9,1,':');
    DisplayOneChar(10,1,N+'0');
	  DisplayOneChar(11,1,O+'0');
		delay();
		twinkle=!twinkle;
	  }
	  if(!twinkle)
		{
		 DisplayOneChar(3,0,A+'0');
     DisplayOneChar(4,0,R+'0');
     DisplayOneChar(5,0,C+'0');
     DisplayOneChar(6,0,D+'0');
		 DisplayOneChar(7,0,'-');
     DisplayOneChar(8,0,E+'0');
     DisplayOneChar(9,0,F+'0');
     DisplayOneChar(10,0,'-');
     DisplayOneChar(11,0,G+'0');
     DisplayOneChar(12,0,H+'0');
  
	   DisplayOneChar(15,0,I+'0');
	
     DisplayOneChar(4,1,J+'0');
     DisplayOneChar(5,1,K+'0');
		 DisplayOneChar(6,1,':');
     DisplayOneChar(7,1,L+'0');
     DisplayOneChar(8,1,M+'0');
		 DisplayOneChar(9,1,':');
     DisplayOneChar(10,1,N+'0');
	   DisplayOneChar(11,1,O+'0');
		 DisplayOneChar(place[3]%16,place[3]/16,'_');
		 delay();
		 twinkle=!twinkle;
		}
  break;
	}
}

void main()
{
	uchar i;
	LcdWriteCom(0x40);
	for(i=0;i<24;i++)
	{
	 LcdWriteData(table0[i]);
	}
	LcdWriteCom(0x80);
	for(i=0;i<3;i++)
	{
	 LcdWriteData(table1[i]);
	}		
  //time_buf[4]=(cRevisionTime[0]-'0')*16+cRevisionTime[1]-'0';
	//time_buf[5]=(cRevisionTime[3]-'0')*16+cRevisionTime[4]-'0';
	//time_buf[6]=(cRevisionTime[6]-'0')*16+cRevisionTime[7]-'0';
	//ds1302_write_time();
	ds1302_init();
	LcdInit();
	while(1)
	{
	 switch(window)
		{
			case 1: control1();break;
			case 2: control2();break;
			case 3: control3();break;
			case 4: control4();break;	
			default: control0();break;
		}
		display();
	}
}
