#pragma once

class Point{
    double m_a, m_b;
public:
    Point(double a = 0.0, double b = 0.0);

    void print() const;
    double distanceTo(const Point& second) const;
    friend double distanceFrom(const Point& first, const Point& second);
};