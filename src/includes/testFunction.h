#pragma once
#include "structMain.h"
#include "myConstants.h"

#include <array>

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
void stringArraySort(std::string* str, int length);
void printCard(const Card &card);
void printDeck(const std::array<Card, 52> &deck);
void swapCard(Card &a, Card &b);
void shuffleDeck(std::array<Card, 52> &deck);
int getCardValue(const Card &card);
bool playBlackjack(std::array<Card, 52> &deck);