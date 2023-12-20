#pragma once
#include "pch.h"
#include <vector>
#include "Triangle.h"
#include "Triangulation.h"
#include "Geometry.h"


// This class is exported from the dll
class ZBUFFER_API Z_Buffer {
public:
	Z_Buffer();
	~Z_Buffer();

public:
	void reader(std::vector <Triangle>& triangles, std::vector <float>& myColorVector);
	void write(std::vector <Triangle>& triangles, std::vector <float>& inputPoints);
};
//
//extern ZBUFFER_API int nZBuffer;
//
//ZBUFFER_API int fnZBuffer(void);
