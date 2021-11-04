# Spline-Fitting

WIP 

c++ spline fitting ver 2.0 (2021 Nov)

The Spline Fitting program was originally the final project I wrote for ECE 4960, one of the most useful course I took at Cornell in 2018. All assignments in this course were written from scratch. 

In version 2.0, I will add in examples, make the coding style better, and add more documentations. I will also add a Raylib integrated example, for visual validations.

I also removed the time tracking / profiling for each major function. Those can be found in the orginal version 1.0 (it uses clock() which doesn't work on windows). 

## Features:
* Monotonic spline fitting
* Non-monotonic spline fitting (first degree complexity enclosed shapes possible)
* Ability to solve large amount of anchor points (solves derivative function with row compressed storage matrix format)
* Anchor points can be created by reading external files.
* Second Derivative test and Raylib visual validation.

## How to compile this project:
* Simply use the make file under the depot root directory to compile the Spline Fitting console program
* Note that this depot contains another make file to compile the Raylib integrated example. This Raylib GUI app is a nice graphical validation for the Spline Fitting algorithm. Also note that this Raylib GUI app only contains limited functionalities (limited range of possible points because you can only select from screen, limited number of points because of hand cramp, etc...).
* If you want to compile the Raylib GUI app
1. Install Raylib (raylib_installer_v370.mingw.exe) from https://github.com/raysan5/raylib/releases
2. The default installation path should be C:/raylib/raylib. If you install to different path, change RAYLIB_PATH in makefile
3. use the make inside raylib-gui-app compile

## A little bit of the math background:

**Spline**


