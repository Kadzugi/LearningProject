#pragma once
#include <iostream>
#include <cassert>
#include <array>
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

class Card {
public:
    enum CardSuit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};
	enum CardRank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

private:
    CardRank m_rank;
	CardSuit m_suit;

public:
    Card(CardRank rank = MAX_RANKS, CardSuit suit = MAX_SUITS) :
		m_rank(rank), m_suit(suit){};

    void printCard() const
	{
		switch (m_rank)
		{
		case RANK_2:		std::cout << '2'; break;
		case RANK_3:		std::cout << '3'; break;
		case RANK_4:		std::cout << '4'; break;
		case RANK_5:		std::cout << '5'; break;
		case RANK_6:		std::cout << '6'; break;
		case RANK_7:		std::cout << '7'; break;
		case RANK_8:		std::cout << '8'; break;
		case RANK_9:		std::cout << '9'; break;
		case RANK_10:		std::cout << 'T'; break;
		case RANK_JACK:		std::cout << 'J'; break;
		case RANK_QUEEN:	std::cout << 'Q'; break;
		case RANK_KING:		std::cout << 'K'; break;
		case RANK_ACE:		std::cout << 'A'; break;
		}
		switch (m_suit)
		{
		case SUIT_CLUB:		std::cout << 'C'; break;
		case SUIT_DIAMOND:	std::cout << 'D'; break;
		case SUIT_HEART:	std::cout << 'H'; break;
		case SUIT_SPADE:	std::cout << 'S'; break;
		}
	}
    int getCardValue() const
	{
		switch (m_rank)
		{
		case RANK_2:		return 2;
		case RANK_3:		return 3;
		case RANK_4:		return 4;
		case RANK_5:		return 5;
		case RANK_6:		return 6;
		case RANK_7:		return 7;
		case RANK_8:		return 8;
		case RANK_9:		return 9;
		case RANK_10:		return 10;
		case RANK_JACK:		return 10;
		case RANK_QUEEN:	return 10;
		case RANK_KING:		return 10;
		case RANK_ACE:		return 11;
		}
		return 0;
	}
};

class Deck {
private:
    std::array<Card, 52> m_deck;
    int m_cardIndex = 0;

    static int getRandomNumber(int min, int max) {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
    static void swapCard(Card &a, Card &b){
        Card temp = a;
		a = b;
		b = temp;
    }

public:
    Deck(){
        int card = 0;
	    for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
	        for (int rank = 0; rank < Card::MAX_RANKS; ++rank) {
                m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
		        ++card;
	        }
    }

    void printDeck() const {
        for(const auto &card : m_deck){
           card.printCard();
           std::cout << " ";
        }
        std::cout << std::endl;
    }
    void shuffleDeck() {
        for(int i = 0; i < m_deck.size(); i++){
            int number = getRandomNumber(0, 51);
            swapCard(m_deck[i], m_deck[number]);
        }
        m_cardIndex = 0;
    }
    const Card& dealCard() {
        assert(m_cardIndex < 52 && "Out of range!");
        return m_deck[m_cardIndex++];
    }
};

class Fraction_c {
    int m_numerator; 
    int m_denominator;

public:
    Fraction_c(int numerator=0, int denominator=1):
		m_numerator(numerator), m_denominator(denominator){
        reduce();
    }

    int nod(int a, int b) {
        return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
    }

    void print() {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    }

    void reduce() {
        int n = Fraction_c::nod(m_numerator, m_denominator);
        m_numerator /= n;
        m_denominator /=n;
    }

    friend Fraction_c operator*(const Fraction_c &f1, const Fraction_c &f2) {
	    return Fraction_c(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
    }
    friend Fraction_c operator*(const Fraction_c &f1, int number) {
        return Fraction_c(f1.m_numerator * number, f1.m_denominator);
    }
    friend Fraction_c operator*(int number, const Fraction_c &f1) {
        return f1 * number;
    }
};

class Mystring {
std::string m_str;
public:
    Mystring(std::string str) : m_str(str){};

    std::string operator()(int start_index, int lenght) const {
        assert(m_str.size() >= start_index + lenght && "Out of range!");
        
        std::string substr;
        for(int i = start_index; i < start_index + lenght; i++){
            substr += m_str[i];
        }
        return substr;
    }
};

class Drob
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	// Конструктор по умолчанию
	Drob(int numerator = 0, int denominator = 1) :
		m_numerator(numerator), m_denominator(denominator)
	{
        std::cout << "Constructor worked here!\n";
		assert(denominator != 0);
	}
 
	// Конструктор копирования
	Drob(const Drob &copy) :
		m_numerator(copy.m_numerator), m_denominator(copy.m_denominator)
	{
		// Нет необходимости выполнять проверку denominator здесь, так как эта проверка уже осуществлена в конструкторе по умолчанию
		std::cout << "Copy constructor worked here!\n"; // просто, чтобы показать, что это работает
	}
 
	friend std::ostream& operator<<(std::ostream& out, const Drob &d1) {
	    out << d1.m_numerator << "/" << d1.m_denominator;
	    return out;
    }
	int getNumerator() { return m_numerator; }
	void setNumerator(int numerator) { m_numerator = numerator; }
};

class Averages {
int32_t sum_number_m = 0;
int8_t count_number_m = 0;

public:
   Averages(){};

//    Averages operator+(const int32_t number){
//         return Averages(this->sum_number_m + number, this->count_number_m += 1); 
//    }

//    Averages& operator=(const Averages& avg){
//         sum_number_m += avg.sum_number_m;
//         count_number_m += avg.count_number_m;

//         return *this;
//    }

   Averages& operator+=(const int32_t number){
        sum_number_m += number;
        count_number_m += 1;
        return *this; 
   }

   friend std::ostream& operator<<(std::ostream& out, Averages& avg) {
        return out << static_cast<int>(avg.sum_number_m / avg.count_number_m);
   };
};

class IntArray{
    int size_arr_m;
    int* arr_m;
public:
    IntArray(int size_arr) : size_arr_m(size_arr) {
        arr_m = new int[size_arr_m]();
    }

    IntArray(const IntArray& copy_intArr) {
        size_arr_m = copy_intArr.size_arr_m;
        if(copy_intArr.arr_m){
            arr_m = new int[size_arr_m]();
            for(int i = 0; i < size_arr_m; i++){
                arr_m[i] = copy_intArr.arr_m[i];
            }
        } else {
            arr_m = nullptr;
        }
    }

    int& operator[] (const int index) {
        assert(index < size_arr_m && "Out off range!");
        return arr_m[index];
    }

    IntArray& operator=(const IntArray& intArr){
        if (this == &intArr)
            return *this;

        delete[] arr_m;
        size_arr_m = intArr.size_arr_m;
        if(intArr.arr_m){
            arr_m = new int[size_arr_m]();
            for(int i = 0; i < size_arr_m; i++){
                arr_m[i] = intArr.arr_m[i];
            }
        } else {
            arr_m = nullptr;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, IntArray& intArr) {
        for(int i = 0; i < intArr.size_arr_m; i++){
           out << intArr.arr_m[i] << " ";
        }
        out << "\n";
        return out;
    };

    ~IntArray(){
        delete[] arr_m;
        arr_m = nullptr;
    }
};
