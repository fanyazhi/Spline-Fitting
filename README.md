# Spline-Fitting

WIP 

c++ spline fitting ver 2.0

The Spline Fitting program was originally the final project I wrote for ECE 4960, one of the most useful course I took at Cornell in 2018. All assignments in this course were written from scratch. 

In version 2.0, I will add in examples, make the coding style better, and add more documentations, and integrate it with Raylib for better visual validations/GUI. 

I also removed the time tracking / profiling for each major function. Those can be found in the orginal version 1.0 (it uses clock() which doesn't work on windows). 

## Features:
* Monotonic spline fitting
* Non-monotonic spline fitting (first degree complexity enclosed shapes possible)
* Ability to solve large amount of anchor points (solves derivative function with row compressed storage matrix format)
* Anchor points can be created by reading csv files.

## A little bit of the math background:

**Spline**


