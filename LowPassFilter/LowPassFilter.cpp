#include "LowPassFilter.h"
#include <iostream>

using namespace std;

LowPassFilter::LowPassFilter(float cutoffFreq, float samplingTime) {
    this->ParamCheck(cutoffFreq, samplingTime);
    this->CalculateAlpha();
}

void LowPassFilter::Update(float input) {
    data.output = input * params.alpha + (1.0F - params.alpha) * data.prevOutput;
    data.prevOutput = data.output;
}

void LowPassFilter::Reconfigure(float cutoffFreq, float samplingTime) {
    this->data = {};
    this->ParamCheck(cutoffFreq, samplingTime);
    this->CalculateAlpha();
}

void LowPassFilter::CalculateAlpha() {
    params.alpha = params.wCutoff * params.tSample / (1.0F + params.wCutoff * params.tSample);
}

void LowPassFilter::ParamCheck(float cutoffFreq, float samplingTime) {
    if (cutoffFreq < 0.0F) {
        params.wCutoff = 0.01F;
        cout << "cut-off frequency value of the low-pass filter must be greater than 0" << endl;
        cout << "setting cut-off frequency of the low-pass filter as " << params.wCutoff << endl;
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

float LowPassFilter::GetOutput() {
    return data.output;
}
