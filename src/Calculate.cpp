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

    //DAN: UPDATING FUNCTION TO ALLOW FOR MULTIPLE OPERATORS
    /* >> Stream extraction operator is used to read data from the stream, placed into a 
    loop, it is evaluating the string at different places, checking if there is more information to be 
    "extracted", these extracted values (the operator and whatever is to the right of it, is placed in variables), it then checks for the next part of the string that is "not extracted yet"?
    */

	std::istringstream iss(input);
	int result = 0;
    int num;
	char op;

    if (!(iss >> result)) {
        std::cerr << "Error: Invalid input\n";
        return 0;
    }

    while (iss >> op >> num)
    {
        switch (op) {
            case '+': result += num; 
                break;
            case '-': result -= num;
                break;
            case '*': result *= num;
                break;
            case '/': 
                if (num == 0) {
                    std::cerr << "Error: Division by zero\n";
                    return 0;
                }
                result /= num;
            default:
                std::cerr << "Unknown operator: " << op << "\n";
                return 0;
        }
    }

    return result;
}