# DigitalFilters
This library will contain selection of digital filter functions implemented in C++.
 
For the beginning, first order low-pass filter, notch filter and hanning filter have been implemented and tested.

In Figure 1, combination of three discrete sine waves are filtered with Ts = 0.01 seconds and w_c = 10 * 2 * PI rad/s.

In Figure 2, pure sine wave which has an amplitude of 2.0 and frequency of 1Hz with Ts = 0.01 seconds filtered by notch filter which has bandwidth parameter of 0.25 and notch frequency of w_c = 1 * 2 * PI rad/s. It can be clearly seen that the sine wave is almost filtered out.

In Figure 3, combination of two discrete sine waves are filtered with hanning filter which averages 3 consecutive inputs to the filter.

# Low-pass Filter Example
![Example](/LowPassFilter/example.png)
<p align="center">Figure 1: Filtered and unfiltered signals</p>

# Notch Filter Example
![Example](/NotchFilter/example.png)
<p align="center">Figure 1: Filtered and unfiltered signals</p>

# Hanning Filter Example
![Example](/HanningFilter/example.png)
<p align="center">Figure 1: Filtered and unfiltered signals</p>
