#pragma once
#include <CGAL/Cartesian.h>
#include <CGAL/convex_hull_2.h>
#include <vector>

typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2> Points;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public class CGALHolder {
private:
	Points points;
	Points result;

public:
void addPoint(double x, double y) {
	points.push_back(Point_2(x, y));
	}

void paint(Graphics^ g, Pen^ pen, Points points) {
	for (int i = 0; i < points.size(); i++) {
		g->DrawEllipse(pen, points[i].x(), (int)points[i].y(), 2, 2);
	}
}

Points simpleConvexHull() {
	result.clear();
	CGAL::convex_hull_2(points.begin(), points.end(), std::back_inserter(result));
	return result;
}

void paintConvexHull(Graphics^ g, Pen^ p, Points points) {
	Point_2 prevPoint(-1, -1);

	for (auto &point : points) {
		if (prevPoint.x() != -1) {
			g->DrawLine(p, (int)point.x(), (int)point.y(), (int)prevPoint.x(), (int)prevPoint.y());
		}
		prevPoint = point;
	}
	if (!points.empty()) {
		g->DrawLine(p, (int)points[0].x(), (int)points[0].y(),
			(int)points.back().x(), (int)points.back().y());
	}
}

};