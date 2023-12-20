# Hermite Curve Library

This C++ library defines a `HermiteCurve` class that represents a Hermite curve. The curve is calculated based on a set of control points, and the class provides methods to calculate points on the curve.

## Introduction
The Hermite curve is a mathematical curve often used in computer graphics and animation. This library provides a C++ implementation for calculating points on a Hermite curve.

## Exported Variable and Function
```cpp
HERMITECURVE_API int nHermiteCurve = 0;

HERMITECURVE_API int fnHermiteCurve(void)
{
    return 0;
}

## Class: HermiteCurve
### Constructor
HermiteCurve::HermiteCurve(std::vector<Point3D> points);
### Destructor
HermiteCurve::~HermiteCurve();
### Method: calculateHermite
std::vector<Point3D> HermiteCurve::calculateHermite();
### Method: evaluateHermite
Point3D HermiteCurve::evaluateHermite(double t);
### Example Usage
#include "HermiteCurve.h"

// Example usage of HermiteCurve class
std::vector<Point3D> controlPoints = { /* initialize control points here */ };
HermiteCurve hermiteCurve(controlPoints);
std::vector<Point3D> curvePoints = hermiteCurve.calculateHermite();
![HermiteCurve](https://github.com/ashishkamblecctech/ZBufferAlgorithm/assets/149309502/e954dd35-2178-4a57-9e0f-030480d383c1)

