// simple-computer.cpp : The following program accepts expression of simple operations and digits.

#include "simple-computer.h"
#include "Lexer.h"

using namespace std;

// global variables
Lexer* pLexer;

// function declarations
void expr();
void recursiveExpr();
void term();
void recursiveTerm();
void factor();
void fail();

// main program
int main(int argc, char* argv[])
{
	pLexer = new Lexer(argv[1]);
	expr();
	cout << endl;
	delete pLexer;
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
		Token token = pLexer->nextToken();
		if (token.isPlus() || token.isMinus())
		{
			term();
			token.display();
		}
		else
		{
			pLexer->retract();
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
		Token token = pLexer->nextToken();
		if (token.isMultiply() || token.isDivide())
		{
			factor();
			token.display();
		}
		else
		{
			pLexer->retract();
			break;
		}
	}
}

void factor()
{
	Token token = pLexer->nextToken();
	if (token.isOpeningParenthesis())
	{
		token.display();

		// nested expression
		expr();
		
		token = pLexer->nextToken();
		if (!token.isClosingParenthesis())
		{
			fail();
		}
		token.display();
	}
	else if (token.isNumber())
	{
		token.display();
	}
	else
	{
		fail();
	}
}

void fail()
{
	cerr << "Syntax error!" << endl;
	exit(1);
}