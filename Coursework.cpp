﻿#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <clocale>
#include <map>
#include <windows.h>
#include "Header.h"
#include "CardofPatien.h"
#include "Doctor.h"
#include "Schedule.h"
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	list<CardofPatien*> listofpatien;
	list<Doctor*> listofdoctor;
	list<Schedule*> SCHEDULE;
	unsigned int position;
	string date;
	int uid=13, did=3;
	Get_Schedule_from_file(SCHEDULE);
	AddPatientoPriem(SCHEDULE,"16.12",did,uid);
	return 0;
}
/////////////////Пациент//////////////////
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
	string path = "Patiens.txt";
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error\n";
	}
	else
	{
		for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++)
		{
			fout << (*iter)->GetId()<<" "<<(*iter)->GetName()<<" "<<(*iter)->GetSurname()<<" "<< (*iter)->GetOtchestvo()<<" "<< (*iter)->GetBDay()<<" "<< (*iter)->GetMobileNumber()<<" "<< (*iter)->GetEmail()<<"\n";
		}
	}
	fout.close();
}
void GetPatienfromFile(list<CardofPatien*>& ListofPatien) {
	string path = "Patiens.txt";
	ifstream fin;
	fin.open(path);
	if(!fin.is_open())
	{
		cout << "Error\n";
	}
	else {
			string temp;
			int tmp;
			while (!fin.eof())
			{
				CardofPatien* tempclass = new CardofPatien;
				fin >> tmp; tempclass->SetId(tmp);
				fin >> temp; tempclass->SetName(temp); 
				fin >> temp; tempclass->SetSurname(temp); 
				fin >> temp; tempclass->SetOtchestvo(temp);
				fin >> temp; tempclass->SetBDay(temp);
				fin >> temp; tempclass->SetMobileNumber(temp);
				fin >> temp; tempclass->SetEmail(temp);
				if (tmp != -1&&temp!="") { ListofPatien.push_back(tempclass); }
				tmp = -1;
				temp = "";
			}
	}
	fin.close();
}
void AddNewPatien(list<CardofPatien*>& ListofPatien) {
	string temp;

	CardofPatien* patien = new CardofPatien;
#ifdef Debug
	patien->SetName("Артём");
	patien->SetSurname("Мостовой");
	patien->SetOtchestvo("Генадиевич");
	patien->SetBDay("18.11.2002");
	patien->SetMobileNumber("+380664674563");
	patien->SetEmail("Nikolascoc@gimail.com");
#else
	cout << "Введiть ваше iм'я: "; cin >> temp;  cout << endl;
	patien->SetName(temp);
	cout << "Введiть ваше прiзвище: "; cin >> temp;  cout << endl;
	patien->SetSurname(temp);
	cout << "Введiть ваше iм'я по батьковi: "; cin >> temp;  cout << endl;
	patien->SetOtchestvo(temp);
	cout << "Введiть дату вашого народження: "; cin >> temp;  cout << endl;
	patien->SetBDay(temp);
	cout << "Введiть ваш мобiльний номер: (+38)"; cin >> temp;  cout << endl;
	patien->SetMobileNumber(temp);
	cout << "Введiть вашу електронну пошту: "; cin >> temp;  cout << endl;
	patien->SetEmail(temp);

#endif 
	if (ListofPatien.size() == 0) 
	{
		patien->SetId(1);
	}
	else
	{
		patien->SetId(ListofPatien.back()->GetId());
	}
	ListofPatien.push_back(patien);
}
void AddPatientoPriem(list<Schedule*>&schedule,string date,int did,int uid) 
{
	string time;
	for (auto iter = schedule.begin(); iter != schedule.end(); iter++) 
	{
		if (((*iter)->GetDate()==date)&&((*iter)->GetDId()==did)) 
		{
			cout<<"Свободное время приёма:\n";
			for (int i = 0; i < 30; i++)
			{
				if ((*iter)->GetPriem(i).second==0)
				{
					cout << (*iter)->GetPriem(i).first << "\n";
				}
				
			}
			cout << "Выберите время приёма: ";
			cin >> time;
			(*iter)->SetPersonToPriem(time, uid);
		}
	}
	Save_Schedule_to_file(schedule);
}
/////////////////Расписание//////////////////
void Save_Schedule_to_file(list<Schedule*>&schedule) {
	ofstream fout;
	fout.open("Schedule.txt");
	if (!fout.is_open())
	{
		cout << "Error\n";
	}
	else
	{
		pair<string, int> temp;
		for (auto iter = schedule.begin(); iter != schedule.end(); iter++) {
			fout <<(*iter)->GetId()  << " " << (*iter)->GetDId() << " " << (*iter)->GetDate() << " ";
			for (int i = 0; i < 30; i++)
			{
				temp = (*iter)->GetPriem(i);
				fout << temp.first << " " << temp.second << " ";
			}
			fout << "\n";
		}
	}
	fout.close();
}
void Get_Schedule_from_file(list<Schedule*>&schedule) {

	ifstream fin;
	fin.open("Schedule.txt");
	if (!fin.is_open())
	{
		cout << "Error\n";
	}
	else {
		int id, Did,second;
		string Date,first;
		pair<string, int> temp;
		while (!fin.eof())
		{
			Schedule* sched = new Schedule;
			fin >> id >> Did >> Date;
			sched->SetId(id); sched->SetDId(Did); sched->SetDate(Date);
			for (int i = 0; i < 30; i++)
			{
				fin >> first >> second;
				temp.first = first;
				temp.second = second;
				sched->SetPriem(temp);
			}
			if (id!=-1)
			{
				schedule.push_back(sched);
			}
			id = -1;
		}
	}
	fin.close();
};
void ShowList(list<Schedule*>& SCHEDULE) {
	for (auto iter = SCHEDULE.begin(); iter != SCHEDULE.end(); iter++) {
		cout << (*iter)->GetDate() << " " << (*iter)->GetId() << " " << (*iter)->GetDId() << endl;
		for (int i = 0; i < 30; i++)
		{
			cout << (*iter)->GetPriem(i).first << " " << (*iter)->GetPriem(i).second << "\n";
		}
		cout << endl;
	}

}
/////////////////Доктор//////////////////
void AddNewDoctor(list<Doctor*> & ListofDoctors) {
	int tmp;
	string temp;
	Doctor* doc = new Doctor;
#ifdef  Debug

	doc->SetName("Артур");
	doc->SetSurname("Коревников");
	doc->SetOtchestvo("Александрович");
	doc->SetSpeciality("Проктолог");
	doc->SetCab(1488);
#else
	cout << "Введите имя врача: "; cin >> temp;  cout << endl;
	doc->SetName(temp);
	cout << "Введите фамилию врача: "; cin >> temp;  cout << endl;
	doc->SetSurname(temp);
	cout << "Введите отчество врача: "; cin >> temp;  cout << endl;
	doc->SetOtchestvo(temp);
	cout << "Введите специальность врача: "; cin >> temp;  cout << endl;
	doc->SetSpeciality(temp);
	cout << "Введите рабочий кабинет врача: "; cin >> tmp;  cout << endl;
	doc->SetCab(tmp);
#endif //  Debug
	if (ListofDoctors.size() == 0) {
		doc->Setid(1);
	}
	else
	{
		doc->Setid(ListofDoctors.back()->Getid()+1);
	}
	ListofDoctors.push_back(doc);
	AddDoctortoFile(ListofDoctors);
}
void AddDoctortoFile(list<Doctor*>& ListofDoctors) {
	ofstream fout;
	string path = "Doctors.txt";
	fout.open(path);
	if (!fout.is_open())
	{
		cout << "Error\n";
	}
	else
	{
		for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++)
		{
			fout << (*iter)->Getid() << " ";
			fout << (*iter)->GetDName() << " ";
			fout << (*iter)->GetDSurname() << " "; 
			fout << (*iter)->GetDOtchestvo() << " ";
			fout << (*iter)->GetSpeciality() << " ";
			fout << (*iter)->GetCab() << "\n";
		}
	}
	fout.close();
}
void GetDoctorfromFile(list<Doctor*>& ListofDoctors) {
	string path = "Doctors.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error\n";
	}
	else {
		string temp;
		int tmp;
		while (!fin.eof())
		{
			Doctor* doc = new Doctor;
			fin >> tmp; doc->Setid(tmp);
			fin >> temp; doc->SetName(temp); 
			fin >> temp; doc->SetSurname(temp); 
			fin >> temp; doc->SetOtchestvo(temp);
			fin >> temp; doc->SetSpeciality(temp);
			fin >> tmp; doc->SetCab(tmp);
			if (tmp!=-1)
			{
				ListofDoctors.push_back(doc);
			}
			tmp = -1;
		}
	}
	fin.close();
}
void ShowList(list<Doctor*>& ListofDoctors) {

	for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++) {
		cout << (*iter)->Getid() << "\n" << (*iter)->GetDName() << " ";
		cout << (*iter)->GetDSurname() << " " << (*iter)->GetDOtchestvo() << "\n";
		cout << (*iter)->GetSpeciality() << " " << (*iter)->GetCab() << "\n";
		cout << endl;
	}
}