#include <iostream>
#include <vector>
#include "Figure.h"

using namespace std;

class Rectangle : public Figure
{
public:
    Rectangle(double x_center, double y_center, double widht, double height) : Figure(x_center, y_center), width_(widht), height_(height) {}
    void draw() const {cout << "R(" << x_center_ << "," << y_center_ << ")(" << width_ << "," << height_ << ")";};
    ~Rectangle() {}

private:
    double width_;
    double height_;
};

class Circle : public Figure
{
public:
    Circle(double x_center, double y_center, double radius) : Figure(x_center, y_center), radius_(radius) {}
    void draw() const {cout << "C(" << x_center_ << "," << y_center_ << ")(" << radius_ << ")";};
    ~Circle() {}

private:
    double radius_;
};
