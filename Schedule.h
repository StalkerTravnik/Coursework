#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
class Schedule
{
private:
	int id;
	int Did;
	std::string Date;
	std::vector<std::pair<std::string, int>>priem;
public:
	///////////////Сетеры///////////////////
	void SetId(int);
	void SetDId(int);
	void SetDate(std::string);
	void SetPriem(std::pair<std::string, int>);
	void SetPersonToPriem(std::string, int);
	/////////////////Гетеры//////////////////
	int GetId();
	int GetDId();
	std::string GetDate();
	std::pair<std::string, int> GetPriem(int i);
};