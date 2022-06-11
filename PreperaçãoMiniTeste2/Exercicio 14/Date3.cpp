#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date3.h"

using namespace std;

int days_in_month(int year, int month)
{
    int n_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 29;
    return n_days[month - 1];
}

Date::Date() {
    yyyymmdd="00010101";
}

Date::Date(int year, int month, int day){
    yyyymmdd="00000000";
    if (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= days_in_month(year, month))
    {
        this->yyyymmdd.replace(0, 4, to_string(year));
        this->yyyymmdd.replace(4, 2, to_string(month));
        this->yyyymmdd.replace(6, 2, to_string(day));
    }
}

Date::Date(const string& year_month_day){
    int year, month, day;
    char sep1, sep2;
    istringstream iss(year_month_day);
    yyyymmdd="00000000";
    if (iss >> year >> sep1 >> month >> sep2 >> day && sep1 == '/' && sep2 == '/' && year >= 1 &&
     year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= days_in_month(year, month)){
        this->yyyymmdd.replace(0, 4, to_string(year));
        if (month >= 10)
            this->yyyymmdd.replace(4, 2, to_string(month));
        else
            this->yyyymmdd.replace(5, 1, to_string(month));
        if (day >= 10)
            this->yyyymmdd.replace(6, 2, to_string(day));
        else
            this->yyyymmdd.replace(7, 1, to_string(day));
     }
}

int Date::get_year() const{
    return stoi(yyyymmdd.substr(0, 4));
}

int Date::get_month() const{
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_day() const{
    return stoi(yyyymmdd.substr(6, 2));
}

bool Date::is_valid() const{
    if(stoi(yyyymmdd.substr(0, 4))==0000) return false;
    if(stoi(yyyymmdd.substr(4, 2))==00) return false;
    if(stoi(yyyymmdd.substr(6, 2))==00) return false;
    return true;
}
