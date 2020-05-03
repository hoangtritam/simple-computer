#include <iostream>
#include "Lexer.h"

using namespace std;

bool isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	return false;
}

void Lexer::skipWhiteSpaces()
{
	while (*pLookahead == ' ' || *pLookahead == '\t')
	{
		pLookahead++;
	}
	pOriginal = pLookahead;
}

Token Lexer::nextToken()
{
	skipWhiteSpaces();
	Token token;
	switch (*pLookahead)
	{
	case '(':
		token.setType(OPENING_PARENTHESIS);
		pLookahead++;
		break;
	case ')':
		token.setType(CLOSING_PARENTHESIS);
		pLookahead++;
		break;
	case '+':
		token.setType(OPERATOR_PLUS);
		pLookahead++;
		break;
	case '-':
		token.setType(OPERATOR_MINUS);
		pLookahead++;
		break;
	case '*':
		token.setType(OPERATOR_MULTIPLY);
		pLookahead++;
		break;
	case '/':
		token.setType(OPERATOR_DIVIDE);
		pLookahead++;
		break;
	case '\0':
		token.setType(END_OF_FILE);
		break;
	default:
		if (isDigit(*pLookahead))
		{
			int value(*pLookahead - '0');
			pLookahead++;
			while (isDigit(*pLookahead))
			{
				value = value * 10 + (*pLookahead - '0');
				pLookahead++;
			}
			token.setType(NUMBER);
			token.setValue(value);
		}
		else
		{
			cerr << "Character out of set: " << *pLookahead << endl;
		}
	}
	return token;
}

void Lexer::retract()
{
	pLookahead = pOriginal;
}