#include "myFunction.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <locale>
#include <codecvt>
#include <Windows.h>

static std::array<arithmeticStruct, 4> s_arithmeticArray {
    arithmeticStruct{'+', addNumber}, 
    arithmeticStruct{'-', subtractNumber}, 
    arithmeticStruct{'*', multiplyNumber}, 
    arithmeticStruct{'/', divideNumber}
};

void ignoreLine(){
    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
}

int writeInt(){
    std::cout << "Введите целое число: ";
    int number;
    while(!(std::cin >> number)){
        ignoreLine();
        std::cout << "Не верный ввод! Введите целое число: ";
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
    while(!(std::cin >> symbol)){
        ignoreLine();
        std::cout << "Не верный ввод! Введите символ: ";
    }
    ignoreLine();
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

std::string playerAction(){
    std::string command_player;
    do{
        std::cout << "Ваше действие \"hit\"(взять ещё карту) или \"srand\"(удержаться): ";
        command_player = writeString();
    } while(command_player != "hit" && command_player != "srand");
    return command_player;
}

// bool playBlackjack(Deck deck){
//     int player_sum = 0, diller_sum = 0;
//     Card *cardPtr = &deck[0];

//     diller_sum += getCardValue(*cardPtr++);

//     std::cout << "Ваши стартовые карты: ";
//     printCard(*cardPtr);
//     player_sum += getCardValue(*cardPtr++);
//     printCard(*cardPtr);
//     player_sum += getCardValue(*cardPtr++);
//     std::cout << "\nВаш счет: " << player_sum << std::endl;

//     while(true){
        
//         if(player_sum > 21){
//             std::cout << "Вы проиграли!\nКол-во ваших очков составило: " << player_sum << "\nКол-во очков диллера составило: " << diller_sum << std::endl;
//             return false;
//         }
        
//         std::string command_player = playerAction();
//         if(command_player == "srand"){
//             break;
//         }

//         std::cout << "Вы берете карту: ";
//         printCard(*cardPtr);
//         std::cout << std::endl;
//         player_sum += getCardValue(*cardPtr++);
//         std::cout << "Ваш счет: " << player_sum << std::endl;
//     }
    
//     while(diller_sum < 17){
//         diller_sum += getCardValue(*cardPtr++);
//     };
//     if (diller_sum > 21){
//         std::cout << "Диллер проиграл!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
//         return true;
//     };

//    if(diller_sum > player_sum){
//         std::cout << "Вы проиграли!\nКол-во ваших очков составило: " << player_sum << "\nКол-во очков диллера составило: " << diller_sum << std::endl;
//         return false;
//    } else if(diller_sum == player_sum) {
//         std::cout << "Ничья!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
//         return false;
//    } else{
//         std::cout << "Диллер проиграл!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
//         return true;
//    }   
// }

bool playBlackjack(Deck deck){
    int player_sum = 0, diller_sum = 0;

    diller_sum += deck.dealCard().getCardValue();

    std::cout << "Ваши стартовые карты: ";
    Card card_player_first = deck.dealCard();
    card_player_first.printCard();
    player_sum += card_player_first.getCardValue();
    Card card_player_second = deck.dealCard();
    card_player_second.printCard();
    player_sum += card_player_second.getCardValue();
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
        Card card_player = deck.dealCard();
        card_player.printCard();
        std::cout << std::endl;
        player_sum += card_player.getCardValue();
        std::cout << "Ваш счет: " << player_sum << std::endl;
    }
    
    while(diller_sum < 17){
        diller_sum += deck.dealCard().getCardValue();
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
        std::cout << "Вы выйграли!\nКол-во очков диллера составило: " << diller_sum << "\nКол-во ваших очков составило: " << player_sum << std::endl;
        return true;
   }   
}

void intArraySort(int *array, int lenght, ptrBoolFunc funcSort){
    for(int i = 0; i < lenght - 1; i++){
       bool is_check = true;
       for(int j = 0; j < lenght - i - 1; j++){
           if(funcSort(array[j], array[j + 1])){
               is_check = false;
               std::swap(array[j], array[j + 1]);
           }
       }
       if(is_check){
           //std::cout << "Сортировка остановлена на " << i + 1 << " итерации." <<std::endl;
           break;
       } 
    }
}

bool sortASC(int a, int b){
    return a > b; 
}
 
bool sortDESC(int a, int b){
    return a < b; 
}

int addNumber(int a, int b){
    return a + b;
}

int subtractNumber(int a, int b){
    return a - b;
}

int multiplyNumber(int a, int b){
    return a * b;
}

int divideNumber(int a, int b){
    return a / b;
}

ptrOperationFunc getArithmeticFcn(char operation){
    /*if(operation == '+'){
        return addNumber;
    } else if(operation == '-'){
        return subtractNumber;
    } else if(operation == '*'){
        return multiplyNumber;
    } else if(operation == '/'){
        return divideNumber;
    }
    return nullptr;*/

    for(auto &elem: s_arithmeticArray){
        if(operation == elem.operation){
            return elem.arithmeticFcn;
        }
    }

    std::cout << "Данная математическая операция не реализована!" << std::endl;
    return nullptr;
}

int factorial(int value){
    if(value < 2){
        std::cout << 1 << " ";
        return 1;
    } else {
        int res = factorial(value - 1) * value;
        std::cout << res << " ";
        return res;
    }
}

int sumNumber(int number){
    if((-10 < number) && (number < 10)) {
        return number;
    } else {
        int val = number / 10;
        int val_2 = number % 10;
        if(val_2 < 0) {
            val_2 *= -1;
        }

        int res = sumNumber(val) + val_2;
        return res;
    }
}

void binaryConvert(unsigned int value){
    if(value == 0){
        std::cout << "0";
        return;
    } else {
        if((value / 2) > 0){
            binaryConvert(value / 2);
        }
        std::cout << value % 2 << " "; 
    }
}

int findAverage(int count, ...){
    va_list list;
    va_start(list, count);
    int sum = 0;
    for(int i = 0; i < count; i++){
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum / count;
}

int binarySearch(int *array, int target, int min, int max){
    /* рекурсивная версия
    if((max - min) == 1){
        if(array[min] == target){
            return min;
        } else if(array[max] == target){
            return max;
        } else {
            return -1;
        }
    }
    int average = (min + max) / 2;
    if(array[average] > target){
        return binarySearch(array, target, min, average);
    } else if (array[average] < target){
        return binarySearch(array, target, average, max);
    }*/

    // итеративная версия
    int average = 0;
    while((max - min) != 1){
        average = (min + max) / 2;
        if(array[average] > target){
            max = average;
        } else if (array[average] < target){
            min = average;
        } else {
            return average;
        }
    }
  
    if(array[min] == target){
        return min;
    } else if(array[max] == target){
        return max;
    } else {
        return -1;
    }
}

Drob makeNegative(Drob d) {
	d.setNumerator(-d.getNumerator());
    std::cout << "makeNegative successful!" << std::endl;
	return d;
}

IntArray fillArray() {
	IntArray a(6);
	a[0] = 6;
	a[1] = 7;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
    a[5] = 8;
 
	return a;
}

void SomeTest() {
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}