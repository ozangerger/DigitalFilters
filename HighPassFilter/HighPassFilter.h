#pragma once
class HighPassFilter
{
public:
	HighPassFilter(float cutoffFreq = 1.0, float samplingTime = 0.01);
	~HighPassFilter();
	void update(float input = 0.0);
	void reconfigure(float cutoffFreq = 1.0, float samplingTime = 0.01);
	float getFilterOutput();

private:
	float tSample;
	float wCutoff;
	float alpha;
	float prevOutput;
	float output;
	float prevInput;
};

