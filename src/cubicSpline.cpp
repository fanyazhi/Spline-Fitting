/*
 *  cubicSpline.cpp
 *  SplineFitting
 *  This file contains cubic spline functions
 *
 *  Created by Yazhi Fan (yf92) and Yijia Chen (yc2366) on 5/10/18.
 *  Copyright © 2018 Yazhi and Yijia. All rights reserved.
 *
 */

#include "cubicSpline.h"
#include "CRSmatrix.h"

using namespace std;

// ----------------------------------------------------------------------------------------

double cubicPoint(int i, double xi, vector<double> x, vector<double> y, vector<double> k) {
    double t = (xi-x[i-1]) / (x[i]-x[i-1]);
    double a = k[i-1]*(x[i]-x[i-1]) - (y[i]-y[i-1]);
    double b = -1.0*k[i]*(x[i]-x[i-1]) +(y[i]-y[i-1]);
    return (1-t)*y[i-1] + t*y[i] + t*(1-t)*(a*(1-t)+b*t);
}

vector<double> splineDerivative(int d, vector<double> x, vector<double> y) {
    //solve a[][]k[] = b[] to find frst derivatives
    vector<double> k(d);
    CRSmatrix a (d, d);
    vector<double> b(d);

    //first row
    a.changeValue(2.0/(x[1]-x[0]), 0, 0);
    a.changeValue(1.0/(x[1]-x[0]), 0, 1);
    b[0] = 3.0* (y[1]-y[0]) / pow((x[1]-x[0]),2);

    //middle rows
    for (int i = 1; i<d-1; i++) {
        a.changeValue(1.0/(x[i]-x[i-1]), i, i-1);
        a.changeValue(2.0* (1/(x[i]-x[i-1]) + 1/(x[i+1]-x[i])), i, i);
        a.changeValue(1.0/(x[i+1]-x[i]), i, i+1);
        b[i] = 3.0* ( ((y[i]-y[i-1]) / pow((x[i]-x[i-1]),2)) + ((y[i+1]-y[i]) / pow((x[i+1]-x[i]),2)));
    }

    //last row
    a.changeValue(1.0/(x[d-1]-x[d-2]), d-1, d-1);
    a.changeValue(2.0/(x[d-1]-x[d-2]), d-1, d-2);
    b[d-1] = 3.0* (y[d-1] - y[d-2]) / pow((x[d-1]-x[d-2]),2);

    k = Jacobi(a, b);

    return k;
}

void cubicSpline(vector<double> x, vector<double> y, vector<double> &qx, vector<double> &qy) {
    //initialize qx and qy for extraction
    qx[0] = x[0];
    qy[0] = y[0];

    //initialize variable t to breakdown a and y into monotonic functions
    vector<double> t(x.size());
    for (int i = 0; i<t.size(); i++){
        t[i] = i;
    }
    vector<double> qt(qx.size()); qt[0] = 0;
    for (int i = 1; i<qt.size(); i++){
        qt[i] = qt[i - 1] + 1.0*(t.size()-1) / qx.size();
    }

    int derivative_s=clock();   //derivative calculation start time

    //obtain derivatives
    vector<double> ky(qt.size());
    vector<double> kx(qt.size());
    ky = splineDerivative(t.size(), t, y);
    kx = splineDerivative(t.size(), t, x);

    int derivative_e=clock();

    cout << "slope function calculation completed in "
         << (derivative_e-derivative_s)/double(CLOCKS_PER_SEC)*1000 << "ms"<<endl;

    //if the first point and the last points are exactly the same, then the
    //curve is enclosed, and derivatives should match at the enclosure point
    double epislon = 1E-7;
    if ( (abs(x[0] - x[x.size()-1]) <epislon)
         && (abs(y[0] - y[y.size()-1]) <epislon) ) {
        ky[ky.size()-1] = ky[0];
        kx[kx.size()-1] = kx[0];
    }

    int spline_s=clock();   //derivative calculation start time

    for (int j = 1; j < qt.size(); j++) {
        int i = 0;
        while (t[i]<qt[j] && i<t.size()){
            i++;
        }
        qy[j] = cubicPoint(i , qt[j], t, y, ky);
        qx[j] = cubicPoint(i , qt[j], t, x, kx);
    }

    int spline_e=clock();

    cout << "spline interpolation completed in "
         << (spline_e-spline_s)/double(CLOCKS_PER_SEC)*1000 << "ms"<<endl;

}

vector<double> constructVariables (string address) {

    int file_s=clock();   //derivative calculation start time

    //initiate vector x to store all elements in file
    vector<double> x;

    ifstream inValue;
    inValue.open(address);

    //check if file is open, if not exit code
    if(!inValue.is_open()) {
        cout << "error: file did not open" << endl;
        exit(1);
    }

    // Declare a variable to load the contents from the file
    string line = "";

    // Loading the value vector
    while (inValue >> line) {
        double value = stod(line);
        x.push_back(value);
    }

    int file_e=clock();

    cout << "file read completed in "
         << (file_e-file_s)/double(CLOCKS_PER_SEC)*1000 << "ms"<<endl;

    return x;
}