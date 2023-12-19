#pragma once
#include "pch.h"
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"
#include "ZBuffer.h"

class Reader
{
public:
	void reader(std::vector <Triangle>& triangles, std::vector <float>& myColorVector);

};

