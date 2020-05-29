#include "Schedule.h"
///////////////Сетеры///////////////////
void Schedule::SetId(int id) { this->id = id; }
void Schedule::SetDId(int Did) { this->Did = Did; }
void Schedule::SetDate(std::string Date) { this->Date = Date; }
void Schedule::SetPriem(std::pair<std::string, int> pair) { priem.push_back(pair); }
void Schedule::SetPersonToPriem(std::string time,int userid) {
	for (int i = 0; i < 30; i++)
	{
		if (priem[i].first == time) { priem[i].second = userid; break; }
	}
}
/////////////////Гетеры//////////////////
int Schedule::GetId() { return id; };
int Schedule::GetDId() { return Did; };
std::string Schedule::GetDate() { return Date; };
std::pair<std::string, int> Schedule::GetPriem(int i) { return priem[i]; };

