#include "lcd.h"
#include "key.h"
#include "display.h"
#include "ds1302.h"
#define true 1

uchar code mima[4]={1,3,1,4};
uchar table[4]={0};
uchar x='_',y='_',z='_',t='_';
uchar window=0;
uchar twinkle=0;
uchar place[4]={4,1,5,3};
uchar hour0=0,minute0=0,second0=0,hour1=0,minute1=0,second1=0,h0=0,h1=0,m0=0,m1=0,s0=0,s1=0;
uchar A=0,R=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0,K=0,L=0,M=0,N=0,O=0;

 void delay()
{
	uchar m,n,o;
	for(o=15;o>0;o--)
	for(m=1000;m>0;m--)
	for(n=110;n>0;n--);
}

void delay_500ms()
{
	uchar x,y;
	for(x=500;x>0;x--)
	for(y=110;y>0;y--);
}

void control0()
{
	static uchar aa;
	key_scan0();
	key_scan1();
	key_judge();
	switch(number)
	{
		case 'A': window=1;LcdInit();break;
		case 'B': ++aa;if(aa==12){aa=0;window=3;LcdInit();}break;
		case 'C': window=2;LcdInit();break;
		//case '#':
	}
	number=0;
	//if(dis_time_buf[8]*10+dis_time_buf[9]==hour0*10+hour1 && dis_time_buf[10]*10+dis_time_buf[11]==minute0*10+minute1 && dis_time_buf[12]*10+dis_time_buf[13]==second0*10+second1)
	//{
	 
	//}
}

void naozhong(uchar i)
{
 switch(place[0])
 {
	 case 4: if(i<=2 && (hour0*10+hour1)<=24){hour0=i;place[0]+=1;}else{hour0=0;}break;
	 case 5: if((hour0*10+hour1)<=24){hour1=i;place[0]+=2;}else{hour1=0;}break;
	 case 7: if(i<=5 && (minute0*10+minute1)<=59){minute0=i;place[0]+=1;}else{minute0=0;}break;
	 case 8: if((minute0*10+minute1)<=59){minute1=i;place[0]+=2;}else{minute1=0;}break;
	 case 10: if(i<=5 && (second0*10+second1)<=59){second0=i;place[0]+=1;}else{second0=0;}break;
	 case 11: if((second0*10+second1)<=59){second1=i;place[0]=4;}else{second1=0;}break;
 }
}

void control1()
{
	key_scan0();
	key_scan1();
	key_judge();
	switch(number)
	{
    case 'B': h0=hour0;h1=hour1;m0=minute0;m1=minute1;s0=second0;s1=second1;window=0;LcdInit();break;
		case '*': place[0]-=1;if(place[0]==6){place[0]=5;}if(place[0]==9){place[0]=8;}if(place[0]==3){place[0]=11;}break;
		case 'D': hour0=0;hour1=0;minute0=0;minute1=0;second0=0;second1=0;place[0]=4;window=0;LcdInit();break;
    case '1': naozhong(1);break;
		case '2': naozhong(2);break;
		case '3': naozhong(3);break;
		case '4': naozhong(4);break;
    case '5': naozhong(5);break;
    case '6': naozhong(6);break;
    case '7': naozhong(7);break;
    case '8': naozhong(8);break;
    case '9': naozhong(9);break;
    case '0': naozhong(0);break;
	}
	number=0;
}

void control2()
{
	key_scan0();
	key_scan1();
	key_judge();
	switch(number)
	{
		case 'D': window=0;LcdInit();break;
	}
	number=0;
}

void quanxian(uchar i)
{
 switch(place[2])
 {
	 case 5: table[0]=i;place[2]+=1;x='*';break;
	 case 6: table[1]=i;place[2]+=1;y='*';break;
	 case 7: table[2]=i;place[2]+=1;z='*';break;
	 case 8: table[3]=i;place[2]+=1;t='*';break;
 }
}

