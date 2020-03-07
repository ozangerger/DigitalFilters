#pragma once
class NotchFilter
{
public:
	NotchFilter(float cutoffFreq = 1.0, float a = 0.5, float samplingTime = 0.01);
	~NotchFilter();
	void update(float input = 0.0);
	void reconfigure(float cutoffFreq = 1.0, float a = 0.5, float samplingTime = 0.01);
	float getFilterOutput();

private:
	float tSample;
	float wCutoff;
	float wNatural;
	float aFilter;
	float output;
	float prevOutput;
	float prevPrevOutput;
	float prevInput;
	float prevPrevInput;
};