// simple-computer.cpp : The following program accepts expression of simple operations and digits.

#include "simple-computer.h"

using namespace std;

// global variables
char* pLookAhead;

// function declarations
void expr();
void recursiveExpr();
void term();
void recursiveTerm();
void factor();
void digit();
void forward();
bool match(char ch);
void fail();

// main program
int main(int argc, char* argv[])
{
	pLookAhead = argv[1];
	expr();
	cout << endl;
	return 0;
}

void expr()
{
	term();
	recursiveExpr();
}

void recursiveExpr()
{
	while (true)
	{
		char backup = *pLookAhead;
		if (match('+') || match('-'))
		{
			term();
			cout << backup;
		}
		else
		{
			break;
		}
	}
}

void term()
{
	factor();
	recursiveTerm();
}

void recursiveTerm()
{
	while (true)
	{
		char backup = *pLookAhead;
		if (match('*') || match('/'))
		{
			factor();
			cout << backup;
		}
		else
		{
			break;
		}
	}
}

void factor()
{
	if (match('('))
	{
		expr();
		if (!match(')'))
		{
			fail();
		}
	}
	else
	{
		digit();
	}
}

void digit()
{
	if (*pLookAhead < '0' || *pLookAhead > '9')
	{
		fail();
	}
	cout << *pLookAhead;
	forward();
}

bool match(char ch)
{
	if (*pLookAhead == ch)
	{
		forward();
		return true;
	}
	return false;
}

void forward()
{
	pLookAhead++;
}

void fail()
{
	cerr << endl << "Syntax error!" << endl;
	exit(1);
}