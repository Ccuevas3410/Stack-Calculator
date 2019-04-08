/**
	Purpose: Calculate an equation and determine order of operations using Stacks.

	@author Cristian Cuevas

*/

#include "pch.h"
#include "Operations.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	Operations obj;
	string equation = " ";

	do
	{
		cout << "Enter your equation or 'e' to exit:   ";
		getline(cin, equation);

		if (equation == "e")
		{
			return 0;
		}

		cout << obj.doMath(equation);
		cout << endl;
	} while (equation != "e");


}








