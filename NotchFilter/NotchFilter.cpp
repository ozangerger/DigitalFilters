#include "NotchFilter.h"
#include <iostream>
using namespace std;

NotchFilter::NotchFilter(float cutoffFreq, float a, float samplingTime)
{
    this->CheckParams(cutoffFreq, a, samplingTime);
	this->CalculateWn();
}

void NotchFilter::Update(float input)
{
	//y[k] = (1+a)/2 * [u(k) -2 * cos_w_n * u(k-1) + u(k-2)] + 2 * a * cos_w_n * y(k-1) - a^2 * y(k-2)
	data.output = ((1.0F + params.aFilter) / 2.0F) *
            (input - 2.0F * cosf(params.wNatural) * data.prevInput[0] + data.prevInput[1]) +
            2.0F * params.aFilter * cosf(params.wNatural) * data.prevOutput[0]
            - powf(params.aFilter, 2.0F) * data.prevOutput[1];

    data.prevOutput[1] = data.prevOutput[0];
	data.prevOutput[0] = data.output;
    data.prevInput[1] = data.prevInput[0];
	data.prevInput[0] = input;
}

void NotchFilter::Reconfigure(float cutoffFreq, float a, float samplingTime)
{
    this->data = {};
    this->CheckParams(cutoffFreq, a, samplingTime);
	this->CalculateWn();
}

void NotchFilter::CheckParams(float cutoffFreq, float a, float samplingTime)
{
    if (cutoffFreq < 0.0F) {
        params.wCutoff = 0.01F;
        cout << "cut-off frequency value of the notch filter must be greater than 0.0" << endl;
        cout << "setting cut-off frequency of the notch filter as " << params.wCutoff <<  endl;
    } else {
        params.wCutoff = cutoffFreq;
    }

    if (samplingTime < 0.0F) {
        params.tSample = 0.001F;
        cout << "sampling-time of the notch filter must be greater than 0.001" << endl;
        cout << "setting sampling-time of the notch filter as " << params.tSample << endl;
    } else {
        params.tSample = samplingTime;
    }

    if (a < 0.001F) {
        params.aFilter = 0.001F;
        cout << "bandwidth parameter of the notch filter must be greater than 0.001" << endl;
        cout << "setting bandwidth parameter of the notch filter as " << params.aFilter << endl;
    } else if (a > 0.999F) {
        params.aFilter = 0.999F;
        cout << "bandwidth parameter of the notch filter must be less than 0.999" << endl;
        cout << "setting bandwidth parameter of the notch filter as " << params.aFilter << endl;
    } else {
        params.aFilter = a;
    }
}

void NotchFilter::CalculateWn()
{
    params.wNatural = params.wCutoff * params.tSample;
}

float NotchFilter::GetOutput()
{
    return data.output;
}
