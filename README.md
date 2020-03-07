# DigitalFilters
This library will contain selection of digital filter functions implemented in C++.
 
For the beginning, first order low-pass filter, notch filter and hanning filter have been implemented and tested.

In Figure 1, combination of three discrete sine waves are filtered with Ts = 0.01 seconds and w_c = 10 * 2 * PI rad/s.

In Figures 2, 3, 4 and 5, pure sine waves which have an amplitude of 2.0 and sampling time of 0.01 seconds filtered by notch filters which have different bandwidth parameters and notch frequency of w_c = 1 * 2 * PI rad/s. The effect of bandwidth parameter on the precision and response of the filter can be observed. In addition to this, the effect of corner frequency can be also clearly seen. If the corner frequency of the filter is set close to sine wave frequency, sine wave is almost flattened. Further experiments can be made by using combination of multiple sine waves at different frequencies.

In Figure 6, combination of two discrete sine waves are filtered with hanning filter which averages 3 consecutive inputs to the filter.

# Low-pass Filter Example
![Example](/LowPassFilter/example.png)
<p align="center">Figure 1: Filtered and unfiltered signals</p>

# Notch Filter Examples
![Example](/NotchFilter/example_1hz_0p25.png)
<p align="center">Figure 2: Filtered and unfiltered 1Hz sine signal, filter bandwidth parameter = 0.25 </p>

![Example](/NotchFilter/example_1hz_0p98.png)
<p align="center">Figure 3: Filtered and unfiltered 1Hz sine signal, filter bandwidth parameter = 0.98 </p>

![Example](/NotchFilter/example_5hz_0p25.png)
<p align="center">Figure 4: Filtered and unfiltered 5Hz sine signal, filter bandwidth parameter = 0.25 </p>

![Example](/NotchFilter/example_5hz_0p98.png)
<p align="center">Figure 5: Filtered and unfiltered 5Hz sine signal, filter bandwidth parameter = 0.98 </p>

# Hanning Filter Example
![Example](/HanningFilter/example.png)
<p align="center">Figure 6: Filtered and unfiltered signals</p>
