#include "HanningFilter.h"
#include <iostream>
using namespace std;

HanningFilter::HanningFilter()
{
	output = float(0.0);
	prevInput = float(0.0);
	prevPrevInput = float(0.0);
}

HanningFilter::~HanningFilter()
{

}

void HanningFilter::update(float input)
{
	output = (float)0.25 * ((float)1.0 * input + (float)2.0 * prevInput + (float)1.0 * prevPrevInput);
	prevPrevInput = prevInput;
	prevInput = input;
}

float HanningFilter::getFilterOutput()
{
	return(output);
}