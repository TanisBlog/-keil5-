#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#define uchar unsigned char
#define uint unsigned int


extern uchar dis_time_buf[16];
extern uchar time_buf[8];
extern uchar number;


void delay();
void delay_500ms();
void control0();
void control1();
void control2();
void control3();
void control4();
void naozhong(uchar i);
void root(uchar i);
void quanxian(uchar i);
#endif
