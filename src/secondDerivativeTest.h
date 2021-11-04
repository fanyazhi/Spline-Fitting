/*
 *  test.h
 *  SplineFitting
 *  This file contains test and validation method
 */

#ifndef SPLINEFITTING_TEST_H
#define SPLINEFITTING_TEST_H

#include "CRSmatrix.h"
#include "cubicSpline.h"

// ----------------------------------------------------------------------------------------

/* test if qy(qx) has continuous second derivative
   the test first calculates the second derivative at each point
   and then compare each derivative with its two neighbors,
   if the difference is less than a threshold (currently 1E-7), then
   qy(qx) is C-2 continuous.
        Parameters:
                qx: x value points
                qy: y values points
        Return:
                N/A
*/
void secondDerivativeTest(std::vector<double> qx, std::vector<double> qy);

#endif  //SPLINEFITTING_TEST_H