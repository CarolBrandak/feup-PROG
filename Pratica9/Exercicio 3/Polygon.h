#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"

#include <vector>

class Polygon{
    public:
        Polygon();
        Polygon(vector<Point> poly);
        void show();
        bool get_vertex(int p, Point& point);
        void add_vertex(int p, Point point);
        double perimeter();
        
    private:
        vector<Point> poly_;
};

#endif