# Bezier Curve Library

This C++ library defines a `BezierCurve` class that represents a Bezier curve. The curve is calculated based on a set of control points, and the class provides methods to calculate points on the curve.

## Table of Contents
- [Introduction](#introduction)
- [Class: BezierCurve](#class-beziercurve)
  - [Constructor](#constructor)
  - [Destructor](#destructor)
  - [Method: calculateBezier](#method-calculatebezier)
  - [Method: evaluateBezier](#method-evaluatebezier)
- [Example Usage](#example-usage)

## Introduction
The Bezier curve is a mathematical curve widely used in computer graphics and other fields. This library provides a C++ implementation for calculating points on a Bezier curve.

## Class: BezierCurve

### Constructor
```cpp
BezierCurve::BezierCurve(std::vector<Point3D> points);
