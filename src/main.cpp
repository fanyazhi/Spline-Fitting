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

    cout << "reading csv..." << endl; 
    //read the given x and y points
    vector<double> x = constructVariables("../examples/x.csv");
    vector<double> y = constructVariables("../examples/y.csv");

    for (auto i: x) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i: y) {
        cout << i << " ";
    }
    cout << endl;

    //initialize qx and qy for extraction
    int points = 10;
    vector<double> qx(points);
    vector<double> qy(points);

    cout << "calculating spline..." << endl;
    //call cubic spline
    cubicSpline(x, y, qx, qy);

    for (auto i: qx) {
        cout << i << " ";
    }
    cout << endl;
    for (auto i: qy) {
        cout << i << " ";
    }
    cout << endl;

    //test for continuous second derivative
    //secondDerivativeTest(qx, qy);

    return 0;
}