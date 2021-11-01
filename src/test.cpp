/*
 *  test.cpp
 *  SplineFitting
 *  This file contains test and validation method
 *
 *  Created by Yazhi Fan (yf92) and Yijia Chen (yc2366) on 5/10/18.
 *  Copyright © 2018 Yazhi and Yijia. All rights reserved.
 *
 */

#include "test.h"
#include <cmath>

using namespace std;

void secondDerivativeTest(vector<double> qx, vector<double> qy){

    //first find the second derivative at each point
    vector<double> dydx2;
    for (int i = 1; i<qx.size()-1; i++){
        double Uxxi = qy[i+1]-2*qy[i]+qy[i-1];
        dydx2.push_back(Uxxi);
    }

    //compare each second derivative with its neighbors
    vector<double> diffDev;
    for (int i = 1; i<dydx2.size()-1; i++){
        double diff = abs(dydx2[i]-dydx2[i-1]) + abs(dydx2[i]-dydx2[i+1]);
        diffDev.push_back(diff);
    }

    //calculate vector norm of the difference
    double norm = vectorNorm(diffDev);
    double threshold = 1E-7;
    if (norm < threshold) {
        cout << "Resulting curve has continuous second drivative, : " << norm<<endl;
    } else {
        cout << "Resulting curve does not have continuous second drivative: " << norm<<endl;
        cout << "Current threshold is set at "<<threshold<<
             ", decrease threshold or add more points (>10000) may solve the issue."<<endl;
    }

}