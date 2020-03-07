#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "LowPassFilter.h"

constexpr auto M_PI = ((float)3.14159);
using namespace std;

int main()
{
    float tSample = (float)0.01;
    float w_c = (float)10.0 * (float)2.0 * M_PI;
    LowPassFilter lpf(w_c, tSample);

    int N = 200;
    vector<float> t(N), outFilter(N), data(N);

    ofstream outfile;
    outfile.open("data.csv", ios::out | ios::trunc);
    outfile << "time,unfiltered data,filtered data" << endl;

    for (int i = 0; i < N; i++)
    {
        data[i] = (float)sin((double)i * tSample * 2 * M_PI * (float)1.0) +
            (float)0.2 * (float)sin((float)i * tSample * 2 * M_PI * (float)30.0) +
            (float)0.2 * (float)sin((float)i * tSample * 2 * M_PI * (float)10.0);
        t[i] = (float)i * tSample;
        lpf.update(data[i]);
        outfile << t[i] << "," << data[i] << "," << lpf.getFilterOutput() << endl;
    }
    outfile.close();
}