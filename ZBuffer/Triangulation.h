#pragma once
#include "Triangle.h"
#include <vector>

class Triangulation
{
public:
    Triangulation(std::vector<Triangle> triangles);
    ~Triangulation();

    std::vector<Triangle> getTriangles();

private:
    std::vector<Triangle> mTriangles;
};

