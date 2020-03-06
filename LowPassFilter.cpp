#include "LowPassFilter.h"
#include <iostream>
using namespace std;

LowPassFilter::LowPassFilter(float cutoffFreq, float samplingTime)
{
	if (cutoffFreq < float(0.0))
	{
		wCutoff = float(0.0);
		cout << "cut-off frequency value of the low-pass filter must be greater than 0" << endl;
		cout << "setting cut-off frequency of the low-pass filter as 0.0" << endl;
	} else
	{
		wCutoff = cutoffFreq;
	}

	if (samplingTime < float(0.0))
	{
		samplingTime = float(0.001);
		cout << "sampling-time of the low-pass filter must be greater than 0.0" << endl;
		cout << "setting sampling-time of the low-pass filter as 0.001" << endl;
	} else
	{
		tSample = samplingTime;
	}

	output = float(0.0);
	prevOutput = float(0.0);
	alpha = wCutoff * tSample / (1 + wCutoff * tSample);
}

LowPassFilter::~LowPassFilter()
{

}

void LowPassFilter::update(float input)
{
	output = input * alpha + (float(1.0) - alpha) * prevOutput;
	prevOutput = output;
}

float LowPassFilter::getFilterOutput()
{
	return(output);
}

void LowPassFilter::reconfigure(float cutoffFreq, float samplingTime)
{
	if (cutoffFreq < float(0.0))
	{
		wCutoff = float(0.0);
		cout << "cut-off frequency value of the low-pass filter must be greater than 0" << endl;
		cout << "setting cut-off frequency of the low-pass filter as 0.0" << endl;
	}
	else
	{
		wCutoff = cutoffFreq;
	}

	if (samplingTime < float(0.0))
	{
		samplingTime = float(0.001);
		cout << "sampling-time of the low-pass filter must be greater than 0.0" << endl;
		cout << "setting sampling-time of the low-pass filter as 0.001" << endl;
	}
	else
	{
		tSample = samplingTime;
	}

	output = float(0.0);
	prevOutput = float(0.0);
	alpha = wCutoff * tSample / (1 + wCutoff * tSample);
}