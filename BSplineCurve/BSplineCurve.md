# B-Spline Curve Library

This C++ library defines a `BSplineCurve` class that represents a B-spline curve. The B-spline curve is generated based on a specified degree and a set of control points. The class provides methods for generating uniform knots, calculating B-spline basis functions, and evaluating the B-spline curve at given parameter values.

## Introduction
The B-spline curve is a mathematical curve used in computer graphics and computer-aided design. This library provides a C++ implementation for generating and evaluating B-spline curves.

## Class: BSplineCurve

### Constructor
```
BSplineCurve::BSplineCurve(int degree);
```
### Method: generateUniformKnots
```
std::vector<float> BSplineCurve::generateUniformKnots(int num_control_points);
```
### Method: bSplineBasis
```
float BSplineCurve::bSplineBasis(int i, int k, float t, const std::vector<float>& knots);
```
### Method: evaluate
```
std::vector<Point3D> BSplineCurve::evaluate(std::vector<Point3D> control_points, float t);
```
### Example Usage
```
#include "BSplineCurve.h"

// Example usage of BSplineCurve class
int degree = 3;
BSplineCurve bSplineCurve(degree);
std::vector<Point3D> controlPoints = { /* initialize control points here */ };
float numSamples = 100.0f;
std::vector<Point3D> curvePoints = bSplineCurve.evaluate(controlPoints, numSamples);
```

![B-Spline](https://github.com/ashishkamblecctech/ZBufferAlgorithm/assets/149309502/edb330e6-371c-444f-b485-8b8e421ff97f)
