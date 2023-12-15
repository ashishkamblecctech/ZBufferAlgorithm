#pragma once
#include <vector>
#include "Triangle.h"

class Triangulation
{

public:
    Triangulation(std::vector<Triangle> triangles);
    ~Triangulation();

    std::vector<Triangle> getTriangles();

private:
    std::vector<Triangle> mTriangles;
};
