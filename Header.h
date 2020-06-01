#pragma once
#include "CardofPatien.h"
#include "Doctor.h"
#include "Schedule.h"

/////////////////�������//////////////////
void ShowList(list<CardofPatien*>&);
void AddNewPatien(list<CardofPatien*>&);
void GetPatienfromFile(list<CardofPatien*>&);
void ShowList(list<CardofPatien*>&);
void AddPatientoFile(list<CardofPatien*>&);
void AddPatientoPriem(list<Schedule*>&, string, int, int);
void DeletethePatien(list<CardofPatien*>&);
/////////////////����������//////////////////
void ShowList(list<Schedule*>&);
void Save_Schedule_to_file(list<Schedule*>&);
void Get_Schedule_from_file(list<Schedule*>&);
void ShowDate(list<Schedule*>&,int);
void AddnewSchedule(list<Schedule*>&,list<Doctor*>&,int);
void DeletetheSchedule(list<Schedule*>,list<Doctor*>,int);
/////////////////������//////////////////
void AddNewDoctor(list<Doctor*>&);
void AddDoctortoFile(list<Doctor*>&);
void ShowList(list<Doctor*>& );
void GetDoctorfromFile(list<Doctor*>&);
void DeletetheDoctor(list<Doctor*>&);
/////////////////������//////////////////
bool EntertoPatienAccount(list<CardofPatien*>&,int&);
bool CheckListofDoctors(list<Doctor*>&,int);