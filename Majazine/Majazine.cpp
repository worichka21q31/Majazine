#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include "Header.h"
// Значения...
int siz = 10;
int* idArr = new int[siz];
std::string* nameArr = new std::string[siz];
int* countArr = new int[siz];
double* priceArr = new double[siz];

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    /*Start();*/

    std::string login;
    std::string pass;
    std::string loginTo;
    std::string passTo;

    do
    {
        do
        {
            system("cls");
            std::cout << "[]======================================================[]\n\n";
            std::cout << "\t\t    Регистрация:Создание Аккаунта\nLogin: ";
            std::getline(std::cin, login, '\n');
            if (login.size() < 3)
            {

                std::cerr << "Ошибка! слишком короткий\n";
                system("pause");
            }
            else if(login.size() > 13)
            {
                std::cerr << "Ошибка! слишком длинный\n";
                system("pause");
            }
        } while (login.size() < 3 || login.size() > 13);
        system("cls");
        std::cout << "[]======================================================[]\n\n";
        std::cout << "\t\t    Регистрация:Создание Аккаунта\nLogin: " << login;
        std::cout << "\nPassword: ";
        do
        {
            std::getline(std::cin, pass, '\n');
            if (pass.size() < 3)
            {

                std::cerr << "Ошибка! слишком короткий\n";
                system("pause");
            }
            else if (pass.size() > 13)
            {
                std::cerr << "Ошибка! слишком длинный\n";
                system("pause");
            }
        } while (pass.size() < 3 || pass.size() > 13);
        break;
    } while (true);
    do
    {
        system("cls");
        std::cout << "[]======================================================[]\n\n";
        std::cout << "\t\t    Авторизация:Вход в Аккаунта\nLogin: ";
        std::getline(std::cin, loginTo, '\n');
        system("cls");
        std::cout << "[]======================================================[]\n\n";
        std::cout << "\t\t    Авторизация:Вход в Аккаунта\nLogin: " << loginTo << "\nPassword: ";
        std::getline(std::cin, passTo, '\n');
        system("cls");
        std::cout << "[]======================================================[]\n\n";
        std::cout << "\t\t    Авторизация:Вход в Аккаунта\nLogin: " << loginTo << "\nPassword: ";
        for (size_t i = 0; i < passTo.size(); i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        system("pause");
        system("cls");

        if (login != loginTo || pass != passTo)
        {

            std::cerr << "Ошибка! невернный логин илипароль\n";
            system("pause");
        }
        
    } while (login != loginTo || pass != passTo);


    return 0;
   /* 
    std::string name;
    int a;

    do
    {
        std::getline(std::cin, name, '\n');
    } while (name.size() != 5);
    
    std::cout << name << "\n";

    std::cin >> a;
    std::cout << a << "\n";

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');


    std::getline(std::cin, name, '\n');
    std::cout << name << "\n";
    */
}
















void Start()
{
    SummonmenuNoLog();




    Delete();
}

void SummonmenuNoLog()
{
    system("cls");
    std::cout << "[]======================================================================[]\n\n";
    std::cout << "\t\tДобро Пожаловать в 'Теплый ледъ'\n";
    std::cout << "\t\t    Введите Пароль\n\nВвод: ";
}






















template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dinArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dinArr[i] = staticArr[i];
    }
}

void CreateStorage()
{
    const int sizest = 10;
    int id[sizest]{ 0,1,2,3,4,5,6,7,8,9 };
    std::string name[sizest]
    {
                              "Cладкое ",
                              "Карамель",
                              "Фруктовое",
                              "Огурцовое",
                              "Клубничное",
                              "Шоколадное",
                              "Банановое",
                              "Пустое  ",
                              "Ванильное",
                              "Кокосовое"
    };

    int count[sizest]
    { 
                        4,
                        2,
                        3,
                        3,
                        5,
                        1,
                        4,
                        0,
                        2,
                        1 
    };
    double price[sizest]{ 
                            125 , 
                            150.75, 
                            149.89 , 
                            72.85 , 
                            179.89, 
                            240.20, 
                            345.50, 
                            65.65, 
                            94.85, 
                            139.98 
    };

    FillArray(id, idArr, sizest);
    FillArray(name, nameArr, sizest);
    FillArray(count, countArr, sizest);
    FillArray(price, priceArr, sizest);
}

void Delete()
{
    delete[]priceArr;
    delete[]countArr;
    delete[]nameArr;
    delete[]idArr;

}