#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point(double a, double b) : m_a(a), m_b(b){}

void Point::print() const {
    std::cout << "Point(" << m_a << ", " << m_b << ")" << std::endl;
}

double Point::distanceTo(const Point& second) const {
    return sqrt((this->m_a - second.m_a) * (this->m_a - second.m_a) + (this->m_b - second.m_b) * (this->m_b - second.m_b));
}

double distanceFrom(const Point& first, const Point& second) {
    return sqrt((first.m_a - second.m_a) * (first.m_a - second.m_a) + (first.m_b - second.m_b) * (first.m_b - second.m_b));
}