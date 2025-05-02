#pragma once

#include <sstream>

class Calculate
{
	public:
		Calculate();
		virtual ~Calculate();

		float process(std::string& input);

	//private:
	//	float add(float a, float b);
	//	float subtract(float a, float b);
	//	float multiply(float a, float b);
	//	float divide(float a, float b);

};