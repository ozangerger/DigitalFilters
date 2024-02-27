#include "HighPassFilter.h"
#include <iostream>

using namespace std;

HighPassFilter::HighPassFilter(float cutoffFreq, float samplingTime) {
    this->ParamCheck(cutoffFreq, samplingTime);
    this->CalculateAlpha();
}

void HighPassFilter::Update(float input) {
    data.output = params.alpha * data.prevOutput + params.alpha * (input - data.prevInput);
    data.prevOutput = data.output;
    data.prevInput = input;
}

void HighPassFilter::Reconfigure(float cutoffFreq, float samplingTime) {
    this->data = {};
    this->ParamCheck(cutoffFreq, samplingTime);
    this->CalculateAlpha();
}

void HighPassFilter::CalculateAlpha() {
    params.alpha = 1.0F / (1.0F + params.tSample * params.wCutoff);
}

void HighPassFilter::ParamCheck(float cutoffFreq, float samplingTime) {
    if (cutoffFreq < 0.0F) {
        params.wCutoff = 0.01F;
        cout << "cut-off frequency value of the high-pass filter must be greater than 0" << endl;
        cout << "setting cut-off frequency of the high-pass filter as " << params.wCutoff << endl;
    } else {
        params.wCutoff = cutoffFreq;
    }

    if (samplingTime < 0.0F) {
        params.tSample = 0.001F;
        cout << "sampling-time of the low-pass filter must be greater than 0.0" << endl;
        cout << "setting sampling-time of the low-pass filter as " << params.tSample << endl;
    } else {
        params.tSample = samplingTime;
    }
}

float HighPassFilter::GetOutput() {
    return data.output;
}
