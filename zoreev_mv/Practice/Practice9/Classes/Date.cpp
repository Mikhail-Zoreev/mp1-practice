#include "../Headers/Date.h"

date::date()
{
    day = 1;
    month = 1;
    year = 1970;
}

date::date(const date& temp)
{
    day = temp.day;
    month = temp.month;
    year = temp.year;
}

date::date(unsigned _day, unsigned _month, unsigned _year)
{
    day = _day;
    month = _month;
    year = _year;
}

date& date::operator=(const date& temp)
{
    day = temp.day;
    month = temp.month;
    year = temp.year;
    return *this;
}

unsigned date::getDay()
{
    return day;
}

unsigned date::getMonth()
{
    return month;
}

unsigned date::getYear()
{
    return year;
}

void date::input()
{
    cin >> day >> month >> year;
}

void date::setDay(unsigned _day)
{
    day = _day;
}
void date::setMonth(unsigned _month)
{
    month = _month;
}

void date::setYear(unsigned _year)
{
    year = _year;
}