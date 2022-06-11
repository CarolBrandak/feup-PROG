#include "Date.h"

Date::Date(): year_(1), month_(1), year_(1) { }

Date::Date(int year, int month, int day): year_(year), month_(month), year_(year) { }

int Date::getYear() const { return year_;}

int Date::getMonth() const { return month_;}

int Date::getDay() const { return day_;}

bool Date::is_before(const Date& date) const{
    return (year_*10000+month_*100+day_< date.getYear()*10000+date.getMonth()*100+date.getDay());
}


