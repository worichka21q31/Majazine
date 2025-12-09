#pragma once
inline void Getline(std::string& line);
void SummonmenuNoLog();

void СhangeStoroge();

void ShowIncome();

bool Logout();


void ShowAdmMenu();

void ShowUserMenu();

void ChangeName();

bool Checkpass(const std::string& str);

bool Checklogin(const std::string& str);

void Setpasssymbols();

void Setloginsymbols();

void Addnewuser();

void Showuser(int mode);

void Selling();

void Changeuser();

void Changepass();

void CheckArrAppend();

void PrintCheck(double& totalsum);

void DeleteUser();

void Start();

void StorageReturn();

void ShowStorage(int mode);

void AddStorageItem();

bool IsNumber(const std::string& str);

void ShowSuperAdmMenu();

bool Login();

inline void Err(int time = 1500);

void CreateStorage();

template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dinArr[], int size);

void Delete();

void SumonToLogin();

void RemoveStorageItem();

void СhangePrice();

void AddNewItem();

void Deleteitem();
