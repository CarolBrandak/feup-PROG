#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Point2d.h"

void Point2d::translate(const Point2d& t){
    x+=t.x;
    y+=t.y;
}

double Point2d::distance_to(const Point2d& t) const{
    return sqrt(pow(x-t.x, 2)+pow(y-t.y, 2));
}