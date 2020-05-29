#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include "CardofPatien.h"
using namespace std;
//Структура для хранения времени приёма и пациента

class Doctor
{
private:
	int id;
	string DName;// Имя враяа
	string DSurname;//Фамилия врача
	string DOtchestvo;// Отчество врача
	string Speciality;
	int Cab;// Рабочий кабинет врача
public:
	///////////Конструкторы класса////////////////
	Doctor();
	/////////////////Гетеры//////////////////
	int Getid();
	string GetDName();
	string GetDSurname(); 
	string GetDOtchestvo();
	string GetSpeciality();
	int GetCab(); 
	///////////////Сетеры///////////////////
	void Setid(int id);
	void SetName(string ); 
	void SetSurname(string);
	void SetOtchestvo(string); 
	void SetSpeciality(string);
	void SetCab(int);
};