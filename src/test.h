/*
 *  test.h
 *  SplineFitting
 *  This file contains test and validation method
 *
 *  Created by Yazhi Fan (yf92) and Yijia Chen (yc2366) on 5/10/18.
 *  Copyright © 2018 Yazhi and Yijia. All rights reserved.
 *
 */

#ifndef SPLINEFITTING_TEST_H
#define SPLINEFITTING_TEST_H

#include "cubicSpline.h"
#include "CRSmatrix.h"

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
void secondDerivativeTest(vector<double> qx, vector<double> qy);


#endif //SPLINEFITTING_TEST_H