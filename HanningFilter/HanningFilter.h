#pragma once
class HanningFilter
{
public:
	HanningFilter();
	~HanningFilter();
	void update(float input = 0.0);
	float getFilterOutput();

private:
	float output;
	float prevInput;
	float prevPrevInput;
};