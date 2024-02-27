//
// Created by Ozan Gerger on 27/02/2024.
//

#include "HanningFilter/HanningFilter.h"
#include "LowPassFilter/LowPassFilter.h"
#include "HighPassFilter/HighPassFilter.h"
#include "NotchFilter/NotchFilter.h"

#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

float rad_to_hz(float rad) {
    return rad * 2.0F * (float) M_PI;
}

float sinf_t(float amplitude, float freq, float t) {
    return amplitude * sinf(t * rad_to_hz(freq));
}

int main() {
    float tSample = 0.01F;
    HanningFilter hf;
    LowPassFilter lpf(rad_to_hz(10.0F), tSample);
    HighPassFilter hpf(rad_to_hz(50.0F), tSample);
    NotchFilter nf(rad_to_hz(2.5F), 0.25F, tSample);

    int N = 200;
    vector<float> t(N);
    vector<float> outFilter(N);
    vector<float> hf_data(N);
    vector<float> lpf_data(N);
    vector<float> hpf_data(N);
    vector<float> nf_data(N);

    ofstream outfile;
    outfile.open("data.csv", ios::out | ios::trunc);
    outfile << "time,hf_raw_data,hf_data";
    outfile << ",hpf_raw_data,hpf_data";
    outfile << ",lpf_raw_data,lpf_data";
    outfile << ",nf_raw_data,nf_data" << endl;

    for (int i = 0; i < N; i++) {
        t[i] = (float) i * tSample;
        hf_data[i] = sinf_t(2.0F, 1.0F, t[i]) +
                     sinf_t(0.25F, 15.0F, t[i]);
        hf.Update(hf_data[i]);

        hpf_data[i] = sinf_t(0.5F, 1.0F, t[i]) +
                      sinf_t(0.1F, 40.0F, t[i]);
        hpf.Update(hpf_data[i]);

        lpf_data[i] = sinf_t(0.5F, 1.0F, t[i]) +
                      sinf_t(0.1F, 20.0F, t[i]);
        lpf.Update(lpf_data[i]);

        nf_data[i] = sinf_t(2.0F, 5.0F, t[i]);
        nf.Update(nf_data[i]);

        outfile << t[i] << "," << hf_data[i] << "," << hf.GetOutput();
        outfile << "," << hpf_data[i] << "," << hpf.GetOutput();
        outfile << "," << lpf_data[i] << "," << lpf.GetOutput();
        outfile << "," << nf_data[i] << "," << nf.GetOutput() << endl;
    }

    outfile.close();
}
