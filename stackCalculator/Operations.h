#pragma once

#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Operations
{
public:
	Operations();
	~Operations();


	int getNumber(char Number);
	int orderOperation(char op);
	int applyOperator(int value1, int value2, char op);
	double doMath(string equation);
};