#include "statement.h"

struct _sunion{
    LINE line;
    STATEMENT* statement;
    int index;
};

typedef struct _sunion* sunion;

struct _sunion SUN[100];
int sucnt = 0;

#define maxLine 100
typedef struct{
    int ln[maxLine];
    sunion su[maxLine];
    int vec[maxLine];
    int numLine;
}PROGRAM;

void initProg(PROGRAM* program)
{
    program->numLine = 0;
}

int findLine(PROGRAM* program, int lineNumber)
{
    int i = 0;
    for (i = 0; i < program->numLine; i++)
    {
        if (program->ln[i] == lineNumber)
            return i;
    }
    return -1;
}

void addSourceLine(PROGRAM* program, int lineNumber, LINE line)
{
    if (findLine(program, lineNumber) == -1)
    {
        program->ln[program->numLine] = lineNumber;
        //sunion tmp = (sunion)malloc(sizeof(struct _sunion)*100);
        sunion tmp = &SUN[sucnt++];
        tmp->statement = NULL;
        if (program->numLine == 0 || lineNumber > program->vec[program->numLine-1])
        {
            program->vec[program->numLine] = lineNumber;
            tmp->index = program->numLine;
        }
        else
        {
            int i = 0;
            for (i = 0; i < program->numLine; i++)
            {
                if (lineNumber < program->vec[i])
                {
                    int j = program->numLine;
                    while (j != i)
                    {
                        program->vec[j] = program->vec[j-1];
                        j--;
                    }
                    program->vec[i] = lineNumber;
                    tmp->index = i;
                    int suIndex;
                    for (j = i+1; j <= program->numLine; j++)
                    {
                        suIndex = findLine(program, program->vec[j]);
                        program->su[suIndex]->index++;
                    }
                    break;
                }
            }
        }
        program->su[program->numLine] = tmp;
        program->numLine++;
    }
    program->su[findLine(program, lineNumber)]->line = LIN[lcnt++];
    strcpy(program->su[findLine(program, lineNumber)]->line, line);
}

LINE getSourceLine(PROGRAM* program, int lineNumber)
{
    int flag = findLine(program, lineNumber);
    if (flag != -1)
        return program->su[flag]->line;
    else
        return "";
}

int getFirstLineNumber(PROGRAM* program)
{
    if (program->numLine != 0)
        return program->vec[0];
    else
        return -1;
}

int getNextLineNumber(PROGRAM* program, int lineNumber)
{
    int flag = findLine(program, lineNumber);
    if (flag != -1)
    {
        int idx = program->su[flag]->index;
        if (idx < program->numLine - 1)
            return program->vec[idx+1];
        else return -1;
    }
    else if (program->vec[program->numLine - 1] <= lineNumber)
        return -1;
    else
    {
        int i = 0;
        for (i = 0; i < lineNumber; i++)
        {
            if (program->vec[i] > lineNumber)
                return program->vec[i];
        }
    }
    return -1;
}

STATEMENT* getParsedStatement(PROGRAM* program, int lineNumber)
{
    int flag = findLine(program, lineNumber);
    if (flag != -1)
    {
        return program->su[flag]->statement;
    }
    else
    {
        printf("LINE NUMBER ERROR\n");
		disstring("LINE NUMBER ERROR");
		Delay();
        SysCtlReset();
    }
		return NULL;
}

void setParsedStatement(PROGRAM* program, int lineNumber, STATEMENT *statement)
{
    int flag = findLine(program, lineNumber);
    if (flag != -1)
    {
        if (program->su[flag]->statement != NULL)
            free(program->su[flag]->statement);
        program->su[flag]->statement = statement;
    }
    else
    {
        printf("SYNTAX ERROR\n");
		disstring("SYNTAX ERROR");
		Delay();
        SysCtlReset();
    }
}

int processLine(PROGRAM* program, EVALSTATE* state, LINE line)
{
    char* token;
    char* tmp;
	char intstr[50];
    token = strtok(line, " ");
    tmp = strtok(NULL, "");
    int currentLine;
    int NextLine;
    if (token == NULL)
    {
        return 1;
    }
    else if (!strcmp(token, "QUIT"))
        return 0;
    else if (!strcmp(token, "HELP"))
    {
        helpPrint();
    }
    else if (!strcmp(token, "LIST"))
    {
        currentLine = getFirstLineNumber(program);
        while (currentLine != -1)
        {
            printf("%d %s\n",currentLine, getSourceLine(program, currentLine));
			sprintf(intstr,"%d",currentLine);
			strcat(intstr, " ");
			strcat(intstr, getSourceLine(program, currentLine));
			disstring(intstr);
            currentLine = getNextLineNumber(program, currentLine);
        }
    }
    else if (!strcmp(token, "RUN"))
    {
        currentLine = getFirstLineNumber(program);
        state->currentLine = currentLine;
        NextLine = getNextLineNumber(program, fornumber);
        while (currentLine != -1)
        {
            executeStatement(state, getParsedStatement(program, currentLine), NextLine);
            if (currentLine != state->currentLine)
                currentLine = state->currentLine;
            else
            {
                currentLine = getNextLineNumber(program, currentLine);
                state->currentLine = currentLine;
            }
        }
    }
    else if (!strcmp(token, "CLEAR"))
    {
        initProg(program);
        initEval(state);
    }
    else if (!strcmp(token, "LET") 
		  || !strcmp(token, "PRINT")
	      || !strcmp(token, "INPUT") 
	      || !strcmp(token, "PRINT") 
	      || !strcmp(token, "HIGH")
	      || !strcmp(token, "LOW")
	      || !strcmp(token, "DELAY"))
    {
        if (tmp == NULL)
        {
			printf("SYNTAX ERROR\n");
			disstring("SYNTAX ERROR");
			Delay();
            SysCtlReset();
        }
        char tmp2[30];
        //tmp2 = (char*)malloc(sizeof(char*)*100);
        tmp2[0] = ' ';
        strcpy(tmp2+1, tmp);
        strcat(token, tmp2);
        executeStatement(state, parseStatement(token), 0);
    }
    else if (numCheck(token))
    {
        int lineNumber = atoi(token);
        token = strtok(tmp, " ");
        tmp = strtok(NULL, "");
        if (token == NULL)
        {
            return 1;
        }
        if (!strcmp(token, "FOR"))
            fornumber = lineNumber;
        if (!strcmp(token, "LET") ||
            !strcmp(token, "PRINT") ||
            !strcmp(token, "INPUT") ||
            !strcmp(token, "REM") ||
            !strcmp(token, "IF") ||
            !strcmp(token, "GOTO") ||
            !strcmp(token, "END") ||
            !strcmp(token, "FOR") ||
            !strcmp(token, "NEXT") ||
			!strcmp(token, "HIGH") ||
			!strcmp(token, "LOW") ||
			!strcmp(token, "DELAY"))
        {
            if (tmp != NULL)
            {
                char tmp2[30];
                tmp2[0] = ' ';
                strcpy(tmp2+1, tmp);
                strcat(token, tmp2);
            }
            addSourceLine(program, lineNumber, token);
            setParsedStatement(program, lineNumber, parseStatement(token));
        }
        else
        {
            printf("SYNTAX ERROR\n");
			disstring("SYNTAX ERROR");
			Delay();
            SysCtlReset();
        }
    }
    else
    {
        printf("SYNTAX ERROR\n");
		disstring("SYNTAX ERROR");
		Delay();
        SysCtlReset();
    }
    return 1;
}
