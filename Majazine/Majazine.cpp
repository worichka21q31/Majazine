#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#include "Header.h"
#include <unordered_set>


// Значения...
bool isstotageCreated = false;
size_t siz = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
size_t userSize = 2;
size_t staff_count = 1;
bool isloginsetcreate = false;
bool ispasssetcreate = false;
double* bonusarr = new double[userSize] {0.0, 0.0, 0.0};
unsigned int* useridArr = new unsigned int[userSize]{1,2};
std::unordered_set<char> loginsymbols;
std::unordered_set<char> passsymbols;
// Учетки...
std::string userStatus[3]{ "superAdmin", "admin", "user" };
std::string* loginArr = new std::string[userSize]{ "admin", "user" };
std::string* loginNameArr = new std::string[userSize]{ "Иванов Сеергеев", "Сир Геев" };
std::string* passArr = new std::string[userSize]{ "admin", "user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string curretStatus;
unsigned int curretid;

// Продажа...
size_t checksize = 0;
int* idArrCheck;
std::string* nameArrCheck;
unsigned int* countArrCheck;
double* priceArrCheck;
double* totalPriceArrCheck;

double cashIncome = 0.0;
double bankIncome = 0.0;
double cash = 3000 + rand() % 7500;


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
    while (true)
    {
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
                if (isstotageCreated == false)
                {
                    CreateStorage();
                }
                ShowAdmMenu();
            }
            else if (curretStatus == userStatus[2])
            {
                if (isstotageCreated == false)
                {
                    CreateStorage();
                }
                ShowUserMenu();
            }
            else
            {
                system("cls");
                std::cout << "Для Завершение Работы Програмы Введите пароль Ас.Админа";
                Getline(choose);
                if (choose == passArr[0])
                {
                    break;
                }
                else if (choose == "exit")
                {
                    continue;
                }
            }

        }
    }
    Delete();

}
bool Login()
{
    std::string login, pass;

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
                std::cout << "[]  ..=*=..     []\t Фио: " << loginNameArr[i] << "\n";
                std::cout << "[](.\\.||./.)~~**[]\n";
                std::cout << "[][][][][][][][][]\n\n\n";
                std::cout << "Пользовательское соглашение:\n";
                std::cout << "1.1. Настоящее Пользовательское соглашение (далее – Соглашение) относится к сайту\n Интернет - магазина «mosteplitsa.ru», расположенно по адресу \nhttps  с сайтом https :1.2.Сайт Интернет - магазина «mosteplitsa.ru»(далее – Сайт)\n является собственностью ООО «АлВа».\n1.3.Настоящее Соглашение регулирует отношения между Администрацией\n";
                system("pause");
                curretStatus = statusArr[i];
                curretid = useridArr[i];
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
    std::cout << "[]====================Зараженный===================[]\n\n";
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
    unsigned int id[sizest]{ 1,2,3,4,5,6,7,8,9,10 };
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
        delete[]priceArr; delete[] countArr; delete[] nameArr; delete[] idArr;
    }
    delete[]loginArr; delete[] passArr; delete[] statusArr; delete[] loginNameArr; delete[] bonusarr; delete[] useridArr;
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
    else if (mode == 1)
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
    else if (mode == 3)
    {
        system("cls");
        std::cout << "[]======================Зараженный========================[]\n";
        std::cout << "[]\tID\t" << std::left << std::setw(25) << "Название Товара"
            << "\t\t\t" << "[]\n";
        for (size_t i = 0; i < siz; i++)
        {
            std::cout << "[]\t" << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t\t\t" << "[]\n";
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
            Selling();
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
            СhangeStoroge();
        }
        else if (choose == "7")
        {
            Changeuser();
        }
        else if (choose == "8")
        {
            ShowIncome();
        }
        else if (choose == "0")
        {
            if (Logout())
            {
                break;
            }
        }

        else
        {
            Err();
        }
    } while (true);

}
void ShowAdmMenu()
{

    std::string choose;
    do
    {
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tВыберите опцию\n1 - Начать продажу\n2 - Показать склад";
        std::cout << "\n3 - Пополнить склад\n4 - Списать товар";
        std::cout << "\n6 - Редактировать склад";
        std::cout << "\n7 - Редактировать Персонал\n8 - Отчет о прибыли";
        std::cout << "\n0 - Выйти\nВвод -> ";

        Getline(choose);
        if (choose == "1")
        {
            Selling();
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
        else if (choose == "6")
        {
            СhangeStoroge();
        }
        else if (choose == "7")
        {
            Changeuser();
        }
        else if (choose == "8")
        {
            ShowIncome();
        }
        else if (choose == "0")
        {
            if (Logout())
            {
                break;
            }
        }

        else
        {
            Err();
        }
    } while (true);
}
void ShowUserMenu()
{
    std::string choose;
    do
    {
        system("cls");
        std::cout << "[]===================Зараженный===================[]\n\n";
        std::cout << "\tВыберите опцию\n1 - Начать продажу\n2 - Показать склад";
        std::cout << "\n3 - Пополнить склад";
        std::cout << "\n4 - Отчет о прибыли";
        std::cout << "\n0 - Выйти\nВвод -> ";

        Getline(choose);
        if (choose == "1")
        {
            Selling();
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
            ShowIncome();
        }
        else if (choose == "0")
        {
            if (Logout())
            {
                break;
            }
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
bool IsNumber(const std::string& str)
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
void СhangeStoroge()
{
    std::string choose;
    system("cls");
    std::cout << "[]========================Зараженный=======================[]\n";
    std::cout << "\tВыберите опцию\n1 - Добавить новый товар\n2 - Изменить название товара";
    std::cout << "\n3 - Удалить товар\n0 - выйти\nВвод -> ";
    Getline(choose);
    if (choose == "1")
    {
        AddNewItem();
    }
    else if (choose == "2")
    {
        ChangeName();
    }
    else if (choose == "3")
    {

    }
    else if (choose == "0")
    {
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
void AddNewItem()
{
    std::string newName, newPrice, newCount, choosee;
    double price = 0.0;
    unsigned int count = 0;
    bool exit;

    while (true)
    {
        exit = true;
        while (true)
        {
            system("cls");
            std::cout << "[]===================Admin_menu===================[]\n";
            std::cout << "\tВыбор: Введите ИМЯ нового товара \n\t или EXIT для выхода\nВвод-> ";
            Getline(newName);

            if (newName == "exit")
            {
                std::cout << "\nВыход...";
                Sleep(1500);
                exit = false;
                break;
            }
            if (newName.size() <= 0 || newName.size() >= 30)
            {
                std::cout << "\nОшибка!! имя не может быть длинее чем 25 см.";
                Sleep(1500);
            }
            else
            {
                break;
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]===================Admin_menu===================[]\n";
            std::cout << "\tВыбор: Введите ЦЕНУ нового товара \n\t или EXIT для выхода\nВвод-> ";
            Getline(newPrice);

            if (newCount == "exit")
            {
                std::cout << "\nВыход...";
                Sleep(1500);
                exit = false;
                break;
            }
            if (IsNumber(newPrice))
            {
                price = std::stod(newPrice);
                if (price <= 0 || price >= 52300)
                {
                    std::cout << "\nОшибка!! Цена более 52300 - бред.";
                    Sleep(1500);
                }
                else
                {
                    break;
                }
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]===================Admin_menu===================[]\n";
            std::cout << "\tВыбор: Введите КОЛ-ВО нового товара \n\t или EXIT для выхода\nВвод-> ";
            Getline(newCount);

            if (newCount == "exit")
            {
                std::cout << "\nВыход...";
                Sleep(1500);
                exit = false;
                break;
            }
            if (IsNumber(newCount))
            {
                count = std::stoi(newCount);
                if (count <= 0 || count >= 100)
                {
                    std::cout << "\nОшибка!! 100 макс.";
                    Sleep(1500);
                }
                else
                {
                    break;
                }
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]===================Admin_menu===================[]\n\n";
            std::cout << "\tИмя: " << newName;
            std::cout << "\n\tЦена: " << price;
            std::cout << "\n\tКол-во: " << count << std::endl;
            std::cout << "\tПодтверждение:\n\t1 - Да ; 2 - Нет\nВвод-> ";
            Getline(choosee);
            if (choosee == "1")
            {
                siz++;
                unsigned int* bufIdArr = new unsigned int[siz];
                std::string* bufNameArr = new std::string[siz];
                unsigned int* bufCountArr = new unsigned int[siz];
                double* bufPriceArr = new double[siz];


                FillArray(idArr, bufIdArr, siz - 1);
                FillArray(nameArr, bufNameArr, siz - 1);
                FillArray(countArr, bufCountArr, siz - 1);
                FillArray(priceArr, bufPriceArr, siz - 1);

                bufIdArr[siz - 1] = siz;
                bufNameArr[siz - 1] = newName;
                bufCountArr[siz - 1] = count;
                bufPriceArr[siz - 1] = price;

                std::swap(idArr, bufIdArr);
                std::swap(nameArr, bufNameArr);
                std::swap(countArr, bufCountArr);
                std::swap(priceArr, bufPriceArr);

                delete[] bufIdArr; delete[] bufNameArr; delete[] bufCountArr; delete[] bufPriceArr;
                system("cls");
                std::cout << "[]===================Admin_menu===================[]\n\n";
                std::cout << "\tБрррр... \n";
                Sleep(2000);
                std::cout << "\tБип-вап \n";
                Sleep(2000);
                std::cout << "\tБжжжж \n";
                Sleep(1500);
                break;

            }
            else if (choosee == "2")
            {
                std::cout << "\nОтмена";
                Sleep(1500);
                break;
            }
            else
            {
                Err();
            }
        }
        break;
    }

}
void Deleteitem()
{
    std::string choose;
    unsigned int id = 0;
    while (true)
    {
        system("cls");
        ShowStorage(3);
        std::cout << "\nвведите id/exit - ";
        Getline(choose);
        if (choose == "exit")
        {
            std::cout << "отмена";
            Sleep(1500);
            break;
        }
        if (IsNumber(choose))
        {
            id = std::stoi(choose) - 1;
            if (id < 0 || id > siz - 1)
            {
                std::cout << "неверный id";
                Sleep(1500);
            }
            else
            {
                std::cout << "удаление" << nameArr[id] << "\n\n";
                std::cout << "подтвердить \n1 - да \n2 - нет\n";
                Getline(choose);
                if (choose == "1")
                {
                    siz--;
                    unsigned int* idarrtemp = new unsigned int[siz];
                    std::string* namearrtemp = new std::string[siz];
                    unsigned int* countarrtemp = new unsigned int[siz];
                    double* pricearrtemp = new double[siz];

                    for (size_t i = 0, c = 0; i < siz; i++, c++)
                    {
                        if (id == c)
                        {
                            c++;
                        }
                        idarrtemp[i] = i + 1;
                        namearrtemp[i] = nameArr[c];
                        countarrtemp[i] = countArr[c];
                        pricearrtemp[i] = priceArr[c];
                    }

                    std::swap(idArr, idarrtemp);
                    std::swap(nameArr, namearrtemp);
                    std::swap(countArr, countarrtemp);
                    std::swap(priceArr, pricearrtemp);

                    delete[] idarrtemp; delete[] namearrtemp; delete[] countarrtemp; delete[] pricearrtemp;
                    break;
                }
                else if (choose == "2")
                {
                    std::cout << "отмена";
                    Sleep(1500);
                }
            }
        }
    }
}
void ChangeName()
{
    std::string chooseId, newName, choose;
    unsigned int id = 0;
    while (true)
    {
        ShowStorage(3);
        std::cout << "[]=======================Admin_menu=======================[]\n\n";
        std::cout << "\tВыбор: Введите ID товара \n\t или EXIT для выхода\nВвод-> ";
        Getline(chooseId);
        if (chooseId == "exit")
        {
            std::cout << "\n\tОтмена Галя гредет";
            Sleep(1555);
            break;
        }
        if (IsNumber(chooseId))
        {
            while (true)
            {
                system("cls");
                std::cout << "[]=====================Admin_menu=====================[]\n\n";
                std::cout << "\tВыбор: Введите ИМЯ товара \nВвод-> ";

                Getline(newName);
                if (newName.size() <= 0 || newName.size() >= 30)
                {
                    std::cout << "\nОшибка!! имя не может быть длинее чем 25 см.";
                    Sleep(1500);
                }
                else
                {
                    id = std::stoi(chooseId) - 1;
                    if (id < 0 || id > siz - 1)
                    {
                        std::cout << "\nОшибка!! Неверный Айди.";
                    }
                    else
                    {
                        system("cls");
                        std::cout << "[]===================Admin_menu===================[]\n\n";
                        std::cout << "\t" << nameArr[id] << "---> " << newName;
                        std::cout << "\n\tПодтверждение:\n\t1 - Да ; 2 - Нет\nВвод-> ";
                        Getline(choose);
                        if (choose == "1")
                        {
                            nameArr[id] = newName;
                            break;
                        }
                        else
                        {
                            std::cout << "\nОтмена.";
                            Sleep(1500);
                        }

                    }

                }
            }
        }
        else
        {
            std::cout << "\nОшибка!! Неверный Айди.";
        }

    }


}
bool Checkpass(const std::string& str)
{
    std::unordered_set<char> specialsymbols{ '!', '@' , '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '/', '?', '|', '\\', '\"', '\'', ',', '.', '<', '>', '~', '`', ':', ';', '{', '}', '[', ']' };
    int numcount = 0, specsymcount = 0;
    if (str.size() < 8 || str.size() > 30)
    {
        std::cout << "ошибка длины";
        Sleep(1500);
        return false;
    }
    for (char sym : str)
    {
        if (passsymbols.count(sym))
        {
            std::cout << "некоректный пароль";
            Sleep(1500);
            return false;
        }
        if (std::isdigit(sym))
        {
            numcount++;
        }
        if (specialsymbols.count(sym))
        {
            specsymcount++;
        }
    }
    if (numcount > 2 && specsymcount > 2)
    {
        return true;
    }
    else
    {
        std::cout << "должно быть больше 3 спецсимволов и чисел";
        Sleep(1500);
        return false;
    }
}
bool Checklogin(const std::string& str)
{
    if (str.size() < 4 || str.size() > 20)
    {
        std::cout << "ошибка длины";
        Sleep(1500);
        return false;
    }

    for (char sym : str)
    {
        if (!loginsymbols.count(sym))
        {
            std::cout << "некоректный логин";
            Sleep(1500);
            return false;
        }
    }

    for (int i = 0; i <= userSize; i++)
    {
        if (str == loginArr[i])
        {
            std::cout << "уже есть";
            Sleep(1500);
            return false;
        }
    }
    return true;
}
void Setpasssymbols()
{
    for (char i = '!'; i <= '&'; i++)
    {
        passsymbols.insert(i);
    }
    for (char i = '('; i <= '+'; i++)
    {
        passsymbols.insert(i);
    }
    for (char i = '/'; i <= '~'; i++)
    {
        passsymbols.insert(i);
    }
    isloginsetcreate = true;
}
void Setloginsymbols()
{
    for (char i = '0'; i <= '9'; i++)
    {
        loginsymbols.insert(i);
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        loginsymbols.insert(i);
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        loginsymbols.insert(i);
    }
    isloginsetcreate = true;
}
void Addnewuser()
{
    std::string newlogin, newname, newrole, newpass, choose;
    bool exit = true;
    while (true)
    {
        while (true)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\tВыбор: Введите логин нового пользователя/exit\n";
            std::cout << "Ввод -> ";
            Getline(newlogin);
            if (newlogin == "exit")
            {
                std::cout << "отмена";
                exit = false;
                Sleep(1500);
                break;
            }
            if (Checklogin(newlogin))
            {
                break;
            }
            else
            {
                std::cout << "\nсимволы a-z A-Z 0-9";
                Sleep(1500);
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\tВыбор: Введите фио нового пользователя/exit\n";
            std::cout << "Ввод -> ";
            Getline(newname);
            if (newname == "exit")
            {
                std::cout << "отмена";
                exit = false;
                Sleep(1500);
                break;
            }
            if (newname.size() > 5 && newname.size() < 35)
            {
                break;
            }
            else
            {
                std::cout << "\n Миминум 5 макс 35";
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\tВыбор: Введите пароль нового пользователя/exit\n";
            std::cout << "Ввод -> ";
            Getline(newpass);
            if (newpass == "exit")
            {
                std::cout << "отмена";
                exit = false;
                Sleep(1500);
                break;
            }
            if (Checkpass(newpass))
            {
                break;
            }
            else
            {
                std::cout << "символы a-z A-Z 0-9, и спецсимволы";
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\tВыбор: Введите роль нового пользователя/exit";
            std::cout << "\n1 - User\n2 - Admin\n";
            std::cout << "Ввод -> ";
            Getline(choose);
            if (choose == "exit")
            {
                std::cout << "отмена";
                exit = false;
                Sleep(1500);
                break;
            }
            else if (choose == "1")
            {
                newrole = userStatus[2];
                break;
            }
            else if (choose == "2")
            {
                newrole = userStatus[2];
                break;
            }
            else
            {
                Err();
            }
        }
        while (exit)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\t" << newlogin << "\t" << newname << "\t" << newpass << "\t" << newrole;
            std::cout << "\n1 - Да\n2 - Нет\n";
            std::cout << "Ввод -> ";
            Getline(choose);
            if (choose == "1")
            {
                userSize++;
                std::string* bufNameArr = new std::string[userSize];
                std::string* bufLoginArr = new std::string[userSize];
                std::string* bufpassArr = new std::string[userSize];
                std::string* bufroleArr = new std::string[userSize];
                double* buffbonusarr = new double[userSize];


                FillArray(loginNameArr, bufNameArr, userSize - 1);
                FillArray(loginArr, bufLoginArr, userSize - 1);
                FillArray(passArr, bufpassArr, userSize - 1);
                FillArray(statusArr, bufroleArr, userSize - 1);
                FillArray(bonusarr, buffbonusarr, userSize - 1);

                bufNameArr[userSize - 1] = newname;
                bufLoginArr[userSize - 1] = newlogin;
                bufpassArr[userSize - 1] = newpass;
                bufroleArr[userSize - 1] = newrole;
                buffbonusarr[userSize - 1] = 0.0;

                std::swap(loginNameArr, bufNameArr);
                std::swap(loginArr, bufLoginArr);
                std::swap(passArr, bufpassArr);
                std::swap(statusArr, bufroleArr);
                std::swap(bonusarr, buffbonusarr);

                delete[] bufNameArr, bufLoginArr, bufpassArr, bufroleArr, buffbonusarr;
                system("cls");
                std::cout << "[]===================Admin_menu===================[]\n\n";
                std::cout << "\tБрррр... \n";
                Sleep(2000);
                std::cout << "\tБип-вап \n";
                Sleep(2000);
                std::cout << "\tБжжжж \n";
                Sleep(1500);
                break;

            }
            else if (choose == "2")
            {
                exit = false;
                break;
            }
            else
            {
                Err();
            }
        }
        break;
    }
}
void Showuser(int mode = 0)
{
    if (mode == 0)
    {
        system("cls");
        std::cout << " № \t" << std::left << std::setw(12) << "Логин\t" << "Пароль\t\t" << "Имя\t" << "\tРоль\n";
        std::cout << "[]========================================================[]\n";
        for (size_t i = 1; i < userSize; i++)
        {
            std::cout << i << "\t" << std::left << std::setw(15) << loginArr[i] << "\t" << passArr[i] << "\t\t" << loginNameArr[i] << "\t" << statusArr[i] << "\n";
        }
        std::cout << "\n";
    }
    else if (mode == 1)
    {
        system("cls");
        std::cout << " № \t" << std::left << std::setw(12) << "Логин\t" << "Пароль\t\t" << "Имя\t" << "\tРоль\n";
        std::cout << "[]========================================================[]\n";
        for (size_t i = 0; i < userSize; i++)
        {
            std::cout << i << "\t" << std::left << std::setw(15) << loginArr[i] << "\t" << passArr[i] << "\t\t" << loginNameArr[i] << "\t" << statusArr[i] << "\n";
        }
    }
}
void Changeuser()
{
    std::string choose;
    while (true)
    {
        if (isloginsetcreate == false)
        {
            Setloginsymbols();
        }
        system("cls");
        std::cout << "[]========================================================[]\n";
        std::cout << "1 - Добавить нового работника\n";
        std::cout << "2 - Показать работников\n";
        std::cout << "3 - Изменить пароль\n";
        std::cout << "4 - Уволить работника\n";
        std::cout << "0 - выход\n";
        std::cout << "Вывод -> ";
        Getline(choose);
        system("cls");
        if (choose == "1" )
        {
            Addnewuser();
        }
        else if (choose == "2" && userSize > 1)
        {
            Showuser(0);
            system("pause");
        }
        else if (choose == "3" && userSize > 1)
        {
            Changepass();
        }
        else if (choose == "4" && userSize > 1)
        {
            DeleteUser();
        }
        else if (choose == "0")
        {
            break;
        }
        else
        {
            std::cout << "склад людей пуст\n";
        }
    }
}
void Changepass()
{
    std::string newPass1, newPass2, choose;
    int userId = 0, isAdmin = 0;

    while (true)
    {
        system("cls");
        if (curretStatus == userStatus[0])
        {
            Showuser(1);
            isAdmin = true;
        }
        else
        {
            Showuser(0);
            isAdmin = false;
        }
        std::cout << "[]===================Admin_menu===================[]\n";
        std::cout << "\tВыбор: Введите номер пользователя для смены пароля \n\t или EXIT для выхода\nВвод-> ";
        Getline(choose);
        if (choose == "exit")
        {
            std::cout << "\nОтмена операции";
            Sleep(1500);
            break;
        }
        else if(IsNumber(choose))
        {
            userId = std::stoi(choose);
            if (userId < isAdmin || userId > userSize - 1)
            {
                std::cout << "\nТакого пользователя нет";
                Sleep(1500);
                continue;
            }
        }
        else
        {
            Err();
        }
        while (true)
        {
            system("cls");

            if (curretStatus == userStatus[1] && statusArr[userId] == userStatus[1])
            {
                std::cout << "\nАдмину пароль не сменить!";
                Sleep(1500);
                break;
            }
            std::cout << "[]===================Admin_menu===================[]\n";
            std::cout << "\tВыбор: Введите новый пароль " << loginArr[userId] << " (" << loginNameArr[userId] << ")\nВвод-> ";
            Getline(newPass1);
            system("cls");
            std::cout << "[]===================Admin_menu===================[]\n";
            std::cout << "\tПодтверждение: Введите сменный пароль\nВвод-> ";
            Getline(newPass2);

            if (Checkpass(newPass1) && Checkpass && newPass1 == newPass2)
            {
                passArr[userId] = newPass1;
                std::cout << "\nУспешно!";
                Sleep(1500);
                break;
            }
            else
            {
                std::cout << "\nНТ!";
                Sleep(1500);
            }
        }
    }
        

}
void DeleteUser()
{
    std::string chooseId, chechPass, chose;
    int userId, IsAdmin = 1;

    while (true)
    {
        if (curretStatus == userStatus[0] && userSize > 2)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\tОшибка: ВСЕ УЖЕ УВОЛЕНЫw!!!!!!";
            Sleep(1500);
            return;
        }
        else if (curretStatus == userStatus[1] && staff_count < 1)
        {
            system("cls");
            std::cout << "[]========================================================[]\n";
            std::cout << "\tОшибка: ВСЕ СОТРУДНИКИ УЖЕ УВОЛЕНЫ!!!!!!";
            Sleep(1500);
            return;
        }
        system("cls");
        Showuser();
        std::cout << "\tВыбор: Введите номер для увольнения пользователя/exit\n";
        std::cout << "Ввод -> ";
        Getline(chose);
        if (chose == "exit")
        {
            std::cout << "\t\nОтмена";
            Sleep(1500);
            break;
        }
        else if (IsNumber(chose))
        {
            userId = std::stoi(chose);
            if (userId < IsAdmin || userId > userSize - 1)
            {
                std::cout << "Пользователь с таким н.. нету крч";
                Sleep(1500);
                break;
            }
            while (true)
            {
                system("cls");
                std::cout << "[]========================================================[]\n";
                if (curretStatus == userStatus[1] && statusArr[userId] == userStatus[1])
                {
                    std::cout << "\tНельзя увольнять админа";
                    Sleep(1500);
                    break;
                }
                std::cout << "\tНа казнь выставлен: " << loginArr[userId] << std::endl;
                std::cout << "\tдля подтверждения введите пароль супер админа/exit:\n";
                std::cout << "Ввод -> ";
                Getline(chechPass);
                if (chechPass == "exit")
                {
                    std::cout << "\t\nОтмена";
                    Sleep(1500);
                    break;
                }
                else if(chechPass == passArr[0])
                {
                    userSize--;
                    if (statusArr[userId] == userStatus[2])
                    {
                        staff_count--;
                    }
                    std::string* bufNameArr = new std::string[userSize];
                    std::string* bufLoginArr = new std::string[userSize];
                    std::string* bufpassArr = new std::string[userSize];
                    std::string* bufroleArr = new std::string[userSize];
                    double* buffbonusarr = new double[userSize];
                    unsigned int* bufUserId = new unsigned int[userSize];
                    for (size_t i = 0, c = 0; i < userSize; i++, c++)
                    {
                        if (userId == c)
                        {
                            c++;
                        }
                        bufNameArr[i] = loginNameArr[c];
                        bufLoginArr[i] = loginArr[c];
                        bufpassArr[i] = passArr[c];
                        bufroleArr[i] = statusArr[c];
                        buffbonusarr[i] = 0.0;
                        bufUserId[i] = i + 1;

                        std::swap(loginNameArr, bufNameArr);
                        std::swap(loginArr, bufLoginArr);
                        std::swap(passArr, bufpassArr);
                        std::swap(statusArr, bufroleArr);
                        std::swap(bonusarr, buffbonusarr);
                        std::swap(useridArr, bufUserId);


                        delete[] bufNameArr; delete[] bufLoginArr; delete[] bufpassArr; delete[] bufroleArr; delete[] buffbonusarr; delete[] bufUserId;
                    }

                }
                else
                {
                    Err();
                }
                break;
            }
        }
        break;
    }
}
void CheckArrAppend()
{
    checksize++;
    int* idArrCheckTemp = new int[checksize];
    std::string* nameArrCheckTemp = new std::string[checksize];
    unsigned int* countArrCheckTemp = new unsigned int[checksize];
    double* priceArrCheckTemp = new double[checksize];
    double* totalPriceArrCheckTemp = new double[checksize];

    FillArray(idArrCheck, idArrCheckTemp, checksize - 1);
    FillArray(nameArrCheck, nameArrCheckTemp, checksize - 1);
    FillArray(countArrCheck, countArrCheckTemp, checksize - 1);
    FillArray(priceArrCheck, priceArrCheckTemp, checksize - 1);
    FillArray(totalPriceArrCheck, totalPriceArrCheckTemp, checksize - 1);

    std::swap(idArrCheckTemp, idArrCheck);
    std::swap(nameArrCheckTemp, nameArrCheck);
    std::swap(countArrCheckTemp, countArrCheck);
    std::swap(priceArrCheckTemp, priceArrCheck);
    std::swap(totalPriceArrCheckTemp, totalPriceArrCheck);

    delete[] idArrCheckTemp; delete[] nameArrCheckTemp; delete[] countArrCheckTemp; delete[] priceArrCheckTemp; delete[] totalPriceArrCheckTemp;

}
void Selling()
{
    std::string choose, chooseCount, chooseMoney, chooseId;
    unsigned int id = 0, count = 0;
    int index = -1;
    double money = 0.0, totalSum = 0.0;
    bool isFirst = false;
    while (true)
    {
        system("cls");
        ShowStorage();
        std::cout << "[]====================Зараженный===================[]\n\n";
        std::cout << "\tВведите ID товара для покупке/exit\n";
        std::cout << "\nВвод --> ";
        Getline(chooseId);
        if (chooseId == "exit")
        {
            if (!isFirst)
            {
                std::cout << "\n";
                Sleep(1500);
                break;
            }

            system("cls");
            PrintCheck(totalSum);
            std::cout << "[]====================Зараженный===================[]\n";
            std::cout << "\n\tПодтвердить покупки?\n1 - Да\n2 - Купить еще\n3 - Отмена";
            std::cout << "\nВвода --> ";
            Getline(choose);
            if (choose == "1")
            {
                while (true)
                {
                    system("cls");
                    std::cout << "[]====================Зараженный===================[]\n";
                    std::cout << "\tВыберите способ оплаты\n1 - Наличка\n2 - Безнал\nВвод:";
                    Getline(choose);
                    if (choose == "1")
                    {
                        system("cls");
                        std::cout << "[]====================Зараженный===================[]\n";

                        std::cout << "\nК оплате: " << totalSum << "\n\n";
                        std::cout << "Введите кол-во налика: ";
                        Getline(chooseMoney);
                        if (IsNumber(chooseMoney))
                        {
                            money = std::stod(chooseMoney);
                            if (money < totalSum)
                            {
                                std::cout << "Недст средвтв";
                                Sleep(1500);
                                continue;
                            }
                            else if(money - totalSum > cash)
                            {
                                std::cout << "Cорян сдачи нет";
                                Sleep(1500);
                                continue;
                            }
                            else
                            {
                                std::cout << "Ваши: " << money << "\n\n";
                                Sleep(400);
                                std::cout << "Оплата прошла успешно. Сдача: " << money - totalSum << " рублей\n";
                                Sleep(2000);
                                cash += totalSum;
                                cashIncome += totalSum;
                                bonusarr[curretid] += totalSum;
                                break;
                            }
                        }
                        Sleep(1500);
                        system("cls");
                        break;
                    }
                    else if (choose == "2")
                    {
                        system("cls");
                        std::cout << "[]====================Зараженный===================[]\n";
                        std::cout << "\tПриложите карту";
                        Sleep(1500);
                        if (rand() % 10 <= 2)
                        {
                            for (size_t i = 0; i < 5; i++)
                            {
                                std::cout << i + 1 << "\n\t";
                                Beep(500, 400);
                                Sleep(1000);
                            }
                            std::cout << "\nПровал!";
                            Sleep(1500);
                        }
                        else
                        {
                            for (size_t i = 0; i < 5; i++)
                            {
                                std::cout << i + 1 << "\n\t";
                                Beep(500, 400);
                                Sleep(1000);
                            }
                            std::cout << "\nУспешная покупка!";
                            Sleep(1500);
                            bankIncome += totalSum;
                            bonusarr[curretid] += totalSum;
                            system("cls");
                            break;
                        }
                    }
                    else if (choose == "hit" || choose == "Hit")
                    {
                        system("cls");
                        std::cout << "[]====================Зараженный===================[]\n";
                        std::cout << "\nВы срезали цены! Успешная покупка!";
                        Sleep(1500);
                        system("cls");
                        break;
                    }
                    else
                    {
                        Err();
                    }
                }
                delete[] idArrCheck; delete[] nameArrCheck; delete[] countArrCheck; delete[] priceArrCheck; delete[] totalPriceArrCheck;
                idArrCheck = nullptr;
                nameArrCheck = nullptr;
                countArrCheck = nullptr;
                priceArrCheck = nullptr;
                totalPriceArrCheck = nullptr;
                checksize = 0;
                break;
            }

            else if (choose == "2")
            {
                continue;
            }
            else if (choose == "3")
            {
                std::cout << "Отмена покупки\n";
                StorageReturn();
                Sleep(1500);
                system("cls");
                return;
            }
            else
            {
                Err();
                continue;
            }

        }
        if (IsNumber(chooseId))
        {
            id = std::stoi(chooseId) - 1;
            if (id < 0 || id > siz - 1)
            {
                std::cout << "\tОшибка";
                Sleep(1500);
                continue;
            }
        }
        else
        {
            continue;
        }

        system("cls");
        std::cout << "[]====================Зараженный===================[]\n\n";
        std::cout << "\tВведите кол-во \"" << nameArr[id] << "\" для покупке/exit\n";
        std::cout << "\nВвод --> ";
        Getline(chooseCount);
        if (chooseCount == "exit")
        {
            std::cout << "\tОбратно..";
            Sleep(1500);
            continue;
        }
        if (IsNumber(chooseCount))
        {
            count = std::stoi(chooseCount);
            if (count < 1 || count > countArr[id])
            {
                std::cout << "\tОшибка кол-ва. макс: " << countArr[id];
                Sleep(1500);
                continue;
            }
        }
        else
        {
            continue;
        }
        CheckArrAppend();
        if (!isFirst)
        {
            isFirst = true;
        }
        index++;
        idArrCheck[index] = idArr[id];
        nameArrCheck[index] = nameArr[id];
        priceArrCheck[index] = priceArr[id];
        countArrCheck[index] = count;
        totalPriceArrCheck[index] = count * priceArr[id];
        countArr[id] -= count;
        totalSum += totalPriceArrCheck[index];

        std::cout << "\n\tТовар добавлен в чек\n";
        Sleep(1000);
    }
}
void PrintCheck(double& totalsum)
{
    std::cout << " № \t" << "ID\t" << std::left << std::setw(25) << "Название" << "Цена за шт" << "\tКол-во" << "\tИтог\n";
    std::cout << "[]=========================================================================================[]\n";
    for (size_t i = 0; i < checksize; i++)
    {
        std::cout << i + 1 << "\t" << idArrCheck[i] << "\t" << std::left << std::setw(25) << nameArrCheck[i] << "" << priceArrCheck[i] << "\t\t" << countArrCheck[i] << "\n";
    }
    std::cout << "итого к оплате: " << totalsum << "\n\n";
}
void StorageReturn()
{
    for (size_t i = 0; i < checksize; i++)
    {
        countArr[idArrCheck[i] - 1] += countArrCheck[i];
    }
    delete[] idArrCheck; delete[] nameArrCheck; delete[] countArrCheck; delete[] priceArrCheck; delete[] totalPriceArrCheck;

    idArrCheck = nullptr;
    nameArrCheck = nullptr;
    countArrCheck = nullptr;
    priceArrCheck = nullptr;
    totalPriceArrCheck = nullptr;
    checksize = 0;
}
void ShowIncome()
{
    system("cls");
    std::cout << "[]====================Зараженный===================[]\n\n";
    std::cout << "Текущая прибыль за смену\n\n";
    std::cout << "Наличный расчёт:" << cashIncome << "\n";
    std::cout << "Наличный расчёт:" << bankIncome << "\n";
    std::cout << "Итого:" << bankIncome + cashIncome << "\n\n";
    std::cout << "Cумма ваших продаж:" << bonusarr[curretid] << "\n\n";

    system("pause");
    system("cls");
}
bool Logout()
{
    std::string choose;
    system("cls");
    while (true)
    {
        std::cout << "Для подтверждения выхода из выхода введите пароль/exit\n";
        Getline(choose);
        if (choose == "exit")
        {
            system("cls");
            return false;
        }
        else if (choose == passArr[curretid - 1] || choose == passArr[0])
        {
            system("cls");
            return true;
        }
        else
        {
            Err();
        }

    }
}
}
