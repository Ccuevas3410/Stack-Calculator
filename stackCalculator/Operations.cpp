#include "pch.h"
#include "Operations.h"


Operations::Operations()
{

}


Operations::~Operations()
{
}


//FUNCTION TO GET THE INT VALUE OF CHARACTER
int Operations::getNumber(char Number) {


	return Number - '0';

}
//FUNCTION TO RETURN TRUE IF CHAR IS OPERATOR
bool Operations::isOperator(char op) {


	return (op == '+' || op == '-' || op == '/' || op == '*');

}
//FUNCTION TO TELL OPERATOR PRECEDENCE
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
		order = 2;
		break;
	}
	return order;
}

//FUNCTION TO APPLY OPERATOR TO EACH OPERATION
int Operations::applyOperator(double value1, double value2, char op) {

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
	default:
		break;

	}
}

//FUNCTION TO DO ALL THE LOGIC IN THE OPERATIONS
double Operations::doMath(string equation) {

	stack<char> symbols;
	stack <int> numbers;
	bool negative = false;


	for (int i = 0; i < equation.length(); i++)
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
				//	cout << value << "\n";
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
				negative = false;
			}

		}
		else if (equation[i] == ')')
		{
			while (!symbols.empty() && symbols.top() != '(')
			{
				double value2 = numbers.top();
				numbers.pop();
				double value1 = numbers.top();
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

				double value1 = numbers.top();
				numbers.pop();
				double value2 = numbers.top();
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