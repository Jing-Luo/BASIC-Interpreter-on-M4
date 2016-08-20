#include "exp.h"

typedef struct{
    int type;//1 for REM; 2 for LET; 3 for INPUT; 4 for PRINT; 5 for GOTO; 6 for IF; 7 for END; 8 for FOR; 9 for NEXT£»10 for HIGH; 11 for LOW; 12 for DELAY
    char* name;
    EXPRESSION* exp;
    int nextLine;
    EXPRESSION* exp2;
    char op;
}STATEMENT;

STATEMENT STA[100];
int scnt = 0;

void initStm(STATEMENT* statement)
{
    statement->type = 1;
    statement->name = NULL;
    statement->nextLine = 0;
    statement->op = '=';
    statement->exp = statement->exp2 = NULL;
}

STATEMENT* parseStatement(LINE originalLine)
{
    char* line = LIN[lcnt++];
    //char* line = (char*)malloc(sizeof(char)*100);
    strcpy(line, originalLine);
    STATEMENT* newstatement = &STA[scnt++];
    initStm(newstatement);
    char* token;
    char* tmp;
    char *flag;
    token = strtok(line, " ");
    line = strtok(NULL, "");
    if (!strcmp(token, "REM"))
    {
        newstatement->type = 1;
    }
    else if (!strcmp(token, "LET"))
    {
        newstatement->type = 2;
        tmp = strtok(line, " ");
        nameCheck(tmp);
        newstatement->name = tmp;
        tmp = strtok(NULL, " ");
        if (tmp == NULL || strcmp(tmp, "="))
        {
            printf("SYNTAX ERROR\n");
			disstring("SYNTAX ERROR");
			Delay();
            SysCtlReset();
        }
        line = strtok(NULL, "");
        newstatement->exp = parseExp(line);
    }
    else if (!strcmp(token, "INPUT"))
    {
        newstatement->type = 3;
        tmp = strtok(line, " ");
        nameCheck(tmp);
        newstatement->name = tmp;
    }
    else if (!strcmp(token, "PRINT"))
    {
        newstatement->type = 4;
        newstatement->exp = parseExp(line);
    }
    else if (!strcmp(token, "GOTO"))
    {
        newstatement->type = 5;
        tmp = strtok(line, " ");
        if (numCheck(tmp) == 0)
        {
            printf("INVALID NUMBER\n");
			disstring("INVALID NUMBER");
			Delay();
            SysCtlReset();
        }
        newstatement->nextLine = atoi(tmp);
    }
    else if (!strcmp(token, "IF"))
    {
        newstatement->type = 6;
        line = strtok(line, "<");
        tmp = strtok(NULL, "");
        if (tmp != NULL)
        {
            newstatement->exp = parseExp(line);
            newstatement->op = '<';
        }
        else
        {
            line = strtok(line, "=");
            tmp = strtok(NULL, "");
            if (tmp != NULL)
            {
                newstatement->exp = parseExp(line);
                newstatement->op = '=';
            }
            else
            {
                line = strtok(line, ">");
                tmp = strtok(NULL, "");
                if (tmp != NULL)
                {
                    newstatement->exp = parseExp(line);
                    newstatement->op = '>';
                }
                else
                {
                    printf("SYNTAX ERROR\n");
					disstring("SYNTAX ERROR");
					Delay();
                    SysCtlReset();
                }
            }
        }
        flag = strstr(tmp, "THEN");
        if (flag == NULL)
        {
            printf("SYNTAX ERROR\n");
			disstring("SYNTAX ERROR");
			Delay();
            SysCtlReset();
        }
        line = subLine(tmp, 0, flag - tmp);
        newstatement->exp2 = parseExp(line+1);
        tmp = strtok(flag, " ");
        tmp = strtok(NULL, " ");
        if (numCheck(tmp) == 0)
        {
            printf("INVALID NUMBER\n");
			disstring("INVALID NUMBER");
			Delay();
            SysCtlReset();
        }
        newstatement->nextLine = atoi(tmp);
    }
    else if (!strcmp(token, "END"))
    {
        newstatement->type = 7;
    }
    else if (!strcmp(token, "FOR"))
    {
        newstatement->type = 8;
        if (strstr(line, "TO") == NULL || strstr(line, "=") == NULL)
        {
            printf("SYNTAX ERROR\n");
			disstring("SYNTAX ERROR");
			Delay();
            SysCtlReset();
        }
        line = strtok(line, " ");
        nameCheck(line);
        newstatement->name = line;
        line = strtok(NULL, " ");
        line = strtok(NULL, " ");
        tmp = strtok(NULL, " ");
        tmp = strtok(NULL, " ");
        if (tmp == NULL)
        {
            printf("SYNTAX ERROR\n");
			disstring("SYNTAX ERROR");
			Delay();
            SysCtlReset();
        }
        newstatement->exp = parseExp(line);
        newstatement->exp2 = parseExp(tmp);
    }
    else if (!strcmp(token, "NEXT"))
    {
        newstatement->type = 9;
        tmp = strtok(line, " ");
        nameCheck(tmp);
        newstatement->name = tmp;
    }
	else if (!strcmp(token, "HIGH"))
    {
        newstatement->type = 10;
        tmp = strtok(line, " ");
        nameCheck(tmp);
		if (tmp[0]!='P')//such as PN2
		{
			printf("PIN ERROR\n");
			disstring("PIN ERROR");
			Delay();
			SysCtlReset();
		}			
        newstatement->name = tmp;
    }
	else if (!strcmp(token, "LOW"))
    {
        newstatement->type = 11;
        tmp = strtok(line, " ");
        nameCheck(tmp);
		if (tmp[0]!='P')
		{
			printf("PIN ERROR\n");
			disstring("PIN ERROR");
			Delay();
			SysCtlReset();
		}			
        newstatement->name = tmp;
    }
	else if (!strcmp(token, "DELAY"))
    {
        newstatement->type = 12;
        tmp = strtok(line, " ");
        if (numCheck(tmp) == 0)
        {
            printf("INVALID NUMBER\n");
			disstring("INVALID NUMBER");
			Delay();
            SysCtlReset();
        }
        newstatement->name = tmp;//name implies the sleep time
    }
    else
    {
        printf("SYNTAX ERROR\n");
		disstring("SYNTAX ERROR");
		Delay();
        SysCtlReset();
    }
    return newstatement;
}

