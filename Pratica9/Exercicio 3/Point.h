#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

using namespace std;

class Point{
    public:
        Point();
        Point(int x, int y);
        void show();
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
    private:
        int x_;
        int y_;
        
};

#endif