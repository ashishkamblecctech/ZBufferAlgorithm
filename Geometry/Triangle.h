#pragma once
#include "pch.h"
#include "Point3D.h"

class GEOMETRY_API Triangle
{
public:
    Triangle(Point3D p1, Point3D p2, Point3D p3);
    ~Triangle();

    Point3D p1();
    Point3D p2();
    Point3D p3();
private:
    Point3D mP1;
    Point3D mP2;
    Point3D mP3;
};