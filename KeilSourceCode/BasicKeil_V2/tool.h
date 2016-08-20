#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "UART.h"
#include "LCD.h"
#include "highlow.h"
#include "SysTickConfigure.h"

char LIN[100][50];
int lcnt = 0;

int isWord(char* tmp)
{
    int len = strlen(tmp);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (!isalnum(tmp[i]))
            return 0;
    }
    return 1;
}

void nameCheck(char* name)
{
    if (!strcmp(name, "REM") ||
        !strcmp(name, "LET") ||
        !strcmp(name, "PRINT") ||
        !strcmp(name, "INPUT") ||
        !strcmp(name, "END") ||
        !strcmp(name, "FOR") ||
        !strcmp(name, "NEXT") ||
        !strcmp(name, "GOTO") ||
        !strcmp(name, "IF") ||
        !strcmp(name, "RUN") ||
        !strcmp(name, "LIST") ||
        !strcmp(name, "CLEAR") ||
        !strcmp(name, "QUIT") ||
        !strcmp(name, "HELP"))
    {
        printf("INVALID NAME\n");
		Delay();
        SysCtlReset();
    }
}

int numCheck(char* tmp)
{
    int i;
    for (i = 0; i < strlen(tmp); i++)
    {
        if (tmp[i] < '0' || tmp[i] > '9')
            return 0;
    }
    return 1;
}

char* subLine(char* line, int pos, int len)
{
    char* pch = line;
    char* subch = LIN[lcnt++];
    int i;
    pch = pch + pos;
    for (i =0; i<len; i++)
    {
        subch[i] = *(pch++);
    }
    subch[len] = '\0';
    return subch;
}

int precedence(char* op)
{
	if (!strcmp(op, "=")) return 1;
	if (!strcmp(op, "+") || !strcmp(op, "-")) return 2;
	if (!strcmp(op, "*") || !strcmp(op, "/")) return 3;
	return 0;
}

void helpPrint()
{
    printf("\n================== BASIC INTERPRETER ================== \n"
           "\n1. STATEMENTS\n\n"
           "REM: Used for comments.\n"
           "LET var = exp: BASIC's assignment statement. \n"
           "PRINT exp: Print the value of the expression. \n"
           "INPUT var: Read in a value to be stored in the variable. \n"
           "END: Mark the end of the program. \n"
           "GOTO n: Transfer control unconditionally to line n. \n"
           "IF exp cmp exp THEN n: Branch statement. \n"
           "FOR var = exp TO exp2: Loop statement. \n"
           "NEXT var: Make up the loop with FOR. \n"
           "HIGH/LOW pin: Control the output of pin. \n"
           "DELAY n: Delay n(ms). \n"	
           "\n2. EXECUTED TIME\n\n"
           "The LET, PRINT, and INPUT statements can be executed \n"
           "directly by typing them without a line number. The \n"
           "statements GOTO, IF, REM, FOR and END are legal only if \n"
           "they are given a line number.\n"
           "\n3. CONTROL COMMANDS\n\n"
           "RUN: Start execution from the lowest-numbered line.\n"
           "LIST: List the steps of program in numerical sequence.\n"
           "CLEAR: Delete all program and variables.\n"
           "QUIT: Exits from the BASIC interpreter. \n"
           "HELP: Provide a help message describing the interpreter.\n"
           "\n4. ERROR REPORT\n\n"
           "DIVIDE BY ZERO - Calculating some number divide by zero.\n"
           "INVALID NUMBER - User types wrong value.\n"
           "INVALID NAME - User types wrong var-name such as GOTO.\n"
           "VARIABLE NOT DEFINED - A variable used before assigned.\n"
           "LINE NUMBER ERROR - Statement's line number not exist.\n"
		   "PIN ERROR - Pin number wrong.\n"
           "SYNTAX ERROR - Any other errors.\n"
           "\n5. EXAMPLE\n\n"
           "10 REM Program to add two numbers \n"
           "20 INPUT a \n"
           "30 INPUT b \n"
           "40 LET total = a + b \n"
           "50 PRINT total \n"
           "60 END \n\n"
           "======================================================= \n"
           );
}
