#pragma once
#include "Triangle.h"
class Writer
{
public:
    Writer();
    ~Writer();

    void write(QVector <Triangle>& triangles, QVector <GLfloat>& inputPoints);

};

