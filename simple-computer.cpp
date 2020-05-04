/// simple-computer.cpp : The following program accepts expression of simple operations and digits.
/// It accepts:
/// - multi-digit numbers
/// - simple operators: addition, substraction, multiplication, division
/// - parenthesis for precedence order
/// The program parses the input expression, displays its postfix form together with the final result.

#include "simple-computer.h"
#include "Lexer.h"
#include <stack>

using namespace std;

/* global variables */
Lexer* pLexer;
stack<int> resultStack;

/* function declarations */
void expr();
void recursiveExpr();
void term();
void recursiveTerm();
void factor();
void fail();

/* main program */
int main(int argc, char* argv[])
{
	pLexer = new Lexer(argv[1]);

	// process the whole input as expr
	expr();

	// display result
	cout << endl  << "Result: " << resultStack.top() << endl;

	// clean the dynamic pointer
	delete pLexer;
	return 0;
}

/// Grammar: 
/// expr -> term recursiveExpr
void expr()
{
	term();
	recursiveExpr();
}

/// Grammar: 
/// recursiveExpr -> + term recursiveExpr
/// recursiveExpr -> - term recursiveExpr
/// recursiveExpr -> {null}
void recursiveExpr()
{
	while (true)
	{
		Token token = pLexer->nextToken();
		if (token.isPlus())
		{
			term();
			int arg2 = resultStack.top();
			resultStack.pop();
			int arg1 = resultStack.top();
			resultStack.pop();
			resultStack.push(arg1 + arg2);
			token.display();
		}
		else if (token.isMinus())
		{
			term();
			int arg2 = resultStack.top();
			resultStack.pop();
			int arg1 = resultStack.top();
			resultStack.pop();
			resultStack.push(arg1 - arg2);
			token.display();
		}
		else
		{
			// if the token is not null, we have to retract
			pLexer->retract();
			break;
		}
	}
}

/// Grammar: 
/// term -> factor recursiveTerm
void term()
{
	factor();
	recursiveTerm();
}

/// Grammar:
/// recursiveTerm -> * factor recursiveTerm
/// recursiveTerm -> / factor recursiveTerm
/// recursiveTerm -> {null}
void recursiveTerm()
{
	while (true)
	{
		Token token = pLexer->nextToken();
		if (token.isMultiply())
		{
			factor();
			int arg2 = resultStack.top();
			resultStack.pop();
			int arg1 = resultStack.top();
			resultStack.pop();
			resultStack.push(arg1 * arg2);
			token.display();
		}
		else if (token.isDivide())
		{
			factor();
			int arg2 = resultStack.top();
			resultStack.pop();
			int arg1 = resultStack.top();
			resultStack.pop();
			resultStack.push(arg1 / arg2);
			token.display();
		}
		else
		{
			// if the token is not null, we have to retract
			pLexer->retract();
			break;
		}
	}
}

/// Grammar:
/// factor -> ( expr )
/// factor -> number
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
		resultStack.push(token.getValue());
		token.display();
	}
	else
	{
		fail();
	}
}

/// Report syntax failure and stop the program
void fail()
{
	cerr << "Syntax error!" << endl;
	exit(1);
}