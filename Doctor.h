#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include "CardofPatien.h"
using namespace std;
//��������� ��� �������� ������� ����� � ��������

class Doctor
{
private:
	int id;
	string DName;// ��� �����
	string DSurname;//������� �����
	string DOtchestvo;// �������� �����
	string Speciality;
	int Cab;// ������� ������� �����
public:
	///////////������������ ������////////////////
	Doctor();
	/////////////////������//////////////////
	int GetId();
	string GetDName();
	string GetDSurname(); 
	string GetDOtchestvo();
	string GetSpeciality();
	int GetCab(); 
	///////////////������///////////////////
	void SetId(int id);
	void SetName(string ); 
	void SetSurname(string);
	void SetOtchestvo(string); 
	void SetSpeciality(string);
	void SetCab(int);
};