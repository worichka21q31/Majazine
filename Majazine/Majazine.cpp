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
    std::string choose;
    if (Login())
    {
        if (curretStatus == userStatus[0])
        {
            do
            {
                system("cls");
                std::cout << "[]===================Зараженный===================[]\n\n";
                std::cout << "\tВыберите Склад\n1 - Готовый Склад\n2 - Создать новый\nВвод -> ";
                Getline(choose);
            } while (choose != "1" && choose != "2");
            if (choose == "1")
            {
                CreateStorage();
                ShowSuperAdmMenu();
            }
            else if (choose == "2")
            {

            }
            else
            {
                Err();
            }
                
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
                std::cout << "[] .‘•..•’.     []\t Статус: " << statusArr[i] << "\n";
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
    std::cout << "[]==========-=========Зараженный===================[]\n\n";
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
    unsigned int id[sizest]{ 1,2,3,4,5,6,7,8,9,10};
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

    siz = sizest;
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
void ShowStorage(int mode = 0)
{
    if (mode == 0)
    {

        system("cls");
        std::cout << "[]==========================Зараженный=============================[]\n";
        std::cout << "[]\tID\t" << std::left << std::setw(25) << "Название Товара"
            << "\tКол-во\t" << "\tЦена\t[]\n";
        for (size_t i = 0; i < siz; i++)
        {
            std::cout << "[]\t" << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t"
                << countArr[i] << "\t\t" << priceArr[i] << "\t[]\n";
        }
        std::cout << "[]=================================================================[]\n\n";
    }
    else if(mode == 1)
    {
        system("cls");
        std::cout << "[]======================Зараженный========================[]\n";
        std::cout << "[]\tID\t" << std::left << std::setw(25) << "Название Товара"
            << "\tКол-во\t\t" << "[]\n";
        for (size_t i = 0; i < siz; i++)
        {
            std::cout << "[]\t" << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t"
                << countArr[i] << "\t" << "\t[]\n";
        }
        std::cout << "[]========================================================[]\n";
    }
    else if (mode == 2)
    {
        system("cls");
        std::cout << "[]======================Зараженный========================[]\n";
        std::cout << "[]\tID\t" << std::left << std::setw(25) << "Название Товара"
            << "\tЦена\t\t" << "[]\n";
        for (size_t i = 0; i < siz; i++)
        {
            std::cout << "[]\t" << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t"
                << priceArr[i] << "\t" << "\t[]\n";
        }

    }
}
void ShowSuperAdmMenu()
{
    std::string choose;
    do
    {
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tВыберите опцию\n1 - Начать продажу\n2 - Показать склад";
        std::cout << "\n3 - Пополнить склад\n4 - Списать товар";
        std::cout << "\n5 - Изменить цену\n6 - Редактировать склад";
        std::cout << "\n7 - Редактировать Персонал\n8 - Отчет о прибыли";
        std::cout << "\n0 - Выйти\nВвод -> ";

        Getline(choose);
        if (choose == "1")
        {
            
        }
        else if (choose == "2")
        {
            ShowStorage();
            system("pause");
        }
        else if (choose == "3")
        {
            AddStorageItem();
        }
        else if (choose == "4")
        {
            RemoveStorageItem();
        }
        else if (choose == "5")
        {
            СhangePrice();
        }
        else if (choose == "6")
        {
            ;
        }
        else if (choose == "7")
        {
            ;
        }
        else if (choose == "8")
        {
            ;
        }
        else if (choose == "0")
        {
            break;
        }

        else
        {
            Err();
        }
    } while (true);

}
void AddStorageItem()
{

    std::string chooseId, chooseCount, choose;
    unsigned int id = 0, count = 0;
    
    while (true)
    {      
        system("cls");
        ShowStorage(1);
        std::cout << "[]========================================================[]\n";
        std::cout << "\tВыбор: Введите ID товара или Слово EXIT для выхода\n";
        std::cout << "Ввод ->";
        Getline(chooseId);
        if (chooseId == "exit")
        {
            std::cout << "Отмена операции пополнения товара\n";
            Sleep(1500);
            break;
        }
        else if (!IsNumber(chooseId))
        {
            Err();
            continue;
        }
        if (IsNumber(chooseId))
        {
            int chooseIdInt = std::stoi(chooseId) - 1;

            system("cls");
            std::cout << "[]========================Зараженный=======================[]\n\n";
            std::cout << "\tВыбор: Введите Кол-Во \"" << nameArr[chooseIdInt] << "\" \n";
            std::cout << "Ввод ->";
            Getline(chooseCount);
        }
        else
        {
            Err();
            continue;
        }
        if (IsNumber(chooseCount) && IsNumber(chooseId))
        {
            id = std::stoi(chooseId) - 1;
            count = std::stoi(chooseCount);

            if (id < 0 || id > siz - 1 || count < 0 || count > 100)
            {
                std::cout << "Некорректный ID или кол-во товара\nМаксимальное кол-во 100\n";
                Sleep(1500);
            }
            else
            {
                system("cls");
                std::cout << "[]========================Зараженный=======================[]\n\n";
                std::cout << "\t" << std::left << std::setw(25) << nameArr[id] << countArr[id] << " -----> "
                    << countArr[id] + count << "\n\n";
                std::cout << "[]========================================================[]\n";
                std::cout << "Подтвердить?\n 1 - Да \n 2 - Нет\nВвод ->";
                Getline(choose);
                if (choose == "1")
                {
                    countArr[id] += count;
                    std::cout << "Товар успешно пополнен\n\n";
                    Sleep(1500);
                    system("cls");
                    break;
                }
                else if (choose == "2")
                {
                    std::cout << "Отмена пополнения\n\n";
                    Sleep(1500);
                }
                else
                {
                    Err();
                }
                  
            }
        }

    }
    
}
bool IsNumber(const std::string &str)
{
    if (str.size() <= 0 || str.size() >= 10)
    {
        std::cout << "Ошибка длины числа. Максимум 9-Знач числа\n";
        Sleep(1500);
        return false;
    }
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
        {
            std::cout << "Введённые данные не являются числами\n";
            Sleep(1500);
            return false;
        }
    }
    return true;
}
void RemoveStorageItem()
{

    std::string chooseId, chooseCount, choose;
    unsigned int id = 0, count = 0;

    while (true)
    {
        system("cls");
        ShowStorage(1);
        std::cout << "[]========================================================[]\n";
        std::cout << "\tВыбор: Введите ID товара или Слово EXIT для выхода\n";
        std::cout << "Ввод ->";
        Getline(chooseId);
        if (chooseId == "exit")
        {
            std::cout << "Отмена операции убавления товара\n";
            Sleep(1500);
            break;
        }
        else if (!IsNumber(chooseId))
        {
            Err();
            continue;
        }
        if (IsNumber(chooseId))
        {
            int chooseIdInt = std::stoi(chooseId) - 1;

            system("cls");
            std::cout << "[]========================Зараженный=======================[]\n\n";
            std::cout << "\tВыбор: Введите Кол-Во \"" << nameArr[chooseIdInt] << "\" \n";
            std::cout << "Ввод ->";
            Getline(chooseCount);
        }
        else
        {
            Err();
            continue;
        }
        if (IsNumber(chooseCount) && IsNumber(chooseId))
        {
            id = std::stoi(chooseId) - 1;
            count = std::stoi(chooseCount);

            if (id < 0 || id > siz - 1 || count < 0 || count > countArr[id])
            {
                std::cout << "Некорректный ID или кол-во товара\nМаксимальное кол-во = " << countArr[id] << "\n";
                Sleep(1500);
            }
            else
            {
                system("cls");
                std::cout << "[]========================Зараженный=======================[]\n\n";
                std::cout << "\t" << std::left << std::setw(25) << nameArr[id] << countArr[id] << " -----> "
                    << countArr[id] - count << "\n\n";
                std::cout << "[]========================================================[]\n";
                std::cout << "Подтвердить?\n 1 - Да \n 2 - Нет\nВвод ->";
                Getline(choose);
                if (choose == "1")
                {
                    countArr[id] -= count;
                    std::cout << "Товар успешно убавления\n\n";
                    Sleep(1500);
                    system("cls");
                    break;
                }
                else if (choose == "2")
                {
                    std::cout << "Отмена убавления\n\n";
                    Sleep(1500);
                }
                else
                {
                    Err();
                }

            }
        }

    }

}

void СhangePrice()
{

    std::string chooseId, choosePrice, choose;
    unsigned int id = 0;
    double price = 0;

    while (true)
    {
        system("cls");
        ShowStorage(2);
        std::cout << "[]========================================================[]\n";
        std::cout << "\tВыбор: Введите ID товара или Слово EXIT для выхода\n";
        std::cout << "Ввод ->";
        Getline(chooseId);
        if (chooseId == "exit")
        {
            std::cout << "Отмена операции изменения цены\n";
            Sleep(1500);
            break;
        }
        else if (!IsNumber(chooseId))
        {
            Err();
            continue;
        }
        if (IsNumber(chooseId))
        {
            int chooseIdInt = std::stoi(chooseId) - 1;

            system("cls");
            std::cout << "[]========================Зараженный=======================[]\n\n";
            std::cout << "\tВыбор: Введите Новую цену для \"" << nameArr[chooseIdInt] << "\" \n";
            std::cout << "Ввод ->";
            Getline(choosePrice);
        }
        else
        {
            Err();
            continue;
        }
        if (IsNumber(choosePrice) && IsNumber(chooseId))
        {
            id = std::stoi(chooseId) - 1;
            price = std::stoi(choosePrice);

            if (id < 0 || id > siz - 1 || price < 0 || price > 16999)
            {
                std::cout << "Некорректный ID или кол-во товара\nМаксимальная цена = 16999\n";
                Sleep(1500);
            }
            else
            {
                system("cls");
                std::cout << "[]========================Зараженный=======================[]\n\n";
                std::cout << "\t" << std::left << std::setw(25) << nameArr[id] << priceArr[id] << " -----> "
                    << price << "\n\n";
                std::cout << "[]========================================================[]\n";
                std::cout << "Подтвердить?\n 1 - Да \n 2 - Нет\nВвод ->";
                Getline(choose);
                if (choose == "1")
                {
                    priceArr[id] = price;
                    std::cout << "Цена успешна изменена\n\n";
                    Sleep(1500);
                    system("cls");
                    break;
                }
                else if (choose == "2")
                {
                    std::cout << "Отмена\n\n";
                    Sleep(1500);
                }
                else
                {
                    Err();
                }

            }
        }

    }

}
