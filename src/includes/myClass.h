#pragma once
#include <iostream>
#include <cassert>

class Numbers {
    double m_a, m_b, m_c;
public:
    void setValues(double a, double b, double c){
        m_a = a;
        m_b = b;
        m_c = c;
    }

    void print(){
        std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">" << std::endl;
    }

    bool isEqual(const Numbers& num){
        return (m_a == num.m_a && m_b == num.m_b && m_c == num.m_c);
    }
};

class Stack {
    int len_stack;
    int array[10];
public:
    void reset(){
        len_stack = 0;
        for(int i = 0; i < 10; ++i){
            array[i] = 0;
        }
    }

    bool push(int value){
        if(len_stack < 10){
            array[len_stack++] = value;
            return true;
        } else {
            return false;
        }       
    }

    int pop(){
        assert(len_stack != 0 && "В стеке нет элементов для возврата!");
        int value = array[len_stack];
        array[len_stack] = 0;
        len_stack--;

        return value;
    }

    void print(){
        std::cout << "( ";
        for(int i = 0; i < len_stack; i++){
            std::cout << array[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};