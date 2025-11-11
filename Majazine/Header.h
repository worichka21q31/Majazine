#pragma once
inline void Getline(std::string& line);
void SummonmenuNoLog();

void Start();

bool Login();

inline void Err(int time = 1500);

void CreateStorage();

template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dinArr[], int size);

void Delete();

void SumonToLogin();
