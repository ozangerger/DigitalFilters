#ifndef HANNING_FILTER_H
#define HANNING_FILTER_H

class HanningFilter
{
public:
	HanningFilter() = default;
	void Update(float input);
	float GetOutput();

private:
	float output{};
	float prevInputs[2]{};
};

#endif