// Calculator using the STL stack to do mathematical operations.

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


	cout << "Enter your equation: ";
	getline(cin, equation);



	cout << obj.doMath(equation);

}








