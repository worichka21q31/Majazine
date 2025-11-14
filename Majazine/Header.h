#pragma once
inline void Getline(std::string& line);
void SummonmenuNoLog();

void Start();

void ShowStorage(int mode );

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
