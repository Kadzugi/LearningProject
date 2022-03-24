#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include "testFunction.h"

void ignoreLine(){
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
}

int writeInt(){
    int number;
    while(!(std::cin >> number)){
        ignoreLine();
        std::cout << "Не верный ввод! Введите число: ";
    }
    ignoreLine();
    return number;
}

double writeDouble(){
    double number;
    while(!(std::cin >> number)){
        ignoreLine();
        std::cout << "Не верный ввод! Введите вещественное число: ";
    }
    ignoreLine();
    return number;
}

char writeChar(){
    char symbol;
    std::cin >> symbol;
    return symbol;
}

std::string writeString(){
    std::string str;
    ignoreLine();
    std::getline(std::cin, str);
    return str;
}

std::string writeStringCheck(){
    std::string str;
    while(str != "y" && str != "n"){
        std::cout << "Введите ответ: "; 
        std::cin >> str;
    }
    return str;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

double ball_height_calc(double height, double time_sec){
    return height - (constants::m_earth * ((time_sec * time_sec) / 2));
}

bool isEven(int number){
    return number%2 == 0;
}

void print_count_adv(Advertising &web_side){
    std::cout << "Показано объявлений: " << web_side.count_announ << std::endl;
    std::cout << "Посетителей нажало на объявления: " << web_side.click_announ << std::endl;
    std::cout << "Заработано в среднем: " << web_side.count_cash << std::endl;
    std::cout << "Заработано всего за день: " << web_side.count_announ*web_side.click_announ/100*web_side.count_cash << std::endl;
}

void multiplay(Fraction &fra, Fraction &fra1){
    std::cout << "Полученное десятичное число: " 
    << static_cast<double>(fra.numerator * fra1.numerator) / static_cast<double>(fra.denominator * fra1.denominator) 
    << std::endl;
}

std::string get_rase_personal(Personal &personal){
    if (personal.rase == Rase::ogre)
		return "Ogre";
	if (personal.rase == Rase::goblin)
		return "Goblin";
	if (personal.rase == Rase::skeleton)
		return "Skeleton";
	if (personal.rase == Rase::orc)
		return "Orc";
	if (personal.rase == Rase::troll)
		return "Troll";
    if (personal.rase == Rase::elf)
		return "Elf";
    if (personal.rase == Rase::human)
		return "Human";
 
	return "Unknown";
}

void print_personal_date(Personal &personal){
    std::cout << "Характеристика персонажа\n" << "Раса: " 
    << get_rase_personal(personal) << "\n" 
    << "Имя: " << personal.name << "\n" << "Здоровье: " 
    << personal.headpoint << std::endl;
}

int calculate(int a, int b, char math_operator){
    switch (math_operator){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return a % b; 
        default:
            break;
    }
    return 0;
}

int sumTo(const int value){
    int sum = 0;
    for(int count = 1; count <= value; ++count){
        sum+=count;
    }
    return sum;
}

void stringArraySort(std::string* str, int length){
    for(int i = 0; i < length - 1; i++){
       bool is_check = true;
       for(int j = 0; j < length - i - 1; j++){
           if(str[j] > str[j + 1]){
               is_check = false;
               std::swap(str[j], str[j + 1]);
           }
       }
       if(is_check){
           std::cout << "Сортировка остановлена на " << i + 1 << " итерации." <<std::endl;
           break;
       } 
    }
    //std::sort(str, str + length);
}

void printCard(const Card &card){
    std::string code;

    switch (card.card_value)
    {
    case CardValue::two:
        code+="2";
        break;
    case CardValue::tree:
        code+="3";
        break;
    case CardValue::four:
        code+="4";
        break;
    case CardValue::five:
        code+="5";
        break;
    case CardValue::six:
        code+="6";
        break;
    case CardValue::seven:
        code+="7";
        break;
    case CardValue::eight:
        code+="8";
        break;
    case CardValue::nine:
        code+="9";
        break;
    case CardValue::ten:
        code+="T";
        break;
    case CardValue::jack:
        code+="J";
        break;
    case CardValue::queen:
        code+="Q";
        break;
    case CardValue::king:
        code+="K";
        break;
    case CardValue::ace:
        code+="A";
        break;
    default:
        break;
    };

    
    switch (card.lear)
    {
    case Lear::odiamonds:
        code+="O";
        break;
    case Lear::christs:
        code+="C";
        break;
    case Lear::worms:
        code+="W";
        break;
    case Lear::piki:
        code+="P";
        break;
    default:
        break;
    };

    std::cout << code << " ";
}

void printDeck(const std::array<Card, 52> &deck){
    for(const auto &card : deck){
       printCard(card);
    }
    std::cout << std::endl;
}

void swapCard(Card &a, Card &b){
    std::swap(a.card_value, b.card_value);
    std::swap(a.lear, b.lear);
}

void shuffleDeck(std::array<Card, 52> &deck){
    for(int i = 0; i < deck.size(); i++){
        int number = getRandomNumber(0, 51);
        swapCard(deck[i], deck[number]);
    }
}

int getCardValue(const Card &card){
    switch (card.card_value)
    {
    case CardValue::two:
        return 2;
    case CardValue::tree:
        return 3;
    case CardValue::four:
        return 4;
    case CardValue::five:
        return 5;
    case CardValue::six:
        return 6;
    case CardValue::seven:
        return 7;
    case CardValue::eight:
        return 8;
    case CardValue::nine:
        return 9;
    case CardValue::ten:
        return 10;
    case CardValue::jack:
        return 10;
    case CardValue::queen:
        return 10;
    case CardValue::king:
        return 10;
    case CardValue::ace:
        return 11;
    default:
        return -1;
    };
    return -1;
}

std::string playerAction(){
    std::string command_player;
    do{
        std::cout << "Ваше действие \"hit\"(взять ещё карту) или \"srand\"(удержаться): ";
        command_player = writeString();
    } while(command_player != "hit" && command_player != "srand");
    return command_player;
}

bool playBlackjack(std::array<Card, 52> &deck){
    int player_sum = 0, diller_sum = 0;
    Card *cardPtr = &deck[0];

    diller_sum += getCardValue(*cardPtr++);

    std::cout << "Ваши стартовые карты: ";
    printCard(*cardPtr);
    player_sum += getCardValue(*cardPtr++);
    printCard(*cardPtr);
    player_sum += getCardValue(*cardPtr++);
    std::cout << "\nВаш счет: " << player_sum << std::endl;

    while(true){
        
        if(player_sum > 21){
            std::cout << "Вы проиграли!\nКол-во ваших очков составило: " << player_sum << "\nКол-во очков диллера составило: " << diller_sum << std::endl;
            return false;
        }
        
        std::string command_player = playerAction();
        if(command_player == "srand"){
            break;
        }

        std::cout << "Вы берете карту: ";
        printCard(*cardPtr);
        std::cout << std::endl;
        player_sum += getCardValue(*cardPtr++);
        std::cout << "Ваш счет: " << player_sum << std::endl;
    }
    
    while(diller_sum < 17){
        diller_sum += getCardValue(*cardPtr++);
    };
    if (diller_sum > 21){
        std::cout << "Диллер проиграл!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
        return true;
    };

   if(diller_sum > player_sum){
        std::cout << "Вы проиграли!\nКол-во ваших очков составило: " << player_sum << "\nКол-во очков диллера составило: " << diller_sum << std::endl;
        return false;
   } else if(diller_sum == player_sum) {
        std::cout << "Ничья!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
        return false;
   } else{
        std::cout << "Диллер проиграл!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
        return true;
   }   
}