// simple-computer.cpp : The following program accepts expression of simple operations and digits.

#include "simple-computer.h"

using namespace std;

char* pLookAhead;

void term();
void expr();
void forward();

int main(int argc, char* argv[])
{
	pLookAhead = argv[1];
	term();
	expr();
	cout << endl;
	return 0;
}

void term()
{
	if (*pLookAhead < '0' || *pLookAhead > '9')
	{
		cerr << "Syntax error!" << endl;
		exit(1);
	}
	cout << *pLookAhead;
	forward();
}

void expr()
{
	if (*pLookAhead == '+')
	{
		forward();
		term();
		expr();
		cout << '+';
	}
	else if (*pLookAhead == '-')
	{
		forward();
		term();
		expr();
		cout << '-';
	}
	else
	{
		return;
	}
}

void forward()
{
	pLookAhead++;
}