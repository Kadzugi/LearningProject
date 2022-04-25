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

class Ball{
    std::string m_color;
    double m_radius;
public:
    Ball(double radius){
        m_color = "red";
        m_radius = radius;
    }
    
    Ball(std::string color = "red", double radius = 20.0){
        m_color = color;
        m_radius = radius;
    }

    void print(){
        std::cout << "color: " << m_color << ", radius: " << m_radius << std::endl;
    }
};

class RGBA{
    std::uint8_t m_red, m_green, m_blue, m_alpha; 
public:
    RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255) 
        : m_red{red}, m_green{green}, m_blue{blue}, m_alpha{alpha}
    {}

    void print(){
        std::cout << "r=" << static_cast<int>(m_red) << " g=" << static_cast<int>(m_green) 
            << " b=" << static_cast<int>(m_blue) << " a=" << static_cast<int>(m_alpha) << std::endl;
    }
};

class Employee{
protected:
    int m_id;
    const std::string m_name;
public:
    Employee(int id = 0, const std::string name = "") : m_id(id), m_name(name){
        std::cout << "Id: " << m_id << ", Name: " << m_name << std::endl;
    }
    Employee(const std::string& name) : Employee(0, name){}
};