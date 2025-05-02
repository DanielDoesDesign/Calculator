#include "Calculate.h"

#include <iostream>
#include <string>
#include <sstream>

Calculate::Calculate()
{
}

Calculate::~Calculate()
{
}

float Calculate::process(std::string &input)
{
	std::istringstream iss(input);
	int lhs, rhs;
	char op;

	iss >> lhs >> op >> rhs;

	switch (op) {
		case '+': return lhs + rhs;
		case '-': return lhs - rhs;
		case '*': return lhs * rhs;
		case '/': 
			if (rhs == 0) {
				std::cerr << "Error: Division by zero\n";
				return 0;
			}
			return lhs / rhs;
		default:
			std::cerr << "Unknown operator: " << op << "\n";
			return 0;
	}
}