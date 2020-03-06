#pragma once
class LowPassFilter
{
public:
	LowPassFilter(float cutoffFreq = 1.0, float samplingTime = 0.01);
	~LowPassFilter();
	void update(float input = 0.0);
	void reconfigure(float cutoffFreq = 1.0, float samplingTime = 0.01);
	float getFilterOutput();

private:
	float tSample;
	float wCutoff;
	float alpha;
	float prevOutput;
	float output;
};

