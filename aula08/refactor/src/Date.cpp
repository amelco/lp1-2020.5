#include "Date.h"

#include <sstream>
#include <iomanip>

Date::Date(): year(0), month(0), day(0)
{
}

void Date::set_from_string(const std::string& date)
{
    std::stringstream stream(date);
    char discard;
    stream >> day;   stream >> discard;
    stream >> month; stream >> discard;
    stream >> year;
}

std::string Date::to_string()
{
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(2) << day;   stream << '/';
    stream << std::setfill('0') << std::setw(2) << month; stream << '/';
    stream << year;
    return stream.str();
}