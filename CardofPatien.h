#pragma once
#include <iostream>
#include <string>
using namespace std;

class CardofPatien
{
public:
	
	void SetName(string name) { Name = name; }
	void SetSurname(string surname) { Surname = surname; }
	void SetOtchestvo(string otchestvo) { Otchestvo = otchestvo; }
	void SetBDay(string bday) { BDay = bday; }
	void SetHomeCountry(string country) { HomeCountry = country; }
	void SetHomeCity(string city) { HomeCity = city; }
	void SetAddress(string address) { Address = address; }
	void SetIPN(int ipn) { IPN = ipn; }
	void SetSex(char sex) { Sex = sex; }
	void SetWhoGive(int given) { WhoGive = given; }
	void SetDateOfIssuance(string inssuance) { DateOfIssuance = inssuance; }
	void SetSerialNumber(int number) { SerialNumber = number; }
	void SetMobileNumber(int number) { MobileNumber = number; }
	void SetEmail(string email) { Email = email; }
	
	
	////////////////////////////////////////////////////////////////
	string GetName() { return Name; }
	string GetSurname() { return Surname; }
	string GetOtchestvo() { return Otchestvo; }
	string GetBDay() { return BDay; }
	string GetHomeCountry() { return HomeCountry; }
	string GetHomeCity() { return HomeCity; }
	string GetAddress() { return Address; }
	int GetIPN() {return  IPN; }
	char GetSex() { return Sex; }
	int GetWhoGive() { return WhoGive; }
	string GetDateOfIssuance() { return DateOfIssuance; }
	int GetSerialNumber() { return SerialNumber; }
	int GetMobileNumber() { return MobileNumber; }
	string GetEmail() { return Email; }
	
	///////////////////////////////////////////////////////////////
	CardofPatien(string& name, string& surname, string& otchestvo, string& bday, string& country, string& city, string& address, int ipn, char sex,
		int given, string& inssuance, int serianumber, int mobnumber, string& email) {
		Name = name;
		Surname = surname;
		Otchestvo = otchestvo;
		BDay = bday;
		HomeCountry = country;
		HomeCity = city;
		Address = address;
		IPN = ipn;
		Sex = sex;
		WhoGive = given;
		DateOfIssuance = inssuance;
		SerialNumber = serianumber;
		MobileNumber = mobnumber;
		Email = email;
		
	}
private:

	string Name;
	string Surname;
	string Otchestvo;
	string BDay;
	string HomeCountry;
	string HomeCity;
	string Address;
	int IPN;
	char Sex;
	int WhoGive;
	string DateOfIssuance;
	int SerialNumber;
	int MobileNumber;
	string Email;
};

