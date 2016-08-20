#include "program.h"

int main()
{
	SysTickInit();
	GPIOInit();
    UARTInit();
	PortInit();
    LCDInit();
	UART_OutString("\n**********BASIC INTERPRETER**********\n\n");
	char firstdiaplay[] = "*****BASIC*****";
	disstring(firstdiaplay);
	Delay();
	PROGRAM program;
    initProg(&program);
    EVALSTATE evalstate;
    initEval(&evalstate);
	char buff[100];
	while (1)
    {
		UART_InString(buff);
		disstring(buff);	
        if (processLine(&program, &evalstate, buff) == 0)
            break;
    }
	Delay();
	SysCtlReset();
    return 0;
}