void control3()
{	
	key_scan0();
	key_scan1();
	key_judge();
	switch(number)
	{
		case '*': place[2]-=1;if(place[2]==4){place[2]=5;};break;
		case 'D': place[2]=5;x='_';y='_';z='_';t='_';window=0;LcdInit();break;
    case '1': quanxian(1);break;
		case '2': quanxian(2);break;
		case '3': quanxian(3);break;
		case '4': quanxian(4);break;
		case '5': quanxian(5);break;
		case '6': quanxian(6);break;
		case '7': quanxian(7);break;
		case '8': quanxian(8);break;
		case '9': quanxian(9);break;
		case '0': quanxian(0);break;
	}
	number=0;
	 	if(place[2]>8)
 {
	if(table[0]==mima[0] && table[1]==mima[1] && table[2]==mima[2] && table[3]==mima[3])
	{window=4;;LcdInit();delay_500ms();LcdInit();}
	else{LcdInit();delay_500ms();LcdInit();
		   DisplayOneChar(7,1,'N');
	     DisplayOneChar(8,1,'O');delay();delay();
	     x=y=z=t='_';place[2]=5;window=0;LcdInit();}
 }
}

void root(uchar i)
{
 switch(place[3])
 {
	 case 3: A=i;place[3]+=1;break;
	 case 4: R=i;place[3]+=1;break;
	 case 5: C=i;place[3]+=1;break;
	 case 6: D=i;place[3]+=2;break;
	 case 8: if(i<=1 && (E*10+F)<=12){E=i;place[3]+=1;}else{E=0;}break;
	 case 9: if((E*10+F)<=12){F=i;place[3]+=2;}else{F=0;}break;
	 case 11: if(i<=3 && (G*10+H)<=31){G=i;place[3]+=1;}else{G=0;}break;
	 case 12: if((G*10+H)<=31){H=i;place[3]+=3;}else{H=0;}break;
	 case 15: if(i<=7){I=i;place[3]+=5;}else{I=0;}break;
	 case 20: if(i<=2 && (J*10+K)<=24){J=i;place[3]+=1;}else{J=0;}break;
	 case 21: if((J*10+K)<=24){K=i;place[3]+=2;}else{K=0;}break;
	 case 23: if(i<=5 && (L*10+M)<=59){L=i;place[3]+=1;}else{L=0;}break;
	 case 24: if((L*10+M)<=59){M=i;place[3]+=2;}else{M=0;}break;
	 case 26: if(i<=5 && (N*10+O)<=59){N=i;place[3]+=1;}else{N=0;}break;
	 case 27: if((N*10+O)<=59){O=i;place[3]=3;}else{O=0;}break;	 
 }
}


void control4()
{
	 key_scan0();
	 key_scan1();
	 key_judge();
	 switch(number)
	 {
		 case 'B': time_buf[0]=A*16+R;time_buf[1]=C*16+D;time_buf[2]=E*16+F;time_buf[3]=G*16+H;time_buf[4]=J*16+K;time_buf[5]=L*16+M;time_buf[6]=N*16+O;time_buf[7]=I;ds1302_init();ds1302_write_time();window=0;LcdInit();break;
		 case 'D': window=0;LcdInit();break;
		 case '*': place[3]-=1;if(place[3]==7){place[3]=6;}if(place[3]==10){place[3]=9;}if(place[3]==14){place[3]=12;}if(place[3]==25){place[3]=24;}if(place[3]==22){place[3]=21;}if(place[3]==19){place[3]=15;}break;
	   case '1': root(1);break;
		 case '2': root(2);break;
		 case '3': root(3);break;
		 case '4': root(4);break;
		 case '5': root(5);break;
		 case '6': root(6);break;
		 case '7': root(7);break;
		 case '8': root(8);break;
		 case '9': root(9);break;
		 case '0': root(0);break;
	 }
	 number=0;
}
