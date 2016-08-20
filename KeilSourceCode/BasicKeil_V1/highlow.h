#ifndef _HIGHLOW_H
#define _HIGHLOW_H

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "LED.h"

void GPIOInit()
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);
	LED_Initialize();
}

int high(char ch,int num)
{
	switch(ch){
		case'K':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0, GPIO_PIN_0);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, GPIO_PIN_1);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_2, GPIO_PIN_2);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_3, GPIO_PIN_3);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_4, GPIO_PIN_4);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_5, GPIO_PIN_5);
													return 1;
											 }
								case 6:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_6);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6, GPIO_PIN_6);
													return 1;
											 }
								case 7:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_7);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, GPIO_PIN_7);
													return 1;
											 }
							}
						}
		
		case'L':{						
							switch(num){
								case 0:return 0;
								case 1:return 0;	
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_2, GPIO_PIN_2);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_3, GPIO_PIN_3);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_4, GPIO_PIN_4);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_5, GPIO_PIN_5);
													return 1;
											 }
								case 6:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_6);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_6, GPIO_PIN_6);
													return 1;
											 }
								case 7:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_7);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_7, GPIO_PIN_7);
													return 1;
											 }
							}
						}	

		case'M':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_0, GPIO_PIN_0);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_1, GPIO_PIN_1);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_2, GPIO_PIN_2);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_3, GPIO_PIN_3);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, GPIO_PIN_4);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_5, GPIO_PIN_5);
													return 1;
											 }
								case 6:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_6);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_6, GPIO_PIN_6);
													return 1;
											 }
								case 7:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_7);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_7, GPIO_PIN_7);
													return 1;
											 }
							}
						}		

		case'N':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, GPIO_PIN_0);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_2, GPIO_PIN_2);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_3, GPIO_PIN_3);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_4, GPIO_PIN_4);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, GPIO_PIN_5);
													return 1;
											 }
							}
						}	

		case'P':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_0, GPIO_PIN_0);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_1, GPIO_PIN_1);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_2, GPIO_PIN_2);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_3, GPIO_PIN_3);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_4, GPIO_PIN_4);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_5, GPIO_PIN_5);
													return 1;
											 }
							}
						}	

		case'Q':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_0, GPIO_PIN_0);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_1, GPIO_PIN_1);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_2, GPIO_PIN_2);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_3, GPIO_PIN_3);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_4, GPIO_PIN_4);
													return 1;
											 }
							}
						}

		case'F':{						
							switch(num){
								case 0:{
													LED_On(3);
													return 1;
													
											 }
								case 4:{
													LED_On(2);
													return 1;
											 }
							}
						}												
	}
	return 0;
		
}



int low(char ch,int num)
{
	switch(ch){
		case'K':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_0, 0x00);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_1, 0x00);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_2, 0x00);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_3, 0x00);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_4, 0x00);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_5, 0x00);
													return 1;
											 }
								case 6:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_6);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_6, 0x00);
													return 1;
											 }
								case 7:{
													GPIOPinTypeGPIOOutput(GPIO_PORTK_BASE, GPIO_PIN_7);
													GPIOPinWrite(GPIO_PORTK_BASE, GPIO_PIN_7, 0x00);
													return 1;
											 }
							}
						}
		
		case'L':{						
							switch(num){
								case 0:return 0;
								case 1:return 0;	
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_2, 0x00);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_3, 0x00);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_4, 0x00);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_5, 0x00);
													return 1;
											 }
								case 6:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_6);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_6, 0x00);
													return 1;
											 }
								case 7:{
													GPIOPinTypeGPIOOutput(GPIO_PORTL_BASE, GPIO_PIN_7);
													GPIOPinWrite(GPIO_PORTL_BASE, GPIO_PIN_7, 0x00);
													return 1;
											 }
							}
						}	

		case'M':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_0, 0x00);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_1, 0x00);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_2, 0x00);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_3, 0x00);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_4, 0x00);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_5, 0x00);
													return 1;
											 }
								case 6:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_6);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_6, 0x00);
													return 1;
											 }
								case 7:{
													GPIOPinTypeGPIOOutput(GPIO_PORTM_BASE, GPIO_PIN_7);
													GPIOPinWrite(GPIO_PORTM_BASE, GPIO_PIN_7, 0x00);
													return 1;
											 }
							}
						}		

		case'N':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x00);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x00);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_2, 0x00);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_3, 0x00);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_4, 0x00);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, 0x00);
													return 1;
											 }
							}
						}	

		case'P':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_0, 0x00);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_1, 0x00);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_2, 0x00);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_3, 0x00);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_4, 0x00);
													return 1;
											 }
								case 5:{
													GPIOPinTypeGPIOOutput(GPIO_PORTP_BASE, GPIO_PIN_5);
													GPIOPinWrite(GPIO_PORTP_BASE, GPIO_PIN_5, 0x00);
													return 1;
											 }
							}
						}	

		case'Q':{						
							switch(num){
								case 0:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_0);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_0, 0x00);
													return 1;
													
											 }
								case 1:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_1);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_1, 0x00);
													return 1;
											 }
								case 2:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_2);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_2, 0x00);
													return 1;
											 }
								case 3:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_3);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_3, 0x00);
													return 1;
											 }
								case 4:{
													GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_4);
													GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_4, 0x00);
													return 1;
											 }
							}
						}	

		case'F':{						
							switch(num){
								case 0:{
													LED_Off(3);
													return 1;
													
											 }
								case 4:{
													LED_Off(2);
													return 1;
											 }
							}
						}													
	}
	return 0;
}
#endif
