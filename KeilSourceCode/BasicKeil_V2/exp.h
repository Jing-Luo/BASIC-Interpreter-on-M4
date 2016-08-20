#include "evalstate.h"

typedef char* LINE;

struct _EXPRESSION{
    int type;//1 for CONSTANT; 2 for IDENTIFIER; 3 for COMPOUND
    int value;//for CONSTANT
    char* name;//for IDENTIFIER
    char op;//for COMPOUND
    struct _EXPRESSION *lhs,*rhs;//for COMPOUND
};

typedef struct _EXPRESSION EXPRESSION;

EXPRESSION EXP[50];
int ecnt = 0;

void initExp(EXPRESSION* exp)
{
    exp->type = 1;
    exp->value = 0;
    exp->name = "NONE";
    exp->op = '+';
    exp->lhs = exp->rhs = NULL;
}

int evalExpession(EVALSTATE* state, EXPRESSION* exp)
{
		int left;
		int right;
    switch (exp->type)
    {
    case 1:
        return exp->value;
    case 2:
        if (isDefined(state,exp->name) == -1)
        {
            printf("VARIABLE NOT DEFINED\n");
			Delay();
            SysCtlReset();
        }
        else return getValue(state, exp->name);
    case 3:
        if (exp->op == '=')
        {
            if(exp->lhs->type != 2)
            {
                printf("SYNTAX ERROR\n");
				Delay();
                SysCtlReset();
            }
            int val = evalExpession(state, exp->rhs);
            setValue(state, exp->lhs->name, val);
            return val;
        }
        left = evalExpession(state, exp->lhs);
        right = evalExpession(state, exp->rhs);
        if (exp->op == '+')
            return left + right;
        if (exp->op == '-')
            return left - right;
        if (exp->op == '*')
            return left * right;
        if (exp->op == '/')
        {
            if (right == 0)
            {
                printf("DIVIDE BY ZERO\n");
				Delay();
                SysCtlReset();
            }
            else return left / right;
        }
        printf("SYNTAX ERROR\n");
		Delay();
        SysCtlReset();
    default:
        printf("SYNTAX ERROR\n");
		Delay();
        SysCtlReset();
    }
    return -1;
}

EXPRESSION* readET(int type, LINE* line, int prec)//read Expression or Term, and make the expression tree
{
    if (type == 0)
    {
        EXPRESSION* exp = readET(1, line, 0);
        char* token;
        char op[2];
        while (1)
        {
            if (*line == NULL)
                break;
            op[0] = (*line)[0];
            op[1] = '\0';
            int newPrec = precedence(op);
            if (newPrec <= prec)
                break;
            token = strtok(*line, " ");
            *line = strtok(NULL, "");
            if (*line == NULL)
            {
                printf("SYNTAX ERROR\n");
				Delay();
                SysCtlReset();
            }
            EXPRESSION* rhs = readET(0, line, newPrec);
            EXPRESSION* newexp = &EXP[ecnt++];
            initExp(newexp);
            newexp->type = 3;
            newexp->lhs = exp;
            newexp->rhs = rhs;
            newexp->op = token[0];
            exp = newexp;
        }
        return exp;
    }
    else if (type == 1)
    {
        EXPRESSION* newexp = &EXP[ecnt++];
        initExp(newexp);
        char* token;
        token = strtok(*line, " ");
        if (token == NULL)
        {
            printf("SYNTAX ERROR\n");
			Delay();
            SysCtlReset();
        }
        *line = strtok(NULL, "");
        if (numCheck(token))
        {
            newexp->type = 1;
            newexp->value = atoi(token);
            return newexp;
        }
        else if (isWord(token))
        {
            newexp->type = 2;
            newexp->name = token;
            return newexp;
        }
        if (strcmp(token, "("))
        {
            printf("SYNTAX ERROR\n");
			Delay();
            SysCtlReset();
        }
        if (*line == NULL)
        {
            printf("SYNTAX ERROR\n");
			Delay();
            SysCtlReset();
        }
        newexp = readET(0, line, 0);
        token = strtok(*line, " ");
        *line = strtok(NULL, "");
        if (strcmp(token, ")"))
        {
            printf("SYNTAX ERROR\n");
			Delay();
            SysCtlReset();			
        }
        return newexp;
    }
    printf("SYNTAX ERROR\n");
	Delay();
    SysCtlReset();
    return NULL;
}

EXPRESSION* parseExp(LINE line)
{
    EXPRESSION* exp = readET(0, &line, 0);
    line = strtok(line, " ");
    if (line != NULL)
    {
        printf("SYNTAX ERROR\n");
		Delay();
        SysCtlReset();
    }
    return exp;
}
