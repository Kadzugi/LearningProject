#include "Numbers.h"

void Numbers::setValues(double a, double b, double c){
    m_a = a;
    m_b = b;
    m_c = c;
}

void Numbers::print(){
    std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">" << std::endl;
}

bool Numbers::isEqual(const Numbers& num){
    return (m_a == num.m_a && m_b == num.m_b && m_c == num.m_c);
}