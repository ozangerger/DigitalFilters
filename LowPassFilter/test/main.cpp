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

    int N = 1000;
    vector<float> t(N), outFilter(N), data(N);

    ofstream outfile;
    outfile.open("data.csv", ios::out | ios::trunc);
    outfile << "time,unfiltered data,filtered data" << endl;

    for (int i = 0; i < N; i++)
    {
        data[i] = (float)sin((double)i * 0.1) + (float)2.0 * (float)sin((float)i * 0.1) + (float)0.5 * (float)sin((float)i * 1.0);
        t[i] = (float)i * tSample;
        lpf.update(data[i]);
        outfile << t[i] << "," << data[i] << "," << lpf.getFilterOutput() << endl;
    }
    outfile.close();
}