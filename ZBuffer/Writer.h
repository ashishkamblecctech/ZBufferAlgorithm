#pragma once
#include "pch.h"
#include "Triangle.h"
#include <vector>
#include "ZBuffer.h"
class Writer
{
public:
    Writer();
    ~Writer();

    void write(std::vector<Triangle>& triangles, std::vector <float>& inputPoints);

};

