#include <iostream>

#define INVALID				0
#define END_OF_FILE			1
#define OPERATOR_PLUS		256
#define OPERATOR_MINUS		257
#define OPERATOR_MULTIPLY	258
#define OPERATOR_DIVIDE		259
#define NUMBER				128
#define OPENING_PARENTHESIS 129
#define CLOSING_PARENTHESIS 130

using namespace std;

/// A token to be identified by Lexer. 
/// Each token has a number of attribute, to define what it is, which values it contains.
class Token
{
private:
	int type;
	int value;

public:
	Token() : type(INVALID), value(0) {};
	Token(int type) : type(type), value(0) {};
	
	void setType(int type) { this->type = type; }
	int getType() { return type; }

	void setValue(int value) { this->value = value; }
	int getValue() { return value; }

	bool isOpeningParenthesis()
	{
		return type == OPENING_PARENTHESIS;
	};

	bool isClosingParenthesis()
	{
		return type == CLOSING_PARENTHESIS;
	};

	bool isPlus()
	{
		return type == OPERATOR_PLUS;
	};

	bool isMinus()
	{
		return type == OPERATOR_MINUS;
	};

	bool isMultiply()
	{
		return type == OPERATOR_MULTIPLY;
	};

	bool isDivide()
	{
		return type == OPERATOR_DIVIDE;
	};

	bool isNumber()
	{
		return type == NUMBER;
	};

	void display()
	{
		switch (type)
		{
		case OPENING_PARENTHESIS:
			cout << "(";
			break;
		case CLOSING_PARENTHESIS:
			cout << ")";
			break;
		case OPERATOR_PLUS:
			cout << "+ ";
			break;
		case OPERATOR_MINUS:
			cout << "- ";
			break;
		case OPERATOR_MULTIPLY:
			cout << "x ";
			break;
		case OPERATOR_DIVIDE:
			cout << ": ";
			break;
		case NUMBER:
			cout << value << " ";
			break;
		}
	};
};