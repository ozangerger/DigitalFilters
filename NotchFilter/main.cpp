#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "NotchFilter.h"

constexpr auto M_PI = ((float)3.14159);
using namespace std;

int main()
{
    float tSample = (float)0.01;
    float w_c = (float)1.0 * (float)2.0 * M_PI;
    float a = (float)0.25;
    NotchFilter nf(w_c, a, tSample);

    int N = 500;
    vector<float> t(N), outFilter(N), data(N);

    ofstream outfile;
    outfile.open("data.csv", ios::out | ios::trunc);
    outfile << "time,unfiltered data,filtered data" << endl;

    for (int i = 0; i < N; i++)
    {
        data[i] = (float)2.0 * (float)sin((float)i * tSample * 2 * M_PI * (float)5.0);
        t[i] = (float)i * tSample;
        nf.update(data[i]);
        outfile << t[i] << "," << data[i] << "," << nf.getFilterOutput() << endl;
    }

    outfile.close();
}