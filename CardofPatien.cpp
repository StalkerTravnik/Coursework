#include "CardofPatien.h"
///////////Конструктор класса////////////////
CardofPatien::CardofPatien() {}
///////////////Сетеры///////////////////
void CardofPatien::SetId(int id) { this->id = id; }
void CardofPatien::SetName(string name) { Name = name; }
void CardofPatien::SetSurname(string surname) { Surname = surname; }
void CardofPatien::SetOtchestvo(string otchestvo) { Otchestvo = otchestvo; }
void CardofPatien::SetBDay(string bday) { BDay = bday; }
void CardofPatien::SetMobileNumber(string number) { MobileNumber = number; }
void CardofPatien::SetEmail(string email) { Email = email; }
/////////////////Гетеры//////////////////
int CardofPatien::GetId() { return id; }
string CardofPatien::GetName() { return Name; }
string CardofPatien::GetSurname() { return Surname; }
string CardofPatien::GetOtchestvo() { return Otchestvo; }
string CardofPatien::GetBDay() { return BDay; }
string CardofPatien::GetMobileNumber() { return MobileNumber; }
string CardofPatien::GetEmail() { return Email; }