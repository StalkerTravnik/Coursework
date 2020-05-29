#pragma once
#include "CardofPatien.h"
#include "Doctor.h"
#include "Schedule.h"

//������� ���������� ������ �������� � ������ ��������
void AddNewPatien(list<CardofPatien*>& ListofPatien);
//������� ���������� ������ ����� � ������ ������
void AddNewDoctor(list<Doctor*>& listofdoctors);
//������� ���������� ������ ������ � ����
void AddDoctortoFile(list<Doctor*>& listofdoctors);
//������� ������ ������ ���������
void ShowList(list<CardofPatien*>& ListofPatien);
//������� ������ ������ ������
void ShowList(list<Doctor*>& listofdoctors);
void ShowList(list<Schedule*>&);
void ShowList(list<CardofPatien*>& ListofPatien);
//������ ���������� ������ ��������� � ����
void AddPatientoFile(list<CardofPatien*> &Patien);
//������ ���������� ������ ��������� �� ����
void GetPatienfromFile(list<CardofPatien*>& Patien);
//������ ���������� ������ ������ �� ����
void GetDoctorfromFile(list<Doctor*>& listofdoctors);
void Save_Schedule_to_file(std::list<Schedule*>&);
void Get_Schedule_from_file(std::list<Schedule*>&);
void AddPatientoPriem(list<Schedule*>&,string,int,int);