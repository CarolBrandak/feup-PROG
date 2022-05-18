#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Point2d.h"

void Point2d::translate(const Point2d& t){
    x=x+t.x;
    y=y+t.y;
}

double Point2d::distance_to(const Point2d& p) const{
    double dx=x-p.x;
    double dy=y-p.y;
    return sqrt(dx*dx+dy*dy);
}

