#pragma once
#include "CardofPatien.h"
#include "Doctor.h"
#include "Schedule.h"

/////////////////Пациент//////////////////
void ShowList(list<CardofPatien*>&);
void AddNewPatien(list<CardofPatien*>&);
void GetPatienfromFile(list<CardofPatien*>&);
void ShowList(list<CardofPatien*>&);
void AddPatientoFile(list<CardofPatien*>&);
void AddPatientoPriem(list<Schedule*>&, string, int, int);
/////////////////Расписание//////////////////
void ShowList(list<Schedule*>&);
void Save_Schedule_to_file(std::list<Schedule*>&);
void Get_Schedule_from_file(std::list<Schedule*>&);
void ShowDate(list<Schedule*>&,int);
/////////////////Доктор//////////////////
void AddNewDoctor(list<Doctor*>&);
void AddDoctortoFile(list<Doctor*>&);
void ShowList(list<Doctor*>& );
void GetDoctorfromFile(list<Doctor*>&);
/////////////////Доступ//////////////////
bool EntertoPatienAccount(list<CardofPatien*>&,int&);
bool CheckListofDoctors(list<Doctor*>&,int);