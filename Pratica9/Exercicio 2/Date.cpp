#include "Date.h"

Date::Date() : year_(1), month_(1), day_(1) {}

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {}

bool Date::is_before(const Date &date) const
{
    return (year_*10000+month_*100+day_< date.getYear()*10000+date.getMonth()*100+date.getDay());
}
