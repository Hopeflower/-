#include<iostream>
#include<stack>
#include<cstring>
#include"Complex.h"
using namespace std;
class clac
{
	struct Node
	{		
		char name;
		Complex data;
	};
	int size;
	Node *elem;
	char *expression;

	enum token { OPAREN, ADD, SUB, MULTI, DIV, CPAREN, VELUE, EOL };

	void BrinaryOp(token op, stack<Complex>&dataStack);
	token getop(Complex &value);
public:
	clac(char *ch , char *s, Complex * C)
	{
		int lenth = strlen(s) + 1;
		elem = new Node[lenth];
		for (int i = 0; s[i] != '\0'; ++i)
		{
			elem[i].name = s[i];
			elem[i].data = C[i];
		}
		size = strlen(ch) + 1;
		expression = new char[strlen(ch) + 1];
		int i;
		for (i = 0; ch[i] !='#'; ++i)
		{
			expression[i] = ch[i];
		}
		expression[i+1] = '\0';
	}

	~clac(){}
	Complex result();
	Complex FindID(const Node * n,const char &ch);
};


void clac::BrinaryOp(token op, stack<Complex>& dataStack)
{
	Complex c1, c2;
	if (dataStack.empty())
	{
		cout << "È±²Ù×÷·û£¡";
		exit(1);
	}
	else
	{
		c2 = dataStack.top();
		dataStack.pop();
	}
	if (dataStack.empty())
	{
		cout << "È±²Ù×÷·û£¡";
		exit(1);
	}
	else
	{
		c1 = dataStack.top();
		dataStack.pop();
	}

	switch (op)
	{
	case ADD:
	{
		dataStack.push(c1 + c2);
		break;
	}
	case SUB:
	{
		dataStack.push(c1 - c2);
		break;
	}
	case MULTI:
	{
		dataStack.push(c1 * c2);
		break;
	}
	case DIV:
	{
		dataStack.push(c1 / c2);
		break;
	}
	default:
		break;
	}
}

clac::token clac::getop(Complex  & value)
{
	while (*expression)
	{
		if (*expression&&*expression == ' ')
		{
			++expression;
		}
		else
			if(*expression!='('&& *expression != ')'&& *expression != '+'&& *expression != '-'&& *expression != '*'&& *expression != '/')
			{
				value=FindID(elem,*expression);
				++expression;
				return VELUE;
			}
		switch (*expression)
		{
		case '(':
		{
			++expression;
			return OPAREN;
		}
		case ')':
		{
			++expression;
			return CPAREN;
		}
		case '+':
		{
			++expression;
			return ADD;
		}
		case '-':
		{
			++expression;
			return SUB;
		}
		case '*':
		{
			++expression;
			return MULTI;
		}
		case '/':
		{
			++expression;
			return DIV;
		}
		default:
			break;
		}
	}
	return EOL;
}


Complex clac::result()
{
	token lastOp, topOp;
	Complex result_value,Current_Value;
	stack<token>opStack;
	stack<Complex>dataStack;
	char * str = expression;

	while (1)
	{
		lastOp = getop(Current_Value);
		if (lastOp == EOL)
		{
			break;
		}
		switch (lastOp)
		{
		case VELUE:
		{
			dataStack.push(Current_Value);
			break;
		}
		case CPAREN:
		{
			while (!opStack.empty() && (topOp = opStack.top()) != OPAREN)
			{
				opStack.pop();
				BrinaryOp(topOp, dataStack);
			}
			opStack.pop();
			if (topOp != OPAREN)
			{
				cout << "È±×óÀ¨ºÅ£¡" << endl;
			}
			break;
		}
		case OPAREN:
		{
			opStack.push(OPAREN);
			break;
		}
		case MULTI:
		{
		case DIV:
		{
			while (!opStack.empty() && opStack.top() >= MULTI)
			{
				BrinaryOp(opStack.top(), dataStack);
				opStack.pop();
			}
			opStack.push(lastOp);
			break;
		}
		}
		case ADD:
		{
		case SUB:
		{
			while (!opStack.empty() && opStack.top() != OPAREN)
			{
				BrinaryOp(opStack.top(), dataStack);
				opStack.pop();
			}
			opStack.push(lastOp);
			break;
		}
		}
		default:
			break;
		}
	}
	while (!opStack.empty())
	{
		BrinaryOp(opStack.top(), dataStack);
		opStack.pop();
	}
	if (dataStack.empty())
	{
		cout << "ÎÞ½á¹û\n";
		return (0);
	}
	result_value = dataStack.top();
	dataStack.pop();
	if (!dataStack.empty())
	{
		cout << " È±²Ù×÷·û";
		return (0);
	}
	expression = str;
	return (result_value);
}

inline Complex clac::FindID(const Node * n,const char &ch)
{

	for (int i = 0; i < size; i++)
	{
		if (n[i].name == ch)
		{
			return(n[i].data);
		}
	}
	return (0);
}
