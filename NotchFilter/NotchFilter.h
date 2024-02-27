#ifndef NOTCH_FILTER_H
#define NOTCH_FILTER_H

class NotchFilter
{
public:
	NotchFilter() = delete;
	NotchFilter(float cutoffFreq, float a, float samplingTime);
	void Update(float input);
	void Reconfigure(float cutoffFreq, float a, float samplingTime);
	float GetOutput();

private:
    void CheckParams(float cutoffFreq, float a, float samplingTime);
    void CalculateWn();
    struct params {
        float tSample;
        float wCutoff;
        float wNatural;
        float aFilter;
    } params{};

    struct data {
        float output;
        float prevOutput[2];
        float prevInput[2];
    } data{};
};

#endif