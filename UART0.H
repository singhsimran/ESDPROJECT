#include<lpc21xx.h>
void Uart_Data(unsigned char data );
void Uart_Init(void)
 {
   U0LCR=0X83;                           /* line control registor
                               */
   U0DLL=0X62;                           /* baud rate registor
                               */
   U0DLM=0X00;                           /* baud rate registor
                               */
   U0LCR=0X03;                           /* line control registor
                               */
 }
 void Uart_Data(unsigned char data )
 {
   U0THR = data;
   while((U0LSR & 0X20)!= 0X20);
 }
void Uart_String(unsigned char *dat)
 {
    while(*dat!='\0')
    {
         Uart_Data(*dat);
         dat++;
    }
 }
  void display(int num)
 { int arr[2];
     int i=0;
    while(num>0)
    {
        arr[i]=num%10;
        num=num/10;
        i=i+1;
    }
    for(i=3;i>=0;i--)
    {Uart_Data(arr[i]+48);}
 }
 void Port_Initial(void)
 {
    PINSEL0  =  0x00000005;
 }
 
