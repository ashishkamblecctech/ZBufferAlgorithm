// HermiteCurve.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "HermiteCurve.h"


// This is an example of an exported variable
HERMITECURVE_API int nHermiteCurve=0;

// This is an example of an exported function.
HERMITECURVE_API int fnHermiteCurve(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
HermiteCurve::HermiteCurve(std::vector<Point3D> points) : mControlPoints(points)
{
}

HermiteCurve::~HermiteCurve()
{
}

std::vector<Point3D> HermiteCurve::calculateHermite()
{
    std::vector<Point3D> result;
    for (double t = 0; t <= 1; t += 0.1) {
        Point3D r = evaluateHermite(t);
        result.push_back(r);
    }
    return result;
}

Point3D HermiteCurve::evaluateHermite(double t)
{
    double t2 = t * t;
    double t3 = t2 * t;

    double h1 = 2 * t3 - 3 * t2 + 1;
    double h2 = -2 * t3 + 3 * t2;
    double h3 = t3 - 2 * t2 + t;
    double h4 = t3 - t2;

    double x = h1 * mControlPoints[0].x() + h2 * mControlPoints[1].x() + h3 * mControlPoints[2].x() + h4 * mControlPoints[3].x();
    double y = h1 * mControlPoints[0].y() + h2 * mControlPoints[1].y() + h3 * mControlPoints[2].y() + h4 * mControlPoints[3].y();

    return Point3D(x, y);
}


