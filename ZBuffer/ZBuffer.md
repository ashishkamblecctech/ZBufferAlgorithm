# Z Buffer Library

This C++ library defines a `Z_Buffer` class that is designed for handling Z-Buffering in computer graphics. The class provides methods for reading a 3D model from an STL file, extracting triangles, and writing the triangle vertices to an output vector.

## Table of Contents
- [Introduction](#introduction)
- [Class: Z_Buffer](#class-z_buffer)
  - [Constructor](#constructor)
  - [Destructor](#destructor)
  - [Method: reader](#method-reader)
  - [Method: write](#method-write)
- [Example Usage](#example-usage)

## Introduction
The Z Buffer, or depth buffer, is commonly used in computer graphics to determine the visibility of objects. This library provides a C++ implementation for handling Z-Buffering.

## Class: Z_Buffer

### Constructor
Z_Buffer::Z_Buffer();

### Destructor
Z_Buffer::~Z_Buffer();
### Method: reader
void Z_Buffer::reader(std::vector<Triangle>& triangles, std::vector<float>& myColorVector);

### Method: write
void Z_Buffer::write(std::vector<Triangle>& triangles, std::vector<float>& inputPoints);
### Example Usage
#include "Z_Buffer.h"

// Example usage of Z_Buffer class
Z_Buffer zBuffer;
std::vector<Triangle> triangles;
std::vector<float> myColorVector, inputPoints;

zBuffer.reader(triangles, myColorVector);
zBuffer.write(triangles, inputPoints);

