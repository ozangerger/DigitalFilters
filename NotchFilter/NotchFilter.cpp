#include "NotchFilter.h"
#include <iostream>
using namespace std;

NotchFilter::NotchFilter(float cutoffFreq, float a, float samplingTime)
{
	if (cutoffFreq < float(0.0))
	{
		wCutoff = float(0.0);
		cout << "cut-off frequency value of the notch filter must be greater than 0" << endl;
		cout << "setting cut-off frequency of the notch filter as 0.0" << endl;
	} else
	{
		wCutoff = cutoffFreq;
	}

	if (samplingTime < float(0.0))
	{
		samplingTime = float(0.001);
		cout << "sampling-time of the notch filter must be greater than 0.0" << endl;
		cout << "setting sampling-time of the notch filter as 0.001" << endl;
	} else
	{
		tSample = samplingTime;
	}

	if (a < float(0.001))
	{
		aFilter = float(0.001);
		cout << "bandwidth parameter of the notch filter must be greater than 0.001" << endl;
		cout << "setting bandwidth parameter of the notch filter as 0.001" << endl;
	}
	else if (a > float(0.999))
	{
		aFilter = float(0.999);
		cout << "bandwidth parameter of the notch filter must be less than 0.999" << endl;
		cout << "setting bandwidth parameter of the notch filter as 0.999" << endl;
	}
	else
	{
		aFilter = a;
	}

	output = float(0.0);
	prevOutput = float(0.0);
	prevPrevOutput = float(0.0);
	prevInput = float(0.0);
	prevPrevInput = float(0.0);
	wNatural = wCutoff * tSample;
}

NotchFilter::~NotchFilter()
{

}

void NotchFilter::update(float input)
{
	//y[k] = (1+a)/2 * [u(k) -2 * cos_w_n * u(k-1) + u(k-2)] + 2 * a * cos_w_n * y(k-1) - a^2 * y(k-2)
	output = ((float)1.0 + aFilter) / (float)2.0 * (input - (float)2.0 * (float)cos(wNatural) * prevInput + prevPrevInput) 
		+ 2 * aFilter * (float)cos(wNatural) * prevOutput - (float)pow((double)aFilter, 2.0) * prevPrevOutput;

	prevPrevOutput = prevOutput;
	prevOutput = output;
	prevPrevInput = prevInput;
	prevInput = input;
}

float NotchFilter::getFilterOutput()
{
	return(output);
}

void NotchFilter::reconfigure(float cutoffFreq, float a, float samplingTime)
{
	if (cutoffFreq < float(0.0))
	{
		wCutoff = float(0.0);
		cout << "cut-off frequency value of the notch filter must be greater than 0.0" << endl;
		cout << "setting cut-off frequency of the notch filter as 0.0" << endl;
	}
	else
	{
		wCutoff = cutoffFreq;
	}

	if (samplingTime < float(0.001))
	{
		samplingTime = float(0.001);
		cout << "sampling-time of the notch filter must be greater than 0.001" << endl;
		cout << "setting sampling-time of the notch filter as 0.001" << endl;
	}
	else
	{
		tSample = samplingTime;
	}

	if (a < float(0.001))
	{
		aFilter = float(0.001);
		cout << "bandwidth parameter of the notch filter must be greater than 0.001" << endl;
		cout << "setting bandwidth parameter of the notch filter as 0.001" << endl;
	}
	else if (a > float(0.999))
	{
		aFilter = float(0.999);
		cout << "bandwidth parameter of the notch filter must be less than 0.999" << endl;
		cout << "setting bandwidth parameter of the notch filter as 0.999" << endl;
	}
	else
	{
		aFilter = a;
	}

	output = float(0.0);
	prevOutput = float(0.0);
	prevPrevOutput = float(0.0);
	prevInput = float(0.0);
	prevPrevInput = float(0.0);
	wNatural = wCutoff * tSample;
}