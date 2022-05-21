#include "includes/myFunction.h"

#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <array>
#include <vector>
//#include <functional>

/* Псевдонимы для типов
typedef int status_t;
using status_t = int;*/

/*namespace zoo {
    enum zootop{
        chicken, 
        lion, 
        giraffe, 
        elephant, 
        duck, 
        snake,
        max_lenght
    };
}*/

// void changeArray(int ptr[] /*int *ptr*/, int size)
// {
//     for(int i = 0; i < size; i++){
//         std::cout << ptr[i] << std::endl;
//     }
//     std::cout << ptr[1] << std::endl;
//     *ptr = 5; // поэтому изменение элемента массива приведет к изменению фактического массива
// }

/*int func(int a) {
    return a + 5;
};
double func(double a){
    return a + 5;
}
int funcs(double a){
    return a + 5;
};*/


int main(int argc, char *argv[]){
    setlocale(LC_ALL, "fr_BE.UTF-8");
    srand(static_cast<unsigned int>(time(0)));

    Deck deck;
	deck.shuffleDeck();
	playBlackjack(deck);

    /* Тест глава 8 задания 3
    Monster m = MonsterGenerator::generateMonster();
	m.print();*/

    /* Тест глава 8 задания 1,2
    Point first;
    Point second(2.0, 5.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    Welcome hello;
	hello.print();*/

    /* Работа с дружественными классами
    Point3D p(3.0, 4.0, 5.0);
	Vector3D v(3.0, 3.0, -2.0);
 
	p.print();
	p.moveByVector(v);
	p.print();*/

    /* Работа с классом имеющим делегирующий конструктор
    Employee a("Дмитрий");*/

    /* Работа со списком инициализации членов класса
    RGBA color(0, 135, 135);
	color.print(); */

    /* Работа с различными конструкторами класса
    Ball def;
    def.print();
 
	Ball black("black");
	black.print();
	
	Ball thirty(30.0);
	thirty.print();
	
	Ball blackThirty("black", 30.0);
	blackThirty.print();
    */

    /* Работа с классом Stack
    Stack stack;
	stack.reset();
 
	stack.print();
 
	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();
 
	stack.pop();
	stack.print();
 
	stack.pop();
	stack.pop();
 
	stack.print();
    */

    /* Бинарный поиск
    int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };
	int x{writeInt()};
	int index = binarySearch(array, x, 0, 14);
 
	if (array[index] == x)
		std::cout << "Good! Your value " << x << " is on position "<< index << " in array!\n";
	else
		std::cout << "Fail! Your value " << x << " isn't in array!\n";
	return 0;*/

    /* Элипсис
    std::cout << findAverage(5, 1, 2, 3, 4, 5) << std::endl;
    */

    /* Работа с аргументами команндной строки
    for(int i = 0; i < argc; i++){
        if(i == 1){
            std::cout << typeid(std::stoi(argv[i])).name() << std::endl;
        } else{
            std::cout << argv[i] << std::endl;
        }
    }*/
    
    /* Конвертор десятичного числа в двоичное
    binaryConvert(-14);
    std::cout << std::endl;
    binaryConvert(148);*/

    /* Программа №18 Реализация простого калькулятора с использованием указателя на функцию
    int a {writeInt()};
    char operation = 'none';
    while(operation != '+' && operation != '-' && operation != '/' && operation != '*' && operation != '%'){
        std::cout << "Введите математическую операцию: ";
        operation = writeChar();
    }
    int b {writeInt()}; 

    ptrOperationFunc OperationFunc = getArithmeticFcn(operation);
    if (OperationFunc != nullptr){
        std::cout << "a " << operation << " b = " << OperationFunc(a, b) << std::endl;
    } */

    /* Использование указателя на функцию для способа сортировки массива
    const int lenght = 7;
    int array[lenght] = {20, 10, 30, 40, 50, 5, 60};
    intArraySort(array, lenght, sortDESC);

    for(auto& element : array){
        std::cout << element << " ";
    }*/

    /* Указатели на функцию
    int (*funcPtr)(double) = funcs;
    int (*funcPtr1)(int);
    funcPtr1 = func;
    
    std::function<bool(int,int)> ptrFunc; // создание указателя на функцию с помощью fuction из библиотеки functional

    std::cout << "Ptr func: " << funcPtr1 << std::endl;

    funcPtr1(7) - вызов функции func через указатель неявно
    (*funcPtr1)(7) - вызов функции func через указатель явно (использование разыменовывания)
    */

    /* Программа №17
    std::array<Card, 52> deck;
    int card = 0;
    for(int l = 0; l < static_cast<int>(Lear::len_lear); l++){
        for(int v = 0; v < static_cast<int>(CardValue::len_card_value); v++){
            deck[card].lear = static_cast<Lear>(l);
            deck[card].card_value = static_cast<CardValue>(v);
            card++;
        }
    }
    
    //printDeck(deck);
    shuffleDeck(deck);
    //printDeck(deck);
    playBlackjack(deck);*/

    /* Программа №16
    std::vector<student> students;
    std::cout << "Введите кол-во студентов: ";
    int count_students{writeInt()};

    std::cout << "Введите для каждого студента его имя и оценку." << std::endl;
    for(int i = 0; i < count_students; i++){
        student Student;
        std::cout << "Имя: ";
        Student.name = {writeString()};
        std::cout << "Оценка: ";
        Student.grade = {writeInt()};
        students.push_back(Student);
    }

    std::sort(students.begin(), students.end(), [&](const student& student1, const student& student2) -> bool
    { 
        return student1.grade > student2.grade;
    });

    std::cout << "\n" << "Оценки студентов: " << std::endl;
    for(auto &student : students){
        std::cout << student.name << ": " << student.grade << std::endl;
    }/*
    
    /* Обычный трехмерный массив
    int array[3][3][3]{0};
    */

    /* Трехмерный динамический массив с использованием переменных compile-time
    auto array = new int[3][3][3];
    */

    /* Трехмерный динамический массив c использованием переменных run-time (справедливо также для переменных compile-time)
    int a{writeInt()}, b{writeInt()}, c{writeInt()};
    int ***array = new int**[a]; // Динамическое выделение массива указателей на указатель на тип int

    for(int i = 0; i < a; i++){
        array[i] = new int*[b]; // Динамическое выделение массива указателей на тип int
        for(int j = 0; j < b; j++){
            array[i][j] = new int[c];
            for(int p = 0; p < c; p++){
                array[i][j][p] = p;
            }
        }        
    } 

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int p = 0; p < c; p++){
                std::cout << array[i][j][p] << " ";
            }
            std::cout << " ";
        }
        std::cout << std::endl;        
    }

    // Очистка памяти выделенной для трехмерного динамического массива
    for(int j = 0; j < b; j++){
        for(int p = 0; p < c; p++){
            delete[] array[j][p];
        }
        delete[] array[j];
    }
    delete[] array;
    array = nullptr;
    */

    /* Программа №15
    std::string name_array[]{"Dima", "Lena", "Anton", "Nikolay"};
    std::cout << "Введите имя для проверки: ";
    std::string name_cin{writeString()};
    bool check = false;
    for(const auto& name : name_array){
        if (name == name_cin){
            check = true;
            break;
        }
    }
    
    if(check){
        std::cout << "Имя входит в массив!";
    } else {
        std::cout << "Имя не входит в массив!";
    }*/
    
    /* Утверждение препроцессора
    static_assert(sizeof(int) == 4, "int не равен 4 байтам");*/

    /* Программа №14
    std::cout << "Введите количество имен: ";
    int number{writeInt()};
    std::string *name_array = new std::string[number];
    for(int i = 0; i < number; i++){
        std::cout << "Введите имя: ";
        name_array[i] = writeString();
    }
    stringArraySort(name_array, number);

    for(std::string* i = name_array; i < name_array + sizeof(name_array); i++){
        std::cout << *i << std::endl;
    }

    delete[] name_array;
    name_array = nullptr;*/

    /*int lenght;
    std::cin >> lenght;
    int *a = new int[lenght]{1,2,3};
    int b[5]{1,2,3};

    char *c = new char[14]{"Hello!"};
    std::string *f = new std::string[5]{"Hello!"};

    std::cout << a[2] << " " << b[2] << " " << c[2] << " " << c << " " << *f << std::endl;

    delete[] f;
    f = nullptr;*/

    /*int *value = new (std::nothrow) int;
    if (!value)
    {
        std::cout << "Could not allocate memory";
    }*/

    /*int *a = new int{5};
    std::cout << *a << std::endl;
    delete a;
    a = nullptr;
    std::cout << *a << std::endl;*/

    /*int *a(nullptr);
    std::cout << typeid(a).name() << std::endl;*/

    /*int a = 5;
    int &b = a;
    int *c = &b;
    int **d = &c;
    int &&f = 5;
    int *&g = c;
    std::cout << typeid(g).name() << " " << typeid(&b).name() << " " << c << " " << &b << " " << a << std::endl;*/
    
    /* Сортировка методом перебора
    for(int i = 0; i < length; i++){
        for(int j = i + 1; j < length; j++){
            if(array[i] < array[j]){
                std::swap(array[i], array[j]);
            }
        }
    }*/

    /* Сортировка пузырьковым методом
    const int length = 5;
    int array[length] = { 20, 10, 30, 40, 50 };

    for(int i = 0; i < length - 1; i++){
       bool is_check = true;
       for(int j = 0; j < length - i - 1; j++){
           if(array[j] > array[j + 1]){
               is_check = false;
               std::swap(array[j], array[j + 1]);
           }
       }
       if(is_check){
           std::cout << "Сортировка остановлена на " << i + 1 << " итерации." <<std::endl;
           break;
       } 
    }

    for(auto& element : array){
        std::cout << element << " ";
    }*/


    /* Программа №13
    int array[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
    bool is_check = true;
    int a;
    int index = 0;
    do{
        std::cout << "Пожалуйста введите число: " << std::endl;
        std::cin >> a;
        if (std::cin.fail()){
            std::cin.clear(); 
            std::cin.ignore(32767, '\n'); 
        }
    }
    while(a < 1 || a > 9);
        
    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++){
        std::cout << array[i] << " ";
        if(array[i] == a){
            index = i;
        }
    }
    std::cout << "\n" << index << std::endl;
    */
    
    /*int nog[zoo::max_lenght]{2, 4, 4, 4, 3, 1};
    std::cout << nog[zoo::elephant] << std::endl;*/
    
    /* Программа №12
    int number_gen = getRandomNumber(1, 100);
    int number_att = 0; 
    std::cout << "Добро пожаловать в игру Hi-Lo, у вас есть 7 попыток чтобы угадать загаданное число!" << std::endl;
    std::string is_end_game = "y";
    
    while(is_end_game == "y"){

        number_att++;

        int number_user{writeInt()};
        if(number_user == number_gen){
            std::cout << "Поздравляю) Вы угадали!" << "\n" << "Если хотите начать новую игру введите \"y\", в противном случае введите \"n\"" << std::endl;
            is_end_game = writeStringCheck();
            number_gen = getRandomNumber(1, 100);
            number_att = 0;
        } else if(number_user < number_gen){
            std::cout << "Ваше число меньше)" << std::endl;
        } else if(number_user > number_gen){
            std::cout << "Ваше число больше)" << std::endl;
        }

        if(number_att == 7){
            std::cout << "К сожалению вы не угадали, желаете продолжить? (y/n)" << std::endl;
            is_end_game = writeStringCheck();

            if(is_end_game == "y"){
                number_att = 0;
                number_gen = getRandomNumber(1, 100);
            }
        }
    }*/

    /* Программа №11
    int number{writeInt()};
    std::cout << "Полченная сумма: " << sumTo(number) << std::endl;
    */

    /* Программа №10
    int outer = 1;
    while(outer <= 5){
        int inner = 5;
        while(inner >= 1){
            if(inner > outer){
                std::cout << "  ";
                inner--;
            } else {
                std::cout << inner-- << " ";
            }      
        }
        std:: cout << "\n";
        ++outer;
    }*/

    /* Программа №9
    char code_symbols = 'a';
    while(code_symbols <= 'z'){
        std::cout << "Буква: "  << code_symbols << 
    ", её ASCII-код: " << static_cast<int>(code_symbols) << std::endl;
        ++code_symbols;
    }*/
    
    /* Программа №8
    std::cout << "Результат операции: " 
    << calculate(writeInt(), writeInt(), writeChar()) << std::endl;*/

    /* Программа №7
    Personal elf{Rase::elf, "Kadzugi", 350};
    print_personal_date(elf); */

    /* Программа №6
    Fraction fra{writeInt(), writeInt()};
    Fraction fra1{writeInt(), writeInt()};

    multiplay(fra, fra1);*/

    /* Программа №5
    Advertising adv{writeInt(), writeDouble(), writeDouble()};
    print_count_adv(adv);*/

    /* Программа №4
    std::cout << "Введите имя и фамилию: ";
    std::string NameSurname{writeString()}; 

    std::cout << "Введите ваш возраст: ";
    int years{writeInt()}; 

    std::cout << "На каждую букву своего имени (включая пробел) вы прожили " 
              << static_cast<double>(years) / NameSurname.size() 
              << " лет." <<std::endl;*/

    /* Программа №3
    std::cout << "Введите целое число №1: ";
    int number1{writeInt()};

    std::cout << "Введите целое число №2: ";
    int number2{writeInt()};

    if(number1 > number2){
        std::cout << "Меняем местами!" << std::endl;
        int number_swap{number1};
        number1 = number2;
        number2 = number_swap;
    }

    std::cout << "Меньшее число: " << number1 << "\n" << "Большее число: " << number2 << std::endl;
    */

    /* Программа №2
    std::cout << "Введите целое число: ";
    int number{writeInt()};
    std::cout << std::endl;

    std::cout << "Число является четным? " << std::boolalpha << isEven(number) << std::endl;
    */

    // Программа №1
    /*std::cout << "Введите высоту башни: ";
    double height{writeDouble()};
    std::cout << std::endl;

    double time_sec{0};
    double ball_height{height};

    while(ball_height > 0){
        ball_height = ball_height_calc(height, time_sec);
        if(ball_height > 0){
            std::cout << "В " << time_sec << " секунд, мяч был на высоте: " << ball_height << std::endl;
            ++time_sec;
        } else {
            std::cout << "В " << time_sec << " секунд, мяч достиг земли!" << std::endl;
        }
    }*/
        
    return 0;
}