void executeStatement(EVALSTATE* state, STATEMENT* statement, int NextLine)
{
    int check = 0;
    char num[30];
    int e1;
    int e2;
    int value;
    switch (statement->type)
    {
    case 1://REM
        break;
    case 2://LET
        value = evalExpession(state, statement->exp);
        setValue(state, statement->name, value);
        break;
    case 3://INPUT
        do
        {
            check = 1;
            printf("%s", " ? ");
			disstring(" ? ");
            UART_InString(num);
			disstring(num);
            if (strlen(num) > 0 && num[0] == '-')//check negative number
                check = numCheck(num+1);
            else
                check = numCheck(num);
            if (check == 1)
                setValue(state, statement->name, atoi(num));
            else
			{
				printf("INVALID NUMBER\n");
				disstring("INVALID NUMBER");
				Delay();
			}
        }while(check == 0);
        break;
    case 4://PRINT
        printf("%d\n", evalExpession(state, statement->exp));
		sprintf(num,"%d",evalExpession(state, statement->exp));
		disstring(num);
        break;
    case 5://GOTO
        state->currentLine = statement->nextLine;
        break;
    case 6://IF
        e1 = evalExpession(state, statement->exp);
        e2 = evalExpession(state, statement->exp2);
        if ((statement->op == '=' && e1 == e2) ||
            (statement->op == '>' && e1 > e2) ||
            (statement->op == '<' && e1 < e2))
                state->currentLine = statement->nextLine;
        break;
    case 7://END
        state->currentLine = -1;
        break;
    case 8://FOR
        value = evalExpession(state, statement->exp);
        setValue(state, statement->name, value);
        forrange = evalExpession(state, statement->exp2);
        break;
    case 9://NEXT
        if (isDefined(state, statement->name) == -1)
        {
            printf("VARIABLE NOT DEFINED\n");
			disstring("VARIABLE NOT DEFINED");
			Delay();
            SysCtlReset();
        }
        value = getValue(state, statement->name);
        value++;
        if (value <= forrange)
        {
            setValue(state, statement->name, value);
            state->currentLine = NextLine;
        }
        break;
	case 10://HIGH
		value = atoi((statement->name)+2);
		if (high(statement->name[1], value) == 0)
		{
			printf("PIN ERROR\n");
			disstring("PIN ERROR");
			Delay();
			SysCtlReset();
		}
		break;
	case 11://LOW
		value = atoi((statement->name)+2);
		if (low(statement->name[1], value) == 0)
		{
			printf("PIN ERROR\n");
			disstring("PIN ERROR");
			Delay();
			SysCtlReset();
		}
		break;
	case 12://DALAY
		DelayS(atoi(statement->name));
		break;
    default:
        printf("SYNTAX ERROR\n");
		disstring("SYNTAX ERROR");
		Delay();
        SysCtlReset();
    }
}
