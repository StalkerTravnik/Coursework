#include "Doctor.h"
///////////Конструктор класса////////////////
Doctor::Doctor() {};
/////////////////Гетеры//////////////////
int Doctor::Getid() { return id; }
string Doctor::GetDName() { return DName; }
string Doctor::GetDSurname() { return DSurname; }
string Doctor::GetDOtchestvo() { return DOtchestvo; }
string Doctor::GetSpeciality() { return Speciality; }
int Doctor::GetCab() { return Cab; }
///////////////Сетеры///////////////////
void Doctor::Setid(int id) { this->id = id; }
void Doctor::SetName(string name) { DName = name; }
void Doctor::SetSurname(string surname) { DSurname = surname; }
void Doctor::SetOtchestvo(string otchestvo) { DOtchestvo = otchestvo; }
void Doctor::SetSpeciality(string speciality) { Speciality = speciality; }
void Doctor::SetCab(int cab) { Cab = cab; }