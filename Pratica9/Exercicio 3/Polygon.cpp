#include "Polygon.h"

Polygon::Polygon() {}

Polygon::Polygon(vector<Point> poly) : poly_(poly) {}

void Polygon::show()
{
    cout << "{";
    for (auto i : poly_)
    {
        i.show();
    }
    cout << "}";
}

bool Polygon::get_vertex(int p, Point& point)
{
    if (p < 1 || p > static_cast<int>(poly_.size()))
        return false;
    
    point.setX(poly_[p-1].getX());
    point.setY(poly_[p-1].getY());

    return true;
}

void Polygon::add_vertex(int p, Point point)
{
    poly_.insert(poly_.begin()+p-1, point);
}

double Polygon::perimeter()
{
    double res = 0.0;
    for (int i = 0; i < static_cast<int>(poly_.size()); i++)
    {
        if (i == static_cast<int>(poly_.size()) - 1)
            res += sqrt(pow(poly_[0].getX() - poly_[i].getX(), 2) + pow(poly_[0].getY() - poly_[i].getY(), 2));
        else
            res += sqrt(pow(poly_[i + 1].getX() - poly_[i].getX(), 2) + pow(poly_[i + 1].getY() - poly_[i].getY(), 2));
    }

    return res;
}