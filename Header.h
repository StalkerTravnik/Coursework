#pragma once
#include "CardofPatien.h"
#include "Doctor.h"
#include "Schedule.h"

//Функция добавления нового пациента в список пациетов
void AddNewPatien(list<CardofPatien*>& ListofPatien);
//Функция добавление нового врача в список врачей
void AddNewDoctor(list<Doctor*>& listofdoctors);
//Функция добавления списка фрачей в файл
void AddDoctortoFile(list<Doctor*>& listofdoctors);
//Функция показа списка пациетнов
void ShowList(list<CardofPatien*>& ListofPatien);
//Функция показа списка врачей
void ShowList(list<Doctor*>& listofdoctors);
void ShowList(list<Schedule*>&);
void ShowList(list<CardofPatien*>& ListofPatien);
//Функия добавления списка пациэнтов в файл
void AddPatientoFile(list<CardofPatien*> &Patien);
//Функия добавления списка пациэнтов из файл
void GetPatienfromFile(list<CardofPatien*>& Patien);
//Функия добавления списка врачей из файл
void GetDoctorfromFile(list<Doctor*>& listofdoctors);
void Save_Schedule_to_file(std::list<Schedule*>&);
void Get_Schedule_from_file(std::list<Schedule*>&);
void AddPatientoPriem(list<Schedule*>&,string,int,int);