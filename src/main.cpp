/*
 *  main.cpp
 *  SplineFitting
 *  This file contains an example usage of the spline fitting method
 *  Please change the file path for own use
 *
 *  Created by Yazhi Fan (yf92) and Yijia Chen (yc2366) on 5/10/18.
 *  Copyright © 2018 Yazhi and Yijia. All rights reserved.
 *
 */

#include <iostream>
#include <vector>
#include "cubicSpline.h"
#include "CRSmatrix.h"
#include "test.h"

using namespace std;

// ----------------------------------------------------------------------------------------

int main() {

    //initialize known x and y points
    vector<double> x;
    vector<double> y;
    x = constructVariables("/Users/Jane_Fan/Desktop/xcircle.csv");
    y = constructVariables("/Users/Jane_Fan/Desktop/ycircle.csv");

    //initialize qx and qy for extraction
    int points = 10000;
    vector<double> qx(points);
    vector<double> qy(points);

    //call cubic spline
    cubicSpline(x, y, qx, qy);

    //test for continuous second derivative
    secondDerivativeTest(qx, qy);

    return 0;
}