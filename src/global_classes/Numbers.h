#pragma once
#include <iostream>

class Numbers {
    double m_a, m_b, m_c;
public:
    void setValues(double a, double b, double c);
    void print();
    bool isEqual(const Numbers& num);
};