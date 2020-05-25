#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "CardofPatien.h"


using namespace std;

struct priem
{
	int timeid;
	CardofPatien* person;

};
class Data
{
public:
	string date;
	vector<priem> time;
};
class Doctor
{
private:
	string DName;
	string DOurname;
	string DOtchestvo;
	unsigned int Cab;
	// добавить список(дата+массив) массивов пар(время+указатель на пациента)
	list<Data*> scadual;
public:
	void SetnullTime() {
		int k = 0;
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++)
		{

			for (int i = 0; i < (*iter)->time.size(); i++)
			{
				(*iter)->time[i].timeid = k;
				(*iter)->time[i].person = nullptr;
			}
		}
	}
	void TempShow() {
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++)
		{
			for (int i = 0; i < (*iter)->time.size(); i++)
			{
				cout << (*iter)->time[i].timeid <<" ";
			}
			cout << endl;
		}
	}
	void AddDay() {
		Data* data = new Data();
		scadual.push_back(data);
	}
};

