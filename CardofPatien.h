#pragma once
#include <iostream>
#include <string>
using namespace std;

class CardofPatien
{
public:
	///////////////������///////////////////
	void SetId(int);
	void SetName(string); 
	void SetSurname(string);
	void SetOtchestvo(string);
	void SetBDay(string);
	void SetMobileNumber(string);
	void SetEmail(string);
	/////////////////������//////////////////
	int GetId();
	string GetName();
	string GetSurname();
	string GetOtchestvo();
	string GetBDay();
	string GetMobileNumber();
	string GetEmail();
	///////////����������� ������////////////////
	CardofPatien(); 
private:
	int id;
	string Name;
	string Surname;
	string Otchestvo;
	string BDay;
	string MobileNumber;
	string Email;
};

