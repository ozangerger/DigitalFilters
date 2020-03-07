#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "HighPassFilter.h"

constexpr auto M_PI = ((float)3.14159);
using namespace std;

int main()
{
    float tSample = (float)0.001;
    float w_c = (float)15.0 * (float)2.0 * M_PI;
    HighPassFilter hpf(w_c, tSample);

    int N = 1000;
    vector<float> t(N), outFilter(N), data(N);

    ofstream outfile;
    outfile.open("data.csv", ios::out | ios::trunc);
    outfile << "time,unfiltered data,filtered data" << endl;

    for (int i = 0; i < N; i++)
    {
        data[i] = (float)0.5 * (float)sin((double)i * tSample * 2 * M_PI * (float)1.0) +
            (float)0.1 * (float)sin((float)i * tSample * 2 * M_PI * (float)40.0);
        t[i] = (float)i * tSample;
        hpf.update(data[i]);
        outfile << t[i] << "," << data[i] << "," << hpf.getFilterOutput() << endl;
    }
    outfile.close();
}