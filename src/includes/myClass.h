#pragma once
#include <iostream>
#include <cassert>
#include "global_classes/Numbers.h"
#include "global_classes/Point3D.h"
#include "global_classes/Vector3D.h"
#include "global_classes/Point.h"

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

class Welcome
{
private:
	char *m_data;
 
public:
	Welcome()
	{
		m_data = new char[14];
		const char *init = "Hello, World!";
		for (int i = 0; i < 14; ++i)
			m_data[i] = init[i];
	}
 
	~Welcome()
	{
        delete[] m_data;
	}
 
	void print() const
	{
		std::cout << m_data;
	}
 
};

class Monster {
public:
    enum MonsterType : int {
        Dragon, 
        Goblin, 
        Ogre, 
        Orc, 
        Skeleton, 
        Troll, 
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type;
    std::string m_name;
    int m_health_points;

    std::string getTypeString() const {
        switch (m_type) {
            case 0: return "dragon";
            case 1: return "goblin";
            case 2: return "ogre";
            case 3: return "orc";
            case 4: return "skeleton";
            case 5: return "troll";
            case 6: return "vampire";
            case 7: return "zombie";
        }  
        return "Error!";
    }

public:
    Monster(MonsterType type, std::string name, int health_points) 
        : m_type(type), m_name(name), m_health_points(health_points){};

    void print() const {
        std::cout << m_name << " is the " << getTypeString() << " that has " << m_health_points << " health points." << std::endl;
    }
};

class MonsterGenerator {
    static int getRandomNumber(int min, int max) {
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
public:
    static Monster generateMonster() {
        Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
        static std::string name_monster[6]{"Bob", "Jack", "Mary", "Sebastian", "Veronica", "Linda"};
        int health_points{getRandomNumber(50, 100)}; 
        return Monster(type, name_monster[getRandomNumber(0, 5)], health_points);
    };
};