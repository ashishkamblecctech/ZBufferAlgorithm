#include "stdafx.h"
#include "Writer.h"
#include "Triangulation.h"
#include "OpenGLWindow.h"
#include<fstream>

Writer::Writer()
{
}

Writer::~Writer()
{
}

void Writer::write(QVector <Triangle>& triangles, QVector <GLfloat>& inputPoints)
{
	for (int i = 0; i<triangles.size(); i++) {
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