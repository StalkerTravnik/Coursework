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
struct priem
{
	int timeid;
	CardofPatien* person;
	priem() {}
	priem(int timeid) {
	
		this->timeid = timeid;
		this->person = nullptr;
	}
};
//Структура для хранения даты
struct Data
{
    string date;
	vector<priem> time;
	
};
class Doctor
{
private:
	string DName;// Имя враяа
	string DOurname;//Фамилия врача
	string DOtchestvo;// Отчество врача
	unsigned int Cab;// Рабочий кабинет врача
	list<Data*> scadual;// Расписание
public:
	//Добавить пустое рассписание на день
	void SetnullTime() {
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++)
		{
			for (int i = 0; i < 30; i++)
			{
				priem temp(i);
				(*iter)->time.push_back(temp);
			}
		}
	}
	//Показать рассписание
	void TempShow() {
		map<int,string> temp;
		Addkey(temp);
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++)
		{
			cout <<"Start\n"<<(*iter)->date<<":\n";
			for (int i = 0; i < (*iter)->time.size(); i++)
			{      
				if ((*iter)->time[i].person!=nullptr)
				{
					cout << temp[(*iter)->time[i].timeid] << " " <<(*iter)->time[i].person->GetName()<<endl;
				}
			}
			cout <<"End"<<endl;
		}
	}
	//
	void AddDay(string date) {
		Data* data = new Data();
		data->date = date;
		scadual.push_back(data);
	}
	//Добавить словарь для времени приёма
	void Addkey(map<int, string> &keytime) {
		ifstream fin;
		fin.open("KeyTime.txt");
		if (!fin.is_open())
		{
			cout << "Error\n";
		}
		else {
			while (!fin.eof())
			{
				int temp;
				string tmpstr;
				fin >> temp>>tmpstr;
				keytime.emplace(temp,tmpstr);
			}
		}
		fin.close();
	}
	void Addperson(string DATE,int timeid,CardofPatien* person) {
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++) {
			if ((*iter)->date==DATE)
			{
				for (int i = 0; i < 30; i++)
				{
					if ((*iter)->time[i].timeid==timeid)
					{
						(*iter)->time[i].person = person;
						return;
					}
				}
			}
			
			
		}
		cout << "Приносим свои извинения.Рассписание на эту дату ещё не составлено.\n";
	}
	
};