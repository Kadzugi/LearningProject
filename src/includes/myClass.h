#pragma once
#include <iostream>

class Numbers {
public:
    int m_numbers;
    int m_numbers1;

    void set(int a, int b){
        m_numbers = a;
        m_numbers1 = b;
    }

    void print(){
        std::cout << "Numbers(" << m_numbers << ", " << m_numbers1 << ")" << std::endl;
    }
};