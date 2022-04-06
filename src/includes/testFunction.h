#pragma once
#include "structMain.h"
#include "myConstants.h"

#include <array>
#include <cstdarg>

//typedef bool (*ptrBoolFunc)(int, int); // использование псевдонима типа через typedef для указателя на функцию
using ptrBoolFunc = bool (*)(int, int); // использование псевдонима типа через using для указателя на функцию

using ptrOperationFunc = int (*)(int, int);

void ignoreLine();
int writeInt();
double writeDouble();
char writeChar();
std::string writeString();
std::string writeStringCheck();
int getRandomNumber(int min, int max);
double ball_height_calc(double height, double time_sec);
bool isEven(int number);
void print_count_adv(Advertising &web_side);
void multiplay(Fraction &fra, Fraction &fra1);
std::string get_rase_personal(Personal &personal);
void print_personal_date(Personal &personal);
int calculate(int a, int b, char math_operator);
int sumTo(const int value);
void printCard(const Card &card);
void printDeck(const std::array<Card, 52> &deck);
void swapCard(Card &a, Card &b);
void shuffleDeck(std::array<Card, 52> &deck);
int getCardValue(const Card &card);
bool playBlackjack(std::array<Card, 52> &deck);
bool sortASC(int a, int b);
bool sortDESC(int a, int b);
void stringArraySort(std::string* str, int length);
void intArraySort(int *array, int lenght, ptrBoolFunc funcSort = sortASC);
int addNumber(int a, int b);
int subtractNumber(int a, int b);
int multiplyNumber(int a, int b);
int divideNumber(int a, int b);
ptrOperationFunc getArithmeticFcn(char operation = '+');
int factorial(int value);
int sumNumber(int number);
void binaryConvert(unsigned int value);
int findAverage(int count, ...);