#ifndef HIGHPASS_FILTER_H
#define HIGHPASS_FILTER_H

class HighPassFilter {
public:
    HighPassFilter() = delete;

    HighPassFilter(float cutoffFreq, float samplingTime);

    void Update(float input);

    void Reconfigure(float cutoffFreq, float samplingTime);

    float GetOutput();

private:
    void CalculateAlpha();

    void ParamCheck(float cutoffFreq, float samplingTime);

    struct params {
        float tSample;
        float wCutoff;
        float alpha;
    } params{};

    struct data {
        float prevOutput;
        float output;
        float prevInput;
    } data{};

};

#endif