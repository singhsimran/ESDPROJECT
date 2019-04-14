#include <LPC21xx.H>
#include"ULTRASONIC.h"
#include"UART0.h"
 
#define delay for(i=0;i<65000;i++);
 
unsigned int range=0,i;

 


int main()
{	  VPBDIV=0x01;                 // PCLK = 60MHz
    IO1DIR=0xffffffff;
    ultrasonic_init();
	Port_Initial();
    Uart_Init();
	while(1) {
			Uart_String("Distance:");
      range=get_range();
			display(range);
			Uart_Data(13);	
    }
}
