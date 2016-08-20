#ifndef _LCD_H
#define _LCD_H

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int cline = 1;
int clineflag = 0;
char screen[4][30];

#define uchar unsigned char
#define uint unsigned int

void PortInit(void) //initial ports
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_0);
	GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_0, 0x00);
	GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_1);
	GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_1, 0x00);
}

void delay(uint t)
{ 
	uint i,j;
	for(i=0; i<t; i++)
		for(j=0; j<10; j++);
}

void sendbyte(uchar zdata)
{
	uchar code_seg7;
	uchar serial_clk;
	uchar serial_shift;
	code_seg7=zdata;
	serial_shift=0x80;
	for(serial_clk=0; serial_clk<8; serial_clk++)
	{
		if(code_seg7&serial_shift)
		{
			GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_0, GPIO_PIN_0); 
		}
		else
		{
			GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_0, 0x00);  
		}
		GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_1, 0x00);
		__nop();

		GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_1, GPIO_PIN_1); 
		serial_shift=serial_shift>>1;
	}
}

void write_com(unsigned char cmdcode)
{
	sendbyte(0xf8); 
	sendbyte(cmdcode & 0xf0);
	sendbyte((cmdcode << 4) & 0xf0);
	delay(4); 
}

void write_data(uchar Dispdata)
{
	sendbyte(0xfa); 
	sendbyte(Dispdata & 0xf0); 
	sendbyte((Dispdata << 4) & 0xf0);
	delay(4);
}

void LCDInit() 
{ 
	uchar command_data; 
	delay(100); 
	command_data=0x30; 
	write_com(command_data);
	command_data=0x04; 
	write_com(command_data); 
	command_data=0x0d; 
	write_com(command_data); 
	command_data=0x01; 
	write_com(command_data);
	command_data=0x02; 
	write_com(command_data); 
	command_data=0x80; 
	write_com(command_data); 
	
	delay(3000);
}

void clearscreen()//clear the screen
{
	write_com(0x10);
	delay(3000);
}

void changeline(int i)
{
	switch(i){
		case 1:write_com(0x80);
					 delay(3000);
					 break;
		case 2:write_com(0x90);
					 delay(3000);
					 break;
		case 3:write_com(0x88);
		       delay(3000);
					 break;
		case 4:write_com(0x98);
		       delay(3000);
					 break;
	}
}

void _disstring(char *s)//at most 15 chars,char after 15 will be omitted
{
	int i = 0;
	while(*s != '\0' && i <15)
	{
		write_data(*s);
		s++;
		i++;
	}
}

void aiddisstring(char* str)
{
	int len = strlen(str);
	char* s = str;
	int i = 0;
	int j = 0;
	int k = 0;
	if (len < 16)
	{
		_disstring(str);
		while (i < 16 - len)
		{
			write_data(' ');
			i++;
		}
	}
	else
	{	
		for (i = 0; i < len-14; i++)
		{
			_disstring(s+i);
			delay(200000);
			changeline(cline);
		}
		for (j = 1; j < 5; j++)
		{
			_disstring(s+i);
			i++;
			for (k = 0; k < j; k++)
				write_data(' ');
			delay(200000);
			changeline(cline);
		}
		_disstring(str);
	}
	cline = cline % 4 + 1;
	changeline(cline);
	delay(200000);
}

void aiddisstring2(char* str)
{
	int len = strlen(str);
	char* s = str;
	int i = 0;
	if (len < 16)
	{
		_disstring(str);
		while (i < 16 - len)
		{
			write_data(' ');
			i++;
		}
	}
	else
	{	
		for (i = 0; i < len-14; i++)
		{
			_disstring(s+i);
			delay(150000);
			changeline(cline);
		}
		_disstring(str);
	}
	cline = cline % 4 + 1;
	changeline(cline);
}

void disstring(char* str)
{	
	if (clineflag <= 3)
	{
		aiddisstring(str);
		strcpy(screen[clineflag], str);
		clineflag++;
	}
	else
	{
		changeline(1);
		strcpy(screen[0], screen[1]);
		strcpy(screen[1], screen[2]);
		strcpy(screen[2], screen[3]);
		strcpy(screen[3], str);
		int i = 0;
		for (i = 0; i < 3; i++)
			aiddisstring2(screen[i]);
		aiddisstring(screen[3]);
		changeline(4);
	}
}

void dispicture(uchar *addr)
{
  uint i,j;
  for(i=0;i<32;i++)
  {
          write_com(0x80+i);
          write_com(0x80);
          for(j=0;j<16;j++)
          {
                  write_data(*addr);
                  addr++;
          }
  }
  for(i=0;i<32;i++)
    {
            write_com(0x80+i);
            write_com(0x88);
            for(j=0;j<16;j++)
            {
                    write_data(*addr);
                    addr++;
            }

    }
}
#endif
