#include "stdafx.h"
#include "Reader.h"
#include <sstream>
#include <fstream>


void Reader::reader(QVector <GLfloat> &pointVector, QVector <GLfloat>& colorVector) {

    std::ifstream dataFile;
    dataFile.open("cubeModel.stl");
    if (!dataFile.is_open()) {
        qDebug() << "File not exist";
        return ;
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
            pointVector.push_back(x);
            pointVector.push_back(y);
            pointVector.push_back(z);
            count++;

            if (count == 3) {
                count = 0;
                colorVector.push_back(1.0);
                colorVector.push_back(0.0);
                colorVector.push_back(0.0);

                colorVector.push_back(0.0);
                colorVector.push_back(1.0);
                colorVector.push_back(0.0);

                colorVector.push_back(0.0);
                colorVector.push_back(0.0);
                colorVector.push_back(1.0);
            }
        }
    }
    dataFile.close();
}