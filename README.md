# DigitalFilters

Pre-requisite to run examples with little effort:
- macos 14.2.1 / linux-ubuntu >= 18.04 (only tested in macos, but will likely to work on linux provided that the following packages are installed properly)
- cmake >= 3.20
- python >= 3.9
- matplotlib >= 3.7.1
- pandas >= 2.2.1

This library contains selection of digital filter functions implemented in C++.
 
As a starting point, low-pass filter, high-pass filter, notch filter and hanning filters have been implemented and examples are provided.

Hanning filter outputs a signal which is a scaled average of three successive inputs, with the centre point of the three weighted twice as heavily as its two adjacent neighbours.

In Figure 1 and 2, combination of two discrete sine waves are filtered with Ts = 0.01 seconds and w_c = 2 Hz and 10 Hz.

In Figure 3 and 4, combination of two discrete sine waves are filtered with Ts = 0.01 seconds, w_c = 35 Hz and 50 Hz. Sine wave which has lower frequency is almost filtered out.

In Figures 5, 6 and 7, pure sine waves which have an amplitude of 2.0 and sampling time of 0.01 seconds filtered by notch filters which have different bandwidth parameters and notch frequencies of w_c = 2.5 Hz and 5 Hz. The effect of bandwidth parameter on the precision and response of the filter can be observed. In addition to this, the effect of corner frequency can be also clearly observed. If the corner frequency of the filter is set to close to the sine wave frequency, sine wave is almost flattened. Further experiments are possible with the given main function. Play around with the parameters and have fun!

In Figure 8, combination of two discrete sine waves are filtered with hanning filter which averages 3 consecutive inputs to the filter.

# Low-pass Filter Example
![Example](/LowPassFilter/lpf_plot_2hz.png)
<p align="center">Figure 1: Filtered and unfiltered signals, inputs: w_sine1 = 1Hz + w_sine2 = 20Hz, w_c = 2Hz </p>

![Example](/LowPassFilter/lpf_plot_10hz.png)
<p align="center">Figure 2: Filtered and unfiltered signals, inputs: w_sine1 = 1Hz + w_sine2 = 20Hz, w_c = 10Hz </p>

# High-pass Filter Example
![Example](/HighPassFilter/hpf_plot_35hz.png)
<p align="center">Figure 3: Filtered and unfiltered signals, inputs: w_sine1 = 1Hz + w_sine2 = 40Hz, w_c = 35Hz</p>

![Example](/HighPassFilter/hpf_plot_50hz.png)
<p align="center">Figure 4: Filtered and unfiltered signals, inputs: w_sine1 = 1Hz + w_sine2 = 40Hz, w_c = 50Hz</p>

# Notch Filter Examples
![Example](/NotchFilter/nf_plot_2p5hz_0p25.png)
<p align="center">Figure 5: Filtered and unfiltered 2.5Hz sine signal, filter bandwidth parameter = 0.25 </p>

![Example](/NotchFilter/nf_plot_5hz_0p25.png)
<p align="center">Figure 6: Filtered and unfiltered 5.0Hz sine signal, filter bandwidth parameter = 0.25 </p>

![Example](/NotchFilter/nf_plot_5hz_0p98.png)
<p align="center">Figure 7: Filtered and unfiltered 5Hz sine signal, filter bandwidth parameter = 0.98 </p>

# Hanning Filter Example
![Example](/HanningFilter/hf_plot.png)
<p align="center">Figure 8: Filtered and unfiltered signals, inputs: w_sine1 = 1Hz + w_sine2 = 15Hz</p>
