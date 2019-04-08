#include "pch.h"
#include "Operations.h"


Operations::Operations()
{

}


Operations::~Operations()
{
}



/**
	Changes a CHAR ASCII number to integer number.

	@param character to be changed into an integer.
	@return the number turned into integer data type
*/
int Operations::getNumber(char Number) {


	return Number - '0';

}



/**
	Returns the order of operation depending on the operator..

	@param character to be checked.
	@return The order of operation.
*/
int Operations::orderOperation(char op) {

	int order = 0;
	switch (op)
	{
	case '+':
		order = 1;
		break;
	case '-':
		order = 1;
		break;
	case '*':
		order = 2;
		break;
	case '/':
		order = 3;
		break;
	}
	return order;
}


/**
	Does corresponding operation to the two values being passed.

	@param First value, second value and the character of the operation to be done.
	@return The result of the values being passed.
*/
int Operations::applyOperator(int value1, int value2, char op) {

	switch (op)
	{
	case '+':
		return value1 + value2;

	case '-':
		return value1 - value2;

	case '*':
		return value1 * value2;

	case '/':
		return value1 / value2;


	}
}

/**
	Goes through the whole string doing corresponding calls to utilities functions.

	@param string where operation needs to be done.
	@return The result of the equation in the right order.
*/
	double Operations::doMath(string equation) {

	stack<char> symbols;
	stack <int> numbers;
	bool negative = false;


	for (size_t i = 0; i < equation.length(); i++)
	{
		if (isspace(equation[i]))
		{
			continue;
		}

		else if (i == 0 && equation[i] == '-')
		{
			if (equation[i + 1] == ' ') {
				i++;
			}
			else
			{
				negative = true;
				continue;
			}

		}
		else if (equation[i] == '-' && equation[i + 1] == '-')
		{
			symbols.push('+');
			
			i++;


		}
		else if (equation[i] == '+' && equation[i + 1] == '-')
		{
			symbols.push('+');
			negative = true;
			i++;

		}
		else if (equation[i] == '/' && equation[i + 1] == '-')
		{
			symbols.push('/');
			negative = true;
			i++;

		}
		else if (equation[i] == '*' && equation[i + 1] == '-')
		{
			symbols.push('*');
			negative = true;
			i++;

		}
		else if (equation[i] == '/' && equation[i + 1] == '0') {
			cout << " You cant divide by 0\n";
		}


		else if (equation[i] == '(')
		{
			symbols.push(equation[i]);
		}

		else if (isdigit(equation[i]))
		{
			int value = 0;
			value = (value * 10) + getNumber(equation[i]);
			while (i < equation.length() && isdigit(equation[i + 1]))
			{

				value = (value * 10) + getNumber(equation[i + 1]);
				i++;

			}
			if (negative == true)
			{
				numbers.push(value*-1);
				negative = false;
			}
			else
			{
				numbers.push(value);
				//negative = false;
			}

		}
		else if (equation[i] == ')')
		{
			while (!symbols.empty() && symbols.top() != '(')
			{
				int value2 = numbers.top();
				numbers.pop();
				int value1 = numbers.top();
				numbers.pop();
				char op = symbols.top();
				symbols.pop();

				numbers.push(applyOperator(value1, value2, op));

			}
			symbols.pop();
		}
		else
		{
			
			while (!symbols.empty() && orderOperation(symbols.top()) >= orderOperation(equation[i]) && negative == false)
			{

				int value2 = numbers.top();
				numbers.pop();
				int value1 = numbers.top();
				numbers.pop();
				char op = symbols.top();
				symbols.pop();

				numbers.push(applyOperator(value1, value2, op));

			}
			symbols.push(equation[i]);
		}
	}

	while (!symbols.empty())
	{

		int value2 = numbers.top();
		numbers.pop();
		int value1 = numbers.top();
		numbers.pop();
		char op = symbols.top();
		symbols.pop();


		numbers.push(applyOperator(value1, value2, op));
	}

	return numbers.top();
}