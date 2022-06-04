#include "Point.h"

using namespace std;

Point::Point() : x_(0), y_(0) {}

Point::Point(int x, int y) : x_(x), y_(y) {}

Point::Point(const Point &p) : x_(p.get_x()), y_(p.get_y()) {}

int Point::get_x() const { return x_; }

int Point::get_y() const { return y_; }

Point &Point::operator=(const Point &p)
{
    x_ = p.get_x();
    y_ = p.get_y();
    return *this;
}

Point Point::operator+(const Point &p) const
{
    Point res(p.get_x() + x_, p.get_y() + y_);
    return res;
}

Point &Point::operator+=(const Point &p)
{
    x_ = p.get_x() + x_;
    y_ = p.get_y() + y_;
    return *this;
}

Point Point::operator*(int v) const
{
    Point res(v * x_, v * y_);
    return res;
}

Point operator*(int x, const Point& p){
    Point res(x * p.get_x(), x * p.get_y());
    return res;
}

std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.get_x() << "," << p.get_y() << ")";
    return os;
}

int main()
{
    Point a, b(1, 2), c(b), d(3, 4);
    b = a;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    return 0;
}