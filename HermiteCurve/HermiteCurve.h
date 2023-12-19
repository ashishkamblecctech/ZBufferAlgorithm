#include "pch.h"
#include <Point3D.h>
#include <vector>

// This class is exported from the dll
class HERMITECURVE_API HermiteCurve {
public:
	HermiteCurve(std::vector<Point3D> points);
	~HermiteCurve();
	std::vector<Point3D> calculateHermite();
private:
	Point3D evaluateHermite(double t);
private:
	std::vector<Point3D> mControlPoints;

};

