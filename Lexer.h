#include "Token.h"

/// A lexer that returns tokens by analyzing regular expressions of different tokens.
class Lexer
{
private:
	/// This pointer points to the first character of the token
	char* pOriginal;

	/// This pointer points to the last character of the token
	/// Combined with pOriginal, they allow us to retract
	char* pLookahead;

	/// Move both pointers to the next tokens by skipping whitespaces and tabs
	void skipWhiteSpaces();

public:
	Lexer(char* pLookahead) : pOriginal(pLookahead), pLookahead(pLookahead) {};

	/// Read and return the next tokens
	Token nextToken();

	/// Fall back to the previous token by resetting pLookahead to pOriginal.
	/// Only work once for every new token.
	void retract();
};