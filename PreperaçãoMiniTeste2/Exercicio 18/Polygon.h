#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

#include "Point.h"

using namespace std;

class Polygon
{
public:
    Polygon();
    Polygon(vector<Point> poly);
    void show();
    bool get_vertex(int p, Point &point);
    void add_vertex(int p, Point point);
    double perimeter();

private:
    vector<Point> poly_;
};

#endif