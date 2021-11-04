/*
 *  secondDerivativeTest.cpp
 *  SplineFitting
 *  This file contains test and validation method
 */

#include "secondDerivativeTest.h"

#include <cmath>

void secondDerivativeTest(std::vector<double> qx, std::vector<double> qy) {
    //first find the second derivative at each point
    std::vector<double> dydx2;
    for (int i = 1; i < qx.size() - 1; i++) {
        double Uxxi = qy[i + 1] - 2 * qy[i] + qy[i - 1];
        dydx2.push_back(Uxxi);
    }

    //compare each second derivative with its neighbors
    std::vector<double> diffDev;
    for (int i = 1; i < dydx2.size() - 1; i++) {
        double diff = abs(dydx2[i] - dydx2[i - 1]) + abs(dydx2[i] - dydx2[i + 1]);
        diffDev.push_back(diff);
    }

    //calculate vector norm of the difference
    double norm = vectorNorm(diffDev);
    double threshold = 1E-7;
    if (norm < threshold) {
        std::cout << "Resulting curve has continuous second drivative, : " << norm << std::endl;
    } else {
        std::cout << "Resulting curve does not have continuous second drivative: " << norm << std::endl;
        std::cout << "Current threshold is set at " << threshold << ", decrease threshold or add more points (>10000) may solve the issue." << std::endl;
    }
}