# DigitalFilters
This library will contain selection of digital filter functions implemented in C++.
 
For the beginning, low-pass filter, high-pass filter, notch filter and hanning filters have been implemented and tested.

Hanning filter outputs a signal which is a scaled average of three successive inputs, with the centre point of the three weighted twice as heavily as its two adjacent neighbours.

In Figure 1, combination of three discrete sine waves are filtered with Ts = 0.01 seconds and w_c = 10 * 2 * PI rad/s.

In Figure 2 and 3, combination of two discrete sine waves are filtered with Ts = 0.01 seconds and w_c = 12 * 2 * PI rad/s. Sine wave which has lower frequency is almost filtered out.

In Figures 4, 5, 6 and 7, pure sine waves which have an amplitude of 2.0 and sampling time of 0.01 seconds filtered by notch filters which have different bandwidth parameters and notch frequency of w_c = 1 * 2 * PI rad/s. The effect of bandwidth parameter on the precision and response of the filter can be observed. In addition to this, the effect of corner frequency can be also clearly seen. If the corner frequency of the filter is set close to sine wave frequency, sine wave is almost flattened. Further experiments can be made by using combination of multiple sine waves at different frequencies.

In Figure 8, combination of two discrete sine waves are filtered with hanning filter which averages 3 consecutive inputs to the filter.

# Low-pass Filter Example
![Example](/LowPassFilter/example.png)
<p align="center">Figure 1: Filtered and unfiltered signals</p>

# High-pass Filter Example
![Example](/HighPassFilter/example_sine_1hz_and_15hz_wc_12hz.png)
<p align="center">Figure 2: Filtered and unfiltered signals, w_sine1 = 1Hz, w_sine2 = 15Hz, w_c = 12Hz</p>

![Example](/HighPassFilter/example_sine_1hz_and_40hz_wc_15hz.png)
<p align="center">Figure 3: Filtered and unfiltered signals, w_sine1 = 1Hz, w_sine2 = 40Hz, w_c = 15Hz</p>

# Notch Filter Examples
![Example](/NotchFilter/example_1hz_0p25.png)
<p align="center">Figure 4: Filtered and unfiltered 1Hz sine signal, filter bandwidth parameter = 0.25 </p>

![Example](/NotchFilter/example_1hz_0p98.png)
<p align="center">Figure 5: Filtered and unfiltered 1Hz sine signal, filter bandwidth parameter = 0.98 </p>

![Example](/NotchFilter/example_5hz_0p25.png)
<p align="center">Figure 6: Filtered and unfiltered 5Hz sine signal, filter bandwidth parameter = 0.25 </p>

![Example](/NotchFilter/example_5hz_0p98.png)
<p align="center">Figure 7: Filtered and unfiltered 5Hz sine signal, filter bandwidth parameter = 0.98 </p>

# Hanning Filter Example
![Example](/HanningFilter/example.png)
<p align="center">Figure 8: Filtered and unfiltered signals</p>
