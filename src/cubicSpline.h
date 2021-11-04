/*
 *  cubicSpline.h
 *  SplineFitting
 *  This file contains cubic spline functions
 */

#ifndef SPLINEFITTING_CUBICSPLINE_H
#define SPLINEFITTING_CUBICSPLINE_H

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// ----------------------------------------------------------------------------------------

/* given a set of anchor points and the slope vector,
   find the y value corresponding to xi on the spline curve
        Parameters:
                i: interval index
                xi: x value
                x: x value anchor points
                y: y value anchor points
                k: slope vector
        Return:
                y value corresponding to xi on the spline curve
*/
double cubicPoint(int i, double xi, vector<double> x, vector<double> y, vector<double> k);

// ----------------------------------------------------------------------------------------

/* find the slope vector
        Parameters:
                d: dimension of slope vector
                x: x value anchor points
                y: y value anchor points
        Return:
                slope vector
*/
vector<double> splineDerivative(int d, vector<double> x, vector<double> y);

// ----------------------------------------------------------------------------------------

/* cubic spline method
        Parameters:
                x: x value anchor points
                y: y value anchor points
                qx: vector that stores the returned x values
                qy: vector that stores the returned y values
                NOTE - dimension of qx and qy must be initialized
                and this size will be the total number of points returned.
*/
void cubicSpline(vector<double> x, vector<double> y, vector<double> &qx, vector<double> &qy);

// ----------------------------------------------------------------------------------------

/* reads csv file at file path and put values into a vector
        Parameters:
                address: file path string
        Return:
                vector that contains the list values
*/
vector<double> constructVariables(string address);

#endif  //SPLINEFITTING_CUBICSPLINE_H