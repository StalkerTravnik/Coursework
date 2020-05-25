#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include "Header.h"
#include "CardofPatien.h"
#include "CardofPatien.cpp"
#include "Doctor.cpp"
#include "Doctor.h"
#include <clocale>
#include <map>
#define Debug
using namespace std;
int GetPosition() {
	while (true)
	{
		unsigned int position;
		cin >> position;


		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Введенное значение некоректною. Попробуйте ещё раз.\n";
		}
		else
		{
			cin.ignore(20000000, '\n');
			return  position;
		}
	}
}
int GetVelue() {
	while (true)
	{
		int value;
		cin >> value;


		if (cin.fail() || value < 1)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Введенное значение некоректною. Попробуйте ещё раз.\n";
		}
		else
		{
			cin.ignore(32767, '\n');
			return value;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ukrainian");
	list<CardofPatien*> listofpatien;
	list<Doctor*> listofdoctor;
	unsigned int position;
	Doctor D;
	string date;
	/*do
	{
		cout << "Введите номер нужной операции." << "\n\n";
		cout << "1. Добавить элемент" << endl;
		cout << "2. Вывести список" << endl;
		cout << "0. Выйти" << endl;
		cout << "\nНомер операции > "; position = GetPosition();
		switch (position)
		{
		case 1: AddPatien(listofpatien); break;
		case 2: ShowList(listofpatien); break;
		case 0: break;
		default: cout << "Выбранной операции не существует. Попробуйте ещё раз." << "\n\n"; break;
		}

	} while (position != 0);
	*/
	AddPatien(listofpatien);
	
	for (int i = 0; i < 3; i++)
	{
		cin >> date;
		D.AddDay(date);
	}
	D.SetnullTime();
	cin >> date;
	
	D.Addperson(date,5,listofpatien.back());
	D.TempShow();
	return 0;
}
void AddPatien(list<CardofPatien*> &ListofPatien) {
	string Name, Surname, Otchestvo, BDay,Email;
	int SerialNumber, MobileNumber;
	
#ifdef Debug
	Name="Alan";  
	// cout << "Введiть ваше прiзвище: "; cin >> Surname;  cout << endl;
	Surname = "Abrakadabrovich";
	Otchestvo="Evgenevich"; 
	BDay="13.09.2001";  
	MobileNumber=5454;  
	Email="gg";
	
#else
	cout << "Введiть ваше iм'я: "; cin >> Name;  cout << endl;
	cout << "Введiть ваше прiзвище: "; cin >> Surname;  cout << endl;
	cout << "Введiть ваше iм'я по батьковi: "; cin >> Otchestvo;  cout << endl;
	cout << "Введiть дату вашого народження: "; cin >> BDay;  cout << endl;
	cout << "Введiть ваш мобiльний номер: (+38)"; cin >> MobileNumber;  cout << endl;
	cout << "Введiть вашу електронну пошту: "; cin >> Email;  cout << endl;
	cout << "Придумайте пароль: "; cin >> Pasword;  cout << endl;
#endif 
    CardofPatien* node = new CardofPatien(Name, Surname, Otchestvo, BDay,MobileNumber, Email);
	ListofPatien.push_back(node);
}
void ShowList(list<CardofPatien*>& ListofPatien) {
	for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++)
	{
		cout<<(*iter)->GetName()<<" "<< (*iter)->GetSurname()<<" "<<(*iter)->GetOtchestvo() << endl;
		cout << (*iter)->GetBDay() << endl;
		cout << (*iter)->GetEmail() << endl;
	}
}
void AddPatientoFile(list<CardofPatien*> & ListofPatien) {
	ofstream fout;
	string path = "myFile.txt";
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error\n";
	}
	else
	{
		for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++)
		{
			fout.write((char*)&(*iter),sizeof(CardofPatien));
		}
	}
	fout.close();
}
/*void GetPatienfromFile(list<CardofPatien*>& ListofPatien) {
	string path = "myFile.txt";
	ifstream fin;
	fin.open(path);
	if(!fin.is_open())
	{
		cout << "Error\n";
	}
	else {
		for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++)
		{
			fin.read((char*) & (*iter), sizeof(CardofPatien));
		}
	}
	fin.close();
}*/