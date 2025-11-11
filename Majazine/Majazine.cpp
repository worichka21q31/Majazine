#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include "Header.h"

// Значения...
bool isstotageCreated = false;
size_t siz = 0;
unsigned int* idArr ;
std::string* nameArr ;
unsigned int* countArr ;
double* priceArr ;
size_t userSize = 2;

// Учетки...
std::string userStatus[3]{ "superAdmin", "admin", "user"};
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* loginNameArr = new std::string[userSize]{ "Иванов Сеергеев", "Сир Геев" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string curretStatus;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    Start();

    return 0;
}


void Start()
{
    if (Login())
    {
        if (curretStatus == userStatus[0])
        {

        }
        else if (curretStatus == userStatus[1])
        {

        }
        else if (curretStatus == userStatus[2])
        {

        }
        else
        {
            system("cls");
            std::cout << "Завершение Работы Програмы ";
        }

    }
    Delete();

}
bool Login()
{

    std::string login,  pass;
    

    while (true)
    {
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tАвторизация:Вход в Аккаунт\nLogin: ";
        Getline(login);
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tАвторизация:Вход в Аккаунт\nLogin: " << login;
        std::cout << "\nPassword: ";
        Getline(pass);
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tАвторизация:Вход в Аккаунт\nLogin: " << login;
        std::cout << "\nPassword: ";
        for (size_t i = 0; i < pass.size(); i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        system("pause");
        if (login == "exit" && pass == "exit")
        {
            curretStatus = "";
            return false;
        }
        for (size_t i = 0; i < userSize; i++)
        {
            if (login == loginArr[i] && pass == passArr[i])
            {

                system("cls");
                std::cout << "[]===================Зараженный===================[]\n\n";
                std::cout << "[][][][][][][][][]\n";
                std::cout << "[] ./ \\…/ \\.    []\t Пользователь: " << login << "\n";
                std::cout << "[](.‘•..•’.)    []\t Статус: " << statusArr[i] << "\n";
                std::cout << "[]  ..=*=..     []\t Фио: "<< loginNameArr[i] << "\n";
                std::cout << "[](.\\.||./.)~~**[]\n";
                std::cout << "[][][][][][][][][]\n\n\n";
                std::cout << "Пользовательское соглашение:\n";
                std::cout << "1.1. Настоящее Пользовательское соглашение (далее – Соглашение) относится к сайту\n Интернет - магазина «mosteplitsa.ru», расположенно по адресу \nhttps  с сайтом https :1.2.Сайт Интернет - магазина «mosteplitsa.ru»(далее – Сайт)\n является собственностью ООО «АлВа».\n1.3.Настоящее Соглашение регулирует отношения между Администрацией\n";
                system("pause");
                curretStatus = statusArr[i];
                return true;
            }
        }
        
    }

    
}
inline void Err(int time)
{
    std::cout << "Некорректный ввод";
    Sleep(time);
    system("cls");
}
void SumonToLogin()
{
    std::string login, pass, loginTo, passTo;

    do
    {
        do
        {
            system("cls");
            std::cout << "[]===================Зараженный===================[]\n\n";
            std::cout << "\tРегистрация:Создание Аккаунта\nLogin: ";
            Getline(login);
            if (login.size() < 3)
            {

                std::cerr << "Ошибка! слишком короткий\n";
                system("pause");
            }
            else if (login.size() > 13)
            {
                std::cerr << "Ошибка! слишком длинный\n";
                system("pause");
            }
        } while (login.size() < 3 || login.size() > 13);
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tРегистрация:Создание Аккаунта\nLogin: " << login;
        std::cout << "\nPassword: ";
        do
        {
            Getline(pass);
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
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tАвторизация:Вход в Аккаунта\nLogin: ";
        Getline(login);
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tАвторизация:Вход в Аккаунта\nLogin: " << loginTo << "\nPassword: ";
        Getline(login);
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tАвторизация:Вход в Аккаунта\nLogin: " << loginTo << "\nPassword: ";
        for (size_t i = 0; i < passTo.size(); i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
        system("pause");
        system("cls");

        if (login != loginTo || pass != passTo)
        {

            std::cerr << "Ошибка! невернный логин или пароль\n";
            system("pause");
        }

    } while (login != loginTo || pass != passTo);
}
void SummonmenuNoLog()
{
    system("cls");
    std::cout << "[]===================Зараженный===================[]\n\n";
    std::cout << "\t\tДобро Пожаловать в ''\n";
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
    isstotageCreated = true;
    const int sizest = 10;
    unsigned int id[sizest]{ 0,1,2,3,4,5,6,7,8,9 };
    std::string name[sizest]
    {
                              "Имя Для Ребенка",
                              "Название Фирмы",
                              "Повседневная Идея",
                              "Опасная Идея",
                              "ГеймДизайнерский провал",
                              "Кодовая Идея",
                              "Аполиптическая Идея",
                              "Межгалоктический провал",
                              "Та самая идея",
                              "Не Та самая идея"
    };

    unsigned int count[sizest]
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
                            125, 
                            150.75, 
                            149.89, 
                            72.85, 
                            179.89, 
                            240.20, 
                            345.50, 
                            6275.65, 
                            2194.85, 
                            1239.98 
    };
    idArr = new unsigned int[sizest];
    nameArr = new std::string[sizest];
    countArr = new unsigned int[sizest];
    priceArr = new double[sizest];

    FillArray(id, idArr, sizest);
    FillArray(name, nameArr, sizest);
    FillArray(count, countArr, sizest);
    FillArray(price, priceArr, sizest);
}
inline void Getline(std::string& line)
{
    std::getline(std::cin, line, '\n');
}
void Delete()
{
    if (isstotageCreated)
    {
        delete[]priceArr, countArr, nameArr, idArr;
    }
    delete[]loginArr, passArr, statusArr, loginNameArr;


}
