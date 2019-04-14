#include<LPC21xx.h>
#include"TIMER.h"
#define trig (1<<8)             //P0.8
#define echo (IO0PIN&(1<<9))         //P0.9 as EINT3
 
void ultrasonic_init(void);
void send_pulse(void);
unsigned int get_range(void);
 
void ultrasonic_init()
{
    IO0DIR|=(1<<8);
    T0TCR=0;
    T0PR=59;
}
 
void send_pulse()
{
    T0TC=T0PC=0;
    IO0SET=trig;                            //trig=1
    time1delay(10);                        //10us delay
    IO0CLR=trig;                            //trig=0
}
 
unsigned int get_range()
{
    unsigned int get=0;
    send_pulse();
    while(!echo);
    T0TCR=0x01;
    while(echo);
    T0TCR=0;
    get=T0TC;
		unsigned int distance_ultra=(0.0343*get)/2;
 
    return distance_ultra;
}

