/*
 *  main.cpp
 *  SplineFitting
 *  This file shows an example usage of the spline fitting method.
 *  This example produces a smooth sinusoid curve with just 6 anchor points.
 */

#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

#include "src/CRSmatrix.h"
#include "src/cubicSpline.h"
#include "src/secondDerivativeTest.h"

int main() {
    //--------------------------------------------------------------------------------------
    // Step 1: construct the anchor points or read from file
    //--------------------------------------------------------------------------------------
    std::cout << "constructing the anchor points..." << std::endl;
    std::vector<double> x { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
    std::vector<double> y { 0.0, 1.0, 0.0, -1.0, 0.0, 1.0 };
    // std::vector<double> x = constructVariables("../examples/example_input_sine_x.csv");
    // std::vector<double> y = constructVariables("../examples/example_input_sine_y.csv");

    //--------------------------------------------------------------------------------------
    // Step 2: initialize amount of interpolated points you want to be returned
    //         higher number means smoother line
    //         initialize qx, qy for extraction
    //--------------------------------------------------------------------------------------
    int points = 500;
    std::vector<double> qx(points);
    std::vector<double> qy(points);

    //--------------------------------------------------------------------------------------
    // Step 3: perform cubic spline calculation
    //--------------------------------------------------------------------------------------
    std::cout << "calculating spline..." << std::endl;
    cubicSpline(x, y, qx, qy);

    //--------------------------------------------------------------------------------------
    // Optional: save result to output file
    //--------------------------------------------------------------------------------------
    std::ofstream outputFile_x("../examples/example_output_sine_x.csv");
    std::ostream_iterator<double> output_iterator_x(outputFile_x, "\n");
    std::copy(qx.begin(), qx.end(), output_iterator_x);
    outputFile_x.close();
    std::ofstream outputFile_y("../examples/example_output_sine_y.csv");
    std::ostream_iterator<double> output_iterator_y(outputFile_y, "\n");
    std::copy(qy.begin(), qy.end(), output_iterator_y);
    outputFile_y.close();

    //--------------------------------------------------------------------------------------
    // Optional: perform a continuous second derivative test to verify the result
    //--------------------------------------------------------------------------------------
    secondDerivativeTest(qx, qy);

    return 0;
}