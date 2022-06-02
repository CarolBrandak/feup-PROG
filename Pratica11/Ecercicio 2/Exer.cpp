#include <cmath>
#include <iostream>
#include <iomanip>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
public:
    Circle(point center, double radius) : Shape(center), radius_(radius){};
    double area() const override { return M_PI * pow(radius_, 2); };
    double perimeter() const override { return 2 * M_PI * radius_; };
    bool contains(const point& p) const override
    {
        point c = get_center();
        double dx = p.x - c.x;
        double dy = p.y - c.y;
        return (dx * dx + dy * dy <= radius_ * radius_);
    };

private:
    double radius_;
};

class Rectangle : public Shape
{
public:
    Rectangle(point center, double width, double height) : Shape(center), width_(width), height_(height){};
    double area() const override { return width_ * height_; };
    double perimeter() const override { return 2 * width_ + 2 * height_; };
    bool contains(const point& p) const override
    {
        point c = get_center();
        double dxd = c.x+width_/2;
        double dxe = c.x-width_/2;
        double dyd = c.y+height_/2;
        double dye = c.y-height_/2;
        return (p.x<=dxd) && (p.x>=dxe) && (p.y<=dyd) && (p.y>=dye);
    };

private:
    double width_;
    double height_;
};

