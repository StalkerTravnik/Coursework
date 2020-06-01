#include <iostream>
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
//#define Debug
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
			cin.ignore(200000, '\n');
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
	unsigned int position,position1,position2,position3;
	string date;
	int uid=0,did=0;
	GetPatienfromFile(listofpatien);
	Get_Schedule_from_file(SCHEDULE);
	GetDoctorfromFile(listofdoctor);
	do {
		cout << "Добро пожалвать\n";
		cout << "1) Зайти как пациент;\n";
		cout << "2) Зайти как администратор;\n";
		cout << "0) Завершить сеанс.\n";
		cout << "Выберите необхадимое действие: \n";
		position = GetPosition();
		switch (position)
		{
		case 1:
			do {
				cout << "Выберите необхадимое действие:\n";
				cout << "1) Зарегистрировать нового пациента;\n";
				cout << "2) Войти в свой аккаунт;\n";
				cout << "0) Назад.\n";
				position1 = GetPosition();
				switch (position1)
				{
				case 1:
					AddNewPatien(listofpatien);
					break;
				case 2:
					if (EntertoPatienAccount(listofpatien, uid))
					{
						do {
							cout << "Авторизация удачна.\n";
							cout << "1) Записаться на приём;\n";
							cout << "2) Изменить сою учётную запись;\n";
							cout << "0) Назад.\n";
							cout << "Выберите необхадимое действие: \n";
							position2 = GetPosition();
							switch (position2)
							{
							case 1:

								cout << "Выберите врача для записи:\n";
								ShowList(listofdoctor);
								cout << "\nВведите id врача: "; cin >> did;
								if (CheckListofDoctors(listofdoctor, did))
								{
									cout << "Даты приёма:\n";
									ShowDate(SCHEDULE, did);
									cout << "Выберите дату приёма: "; cin >> date;
									AddPatientoPriem(SCHEDULE, date, did, uid);
								}break;
							case 2:
								do {
									cout << "Доступные поля для изменения:\n";
									cout << "1) Изменить имя;\n";
									cout << "2) Изменить фамилию;\n";
									cout << "3) Изменить отчество;\n";
									cout << "4) Изменить дату рождения;\n";
									cout << "5) Изменить мобильный номер;\n";
									cout << "6) Изменить Email;\n";
									cout << "0) Назад.\n";
									cout << "Выберите необхадимое действие:\n";
									position3 = GetPosition();
									string temp;
									switch (position3)
									{
									case 1:
										cout << "Введите новое имя: ";
										cin >> temp;
										for (auto iter = listofpatien.begin(); iter != listofpatien.end(); iter++) {
											if ((*iter)->GetId() == uid)
											{
												(*iter)->SetName(temp);
												break;
											}
										}
										break;
									case 2:
										cout << "Введите новую фамилию: ";
										cin >> temp;
										for (auto iter = listofpatien.begin(); iter != listofpatien.end(); iter++) {
											if ((*iter)->GetId() == uid)
											{
												(*iter)->SetSurname(temp);
												break;
											}
										}
										break;
									case 3:
										cout << "Введите новое отчество: ";
										cin >> temp;
										for (auto iter = listofpatien.begin(); iter != listofpatien.end(); iter++) {
											if ((*iter)->GetId() == uid)
											{
												(*iter)->SetOtchestvo(temp);
												break;
											}
										}
										break;
									case 4:
										cout << "Введите новую дату рождения: ";
										cin >> temp;
										for (auto iter = listofpatien.begin(); iter != listofpatien.end(); iter++) {
											if ((*iter)->GetId() == uid)
											{
												(*iter)->SetBDay(temp);
												break;
											}
										}
										break;
									case 5:
										cout << "Введите новый мобильный номер: ";
										cin >> temp;
										for (auto iter = listofpatien.begin(); iter != listofpatien.end(); iter++) {
											if ((*iter)->GetId() == uid)
											{
												(*iter)->SetMobileNumber(temp);
												break;
											}
										}
										break;
									case 6:
										cout << "Введите новый Email: ";
										cin >> temp;
										for (auto iter = listofpatien.begin(); iter != listofpatien.end(); iter++) {
											if ((*iter)->GetId() == uid)
											{
												(*iter)->SetEmail(temp);
												break;
											}
										}
										break;
									case 0: break;
									default:
										cout << "Выбранной операции не существует. Попробуйте ещё раз.\n\n"; break;
									}
									AddPatientoFile(listofpatien);
								} while (position3 != 0);break;
							case 0:break;
							default:
								cout << "Выбранной операции не существует. Попробуйте ещё раз.\n\n"; break;
							}
						} while (position2 != 0);
					}
					break;
				case 0:break;
				default:
					cout << "Выбранной операции не существует. Попробуйте ещё раз.\n\n"; break;
				}
				break;
			} while (position1 != 0); break;
		case 2:
			do {
				cout << "1) Добавить нового пользователя;\n";
				cout << "2) Удалить пользователя;\n";
				cout << "3) Добавить нового врача;\n";
				cout << "4) Удалить врача;\n";
				cout << "5) Вывести список врачей;\n";
				cout << "6) Вывести список пациентов\n";
				cout << "7) Добавить расписание врачу\n";
				cout << "8) Удалить расписание врача\n";
				cout << "0) Назад.\n";
				cout << "Выберите необхадимое действие: \n";
				position1 = GetPosition();
				switch (position1)
				{
				case 1:
					AddNewPatien(listofpatien); break;
				case 2:
					DeletethePatien(listofpatien); break;
				case 3: 
					AddNewDoctor(listofdoctor); break;
				case 4:
					DeletetheDoctor(listofdoctor); break;
				case 5:
					ShowList(listofdoctor);break;
				case 6: ShowList(listofpatien); break;
				case 7: ShowList(listofdoctor);
					cout << "Введите id врача,которому хотите добавить расписание: "; did = GetVelue();
					AddnewSchedule(SCHEDULE, listofdoctor, did);
					break;
				case 8:
					ShowList(listofdoctor);
					cout << "Введите id врача,которому хотите удалить расписание: "; did = GetVelue();
					DeletetheSchedule(SCHEDULE, listofdoctor, did);
					break;
				case 0: break;
				default:
					cout << "Выбранной операции не существует. Попробуйте ещё раз.\n\n"; break;
				}
			} while (position1!=0); break;
		case 0:break;
		default:
			cout << "Выбранной операции не существует. Попробуйте ещё раз.\n\n"; break;
		}
	} while (position!=0);
	return 0;
}
/////////////////Пациент//////////////////
void ShowList(list<CardofPatien*>& ListofPatien) {
	for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++)
	{
		cout<<"Ф.И.О. пациента: "<< (*iter)->GetSurname() <<(*iter)->GetName()<<" "<<" "<<(*iter)->GetOtchestvo() << endl;
		cout<<"Дата рождения: "<< (*iter)->GetBDay() << endl;
		cout <<"Email адресс: "<< (*iter)->GetEmail() << endl;
		cout << "Телефон: "<< (*iter)->GetMobileNumber()<<endl;
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
		ListofPatien.push_back(patien);
	}
	else
	{
		for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++) {
			if ((*iter)->GetName() == patien->GetName() && (*iter)->GetSurname() == patien->GetSurname() && (*iter)->GetOtchestvo() == patien->GetOtchestvo()) 
			{
				cout << "Пользователь с такими данными уже существует.\n ";
				return;
			}
		}
		patien->SetId(ListofPatien.back()->GetId()+1);
		ListofPatien.push_back(patien);
	}
	AddPatientoFile(ListofPatien);
}
void AddPatientoPriem(list<Schedule*>&schedule,string date,int did,int uid) 
{
	string time;
	for (auto iter = schedule.begin(); iter != schedule.end(); iter++) 
	{
		if ((*iter)->GetDate()==date&&(*iter)->GetDId()==did) 
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
			for (auto iter1 = schedule.begin(); iter1 != schedule.end(); iter1++) {
				if ((*iter1)->GetDate()==date) {
					for (int i = 0; i < 30; i++)
					{
						if ((*iter1)->GetPriem(i).first == time&&(*iter1)->GetPriem(i).second==uid) {
							cout << "Извините, но на это время у вас уже есть сеанс.\n"; return;
						}
					}
				}
			}
			(*iter)->SetPersonToPriem(time, uid);
		}
	}
	Save_Schedule_to_file(schedule);
}
void DeletethePatien(list<CardofPatien*>&ListofPatien) {
	string name, surname, otchestvo,date;
	cout << "\nВедите имя пациента: "; cin >> name;
	cout << "\nВведите фамилию пациента: "; cin >> surname;
	cout << "\nВведите отчество пациенат: "; cin >> otchestvo;
	cout << "\nВедите дату раоднения: "; cin >>date;
	for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++) {
		if ((*iter)->GetName()==name&&(*iter)->GetSurname()==surname&&(*iter)->GetOtchestvo()==otchestvo&&(*iter)->GetBDay()==date)
		{
			ListofPatien.erase(iter);
			cout << "\nПациент удалён.\n";
			AddPatientoFile(ListofPatien);
			return;
		}
	}
	cout << "\nПациента с такими данными не сущесвует.\n";
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
void ShowDate(list<Schedule*>& SCHEDULE,int did) {
	for (auto iter = SCHEDULE.begin(); iter != SCHEDULE.end(); iter++) {
		if ((*iter)->GetDId()==did)
		{
			cout << (*iter)->GetDate() << endl;
		}
	}
	cout << endl;
}
void AddnewSchedule(list<Schedule*>&SCHEDULE,list<Doctor*>&ListofDoctors,int did) {
	for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++) {
		if ((*iter)->GetId()==did) {
			Schedule* sch = new Schedule;
			string temp;
			pair<string, int> pr;
			cout << "\nВведите дату,на которую хотите составить расписание: "; cin >> temp;
			sch->SetDate(temp);
				ifstream fin("KeyTime.txt");
				if (fin.is_open())
				{
					while (!fin.eof())
					{
						fin >> pr.first >> pr.second;
						sch->SetPriem(pr);
					}
					if (SCHEDULE.size()==0) {
						sch->SetId(1);
						sch->SetDId(did);
						SCHEDULE.push_back(sch);
						Save_Schedule_to_file(SCHEDULE);
						cout << "Расписание добавлено.\n";	fin.close(); return;
					}
					else {
					
						sch->SetId(SCHEDULE.back()->GetId()+1);
						sch->SetDId(did);
						SCHEDULE.push_back(sch);
						Save_Schedule_to_file(SCHEDULE);
						cout << "Расписание добавлено.\n";	fin.close(); return;
					}
				}
				else
				{
					cout << "Ошибка! Проверьте наличие файла KeyTime.txt.\n";	fin.close(); return;
				}
		}
		
	}
	cout << "Врача с таким id не существует.\n";
}
void DeletetheSchedule(list<Schedule*>SCHEDULE,list<Doctor*>ListofDoctors,int did) {
	for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++) {
		if ((*iter)->GetId()==did)
		{
			string date;
			cout << "Введите дату,котрую хотите удалить: "; cin >> date;
			for (auto iter = SCHEDULE.begin(); iter != SCHEDULE.end(); iter++) {
				if ((*iter)->GetDate()==date&&(*iter)->GetDId()==did)
				{
					SCHEDULE.erase(iter);
					Save_Schedule_to_file(SCHEDULE);
					cout << "Расписание удалено.\n";
					return;
				}
			}
		}
	}
	cout << "Врача с таким id н существует.\n"; 

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
	if (ListofDoctors.size() == 0)
	{
		doc->SetId(1);
		ListofDoctors.push_back(doc);
	}
	else
	{
		for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++) {
			if ((*iter)->GetDName() == doc->GetDName() && (*iter)->GetDSurname() == doc->GetDSurname() && (*iter)->GetDOtchestvo() == doc->GetDOtchestvo())
			{
				cout << "Врач с такими данными уже существует.\n ";
				return;
			}
		}
		doc->SetId(ListofDoctors.back()->GetId()+1);
		ListofDoctors.push_back(doc);
	}
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
			fout << (*iter)->GetId() << " ";
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
			fin >> tmp; doc->SetId(tmp);
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
		cout << "ID врача: "<<(*iter)->GetId() << "\n";
		cout << "Ф.И.О. врача:" << (*iter)->GetDSurname() << " "<<(*iter)->GetDName() << " " << (*iter)->GetDOtchestvo() << "\n";
		cout << "Специальность врача: " << (*iter)->GetSpeciality() << "\n"; 
		cout<<"Рабочий кабинет: "<<(*iter)->GetCab() << "\n";
	}
}
void DeletetheDoctor(list<Doctor*>&ListofDoctors) {
	string name, surname, otchestvo, speciality;
	cout << "\nВедите имя врача: "; cin >> name;
	cout << "\nВведите фамилию врача: "; cin >> surname;
	cout << "\nВведите отчество врча: "; cin >> otchestvo;
	cout << "\nВедите дату специальность: "; cin >> speciality;
	for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++) {
		if ((*iter)->GetDName() == name && (*iter)->GetDSurname() == surname && (*iter)->GetDOtchestvo() == otchestvo && (*iter)->GetSpeciality()==speciality)
		{
			ListofDoctors.erase(iter);
			cout << "\nВрач удалён.\n";
			AddDoctortoFile(ListofDoctors);
			return;
		}
	}
	cout << "\nВрача с такими данными не сущесвует.\n";
}
/////////////////Доступ//////////////////
bool EntertoPatienAccount(list<CardofPatien*>& ListofPatien,int &uid) {
	string name, surname, otchestvo;
	cout << "Введите имя пациента: "; cin >> name;
	cout << "Введите фамилию пациента: "; cin >> surname;
	cout << "Введите отчество пациента: "; cin >> otchestvo;
	for (auto iter = ListofPatien.begin(); iter != ListofPatien.end(); iter++) {
	
		if ((*iter)->GetName()==name&&(*iter)->GetSurname()==surname&&(*iter)->GetOtchestvo()==otchestvo)
		{
			uid = (*iter)->GetId();
			return true;
		}
	}
	return false;
}
bool CheckListofDoctors(list<Doctor*>&ListofDoctors,int did) {
	for (auto iter = ListofDoctors.begin(); iter != ListofDoctors.end(); iter++) {
		if ((*iter)->GetId()==did)
		{
			return true;
		}
	}
	return false;
}