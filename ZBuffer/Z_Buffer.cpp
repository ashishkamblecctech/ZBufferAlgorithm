// Z_Buffer.cpp : Defines the exported functions for the DLL.

#include "pch.h"
#include "framework.h"
#include "Z_Buffer.h"
#include "Point3D.h"
#include "Triangle.h"
#include "Triangulation.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

// This is the constructor of a class that has been exported.
Z_Buffer::Z_Buffer()
{
    return;
}

Z_Buffer::~Z_Buffer()
{
}

void Z_Buffer::reader(std::vector <Triangle>& triangles, std::vector <float>& myColorVector) {

    std::ifstream dataFile;
    dataFile.open("cubeModel.stl");
    if (!dataFile.is_open()) {
        std::cout << "File not exist";
        return;
    }
    int count = 0;

    std::string line;

    while (std::getline(dataFile, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;
            iss >> token >> x >> y >> z;
            Point3D point(x, y, z);
            iss >> token >> x >> y >> z;

            Point3D point1(x, y, z);

            std::getline(dataFile, line);
            std::istringstream iss1(line);
            iss1 >> token >> x >> y >> z;
            Point3D point2(x, y, z);

            std::getline(dataFile, line);
            std::istringstream iss2(line);
            iss2 >> token >> x >> y >> z;
            Point3D point3(x, y, z);

            Triangle triangle(point1, point2, point3);
            triangles.push_back(triangle);

            count++;

            if (count == 1) {

                myColorVector.push_back(1.0);
                myColorVector.push_back(0.0);
                myColorVector.push_back(0.0);
            }
            else if (count == 2) {
                myColorVector.push_back(1.0);
                myColorVector.push_back(0.0);
                myColorVector.push_back(0.0);
            }
            else if (count == 3) {
                count = 0;
                myColorVector.push_back(0.0);
                myColorVector.push_back(0.0);
                myColorVector.push_back(1.0);
            }
        }
    }
    dataFile.close();
}

void Z_Buffer::write(std::vector <Triangle>& triangles, std::vector <float>& inputPoints)
{
    for (int i = 0; i < triangles.size(); i++) {
        inputPoints.push_back(triangles[i].p1().x());
        inputPoints.push_back(triangles[i].p1().y());
        inputPoints.push_back(triangles[i].p1().z());

        inputPoints.push_back(triangles[i].p2().x());
        inputPoints.push_back(triangles[i].p2().y());
        inputPoints.push_back(triangles[i].p2().z());

        inputPoints.push_back(triangles[i].p3().x());
        inputPoints.push_back(triangles[i].p3().y());
        inputPoints.push_back(triangles[i].p3().z());
    }

}
