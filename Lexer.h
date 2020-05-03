#include "Token.h"

class Lexer
{
private:
	char* pOriginal;
	char* pLookahead;
	void skipWhiteSpaces();

public:
	Lexer(char* pLookahead) : pOriginal(pLookahead), pLookahead(pLookahead) {};
	Token nextToken();
	void retract();
};