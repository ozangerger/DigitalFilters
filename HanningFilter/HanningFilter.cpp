#include "HanningFilter.h"
#include <iostream>
using namespace std;

void HanningFilter::Update(float input)
{
	output = 0.25F * (input + 2.0F * prevInputs[0] + prevInputs[1]);
	prevInputs[1] = prevInputs[0];
    prevInputs[0] = input;
}

float HanningFilter::GetOutput()
{
	return output;
}