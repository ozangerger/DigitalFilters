cmake_minimum_required(VERSION 3.20)
project(DigitalFilters)

set(CMAKE_CXX_STANDARD 17)

include_directories(HanningFilter)
include_directories(HighPassFilter)
include_directories(LowPassFilter)
include_directories(NotchFilter)

add_executable(DigitalFilters
        HanningFilter/HanningFilter.cpp
        HanningFilter/HanningFilter.h
        HighPassFilter/HighPassFilter.cpp
        HighPassFilter/HighPassFilter.h
        LowPassFilter/LowPassFilter.cpp
        LowPassFilter/LowPassFilter.h
        NotchFilter/NotchFilter.cpp
        NotchFilter/NotchFilter.h
        main.cpp)
