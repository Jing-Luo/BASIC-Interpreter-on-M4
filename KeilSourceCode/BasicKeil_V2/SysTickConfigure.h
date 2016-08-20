#ifndef __SYSTICKCONFIGURE_H_
#define __SYSTICKCONFIGURE_H_

#include "inc/hw_types.h"
#include "driverlib/systick.h"
#include "driverlib/sysctl.h"
unsigned long TheSysClock = 16000UL;

extern void SysTickInit(void);

void SysTickInit(void)
{
		//TheSysClock = SysCtlClockGet();	
		SysTickPeriodSet(TheSysClock);//Set up the initial count of SysTick
		SysTickEnable();//enable SysTick
}

void DelayS(int ms)
{
	int i;
	for(i = 0;i < ms;i++)
	{
		while(1) 
			if(SysTickValueGet()>(TheSysClock/2))
				break;
		while(1) 
			if(SysTickValueGet()<(TheSysClock/2))
				break;
	}
}

#endif
