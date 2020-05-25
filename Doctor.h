#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include "CardofPatien.h"


using namespace std;

class Data
{
public:
	string date;
	vector<map<unsigned, CardofPatien*>> time;

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
		unsigned k = 0;
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++)
		{

			for (int i = 0; i < (*iter)->time.size(); i++)
			{
				(*iter)->time[i].begin = k;
				(*iter)->time[i].end = nullptr;
			}
		}
	}
	void TempShow() {
		for (auto iter = scadual.begin(); iter != scadual.end(); iter++)
		{
			for (int i = 0; i < (*iter)->time.size; i++)
			{
				cout << (*iter)->time[i].begin()<<" ";
			}
			cout << endl;
		}
	}

};

