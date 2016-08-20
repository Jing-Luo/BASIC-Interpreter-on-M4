#include "tool.h"

#define maxNum 30

typedef struct{
    int currentLine;
    char mapSymbol[maxNum][10];
    int mapValue[maxNum];
    int numSymbol;
}EVALSTATE;

int fornumber;
int forrange;

void initEval(EVALSTATE* state)
{
    state->numSymbol = 0;
}

void setValue(EVALSTATE* state, const char* var, int value)
{
    int i;
    for (i = 0; i < state->numSymbol; i++)
    {
        if (!strcmp(state->mapSymbol[i], var))//renew if the variable already exists
        {
            state->mapValue[i] = value;
            return;
        }
    }
    if (state->numSymbol >= maxNum)
    {
        printf("SYNTAX ERROR\n");
		Delay();
        SysCtlReset();;
    }
    strcpy(state->mapSymbol[state->numSymbol], var);
    state->mapValue[state->numSymbol] = value;
    state->numSymbol++;
}

int getValue(EVALSTATE* state, const char* var)
{
    int i;
    for (i = 0; i < state->numSymbol; i++)
    {
        if (!strcmp(state->mapSymbol[i], var))//variable found
        {
            return state->mapValue[i];
        }
    }
    printf("VARIABLE NOT DEFINED\n");
	Delay();
    SysCtlReset();
		return -1;
}

int isDefined(EVALSTATE* state, const char* var)
{
    int i;
    for (i = 0; i < state->numSymbol; i++)
    {
        if (!strcmp(state->mapSymbol[i], var))//variable found
        {
            return i;
        }
    }
    return -1;
}
