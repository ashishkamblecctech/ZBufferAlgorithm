# Bezier Curve Library

This C++ library defines a `BezierCurve` class that represents a Bezier curve. The curve is calculated based on a set of control points, and the class provides methods to calculate points on the curve.

## Introduction
The Bezier curve is a mathematical curve widely used in computer graphics and other fields. This library provides a C++ implementation for calculating points on a Bezier curve.

## Class: BezierCurve

### Constructor
```
BezierCurve::BezierCurve(std::vector<Point3D> points);
```
### Destructor
```
BezierCurve::~BezierCurve();
```
### Method: calculateBezier
```
std::vector<Point3D> BezierCurve::calculateBezier();
```
### Method: evaluateBezier
```
Point3D BezierCurve::evaluateBezier(double t);
```
### Example Usage
```
#include "BezierCurve.h"
```




### Example usage of BezierCurve class
```
std::vector<Point3D> controlPoints = { /* initialize control points here */ };
BezierCurve bezierCurve(controlPoints);
std::vector<Point3D> curvePoints = bezierCurve.calculateBezier();
```
![BezierCurve](https://github.com/ashishkamblecctech/ZBufferAlgorithm/assets/149309502/31ae4131-d650-49c6-b089-c1646ce29682)




https://github.com/ashishkamblecctech/ZBufferAlgorithm/assets/149309502/07a9c7d3-f955-4e0c-b7e6-63dc92c5d4b7




