#pragma once
#include "enumsMain.h"

struct Advertising
{
    int count_announ;
    double click_announ;
    double count_cash;
};

struct Fraction
{
    int numerator;
    int denominator;
};

struct Personal
{
    Rase rase;
    std::string name;
    int headpoint;
};

struct Student{
    std::string name;
    int grade;
};

struct Card{
    Lear lear;
    CardValue card_value;
};

struct arithmeticStruct{
    char operation;
    int (*arithmeticFcn)(int, int);
};