#include "program.h"

int main()
{
	SysTickInit();
	GPIOInit();
    UARTInit();
	PortInit();
    LCDInit();
	printf("\n**********BASIC INTERPRETER**********\n\n");
	disstring("*****BASIC*****");
	Delay();
	PROGRAM program;
    initProg(&program);
    EVALSTATE evalstate;
    initEval(&evalstate);
	char buff[100];
	while (1)
    {
		UART_InString(buff);
        if (processLine(&program, &evalstate, buff) == 0)
            break;
    }
	Delay();
	SysCtlReset();
    return 0;
}
