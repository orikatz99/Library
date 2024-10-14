#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Date.h"


Date::Date() : day(0), month(0), year(0) {}// Default constructor
Date::Date(int d, int m, int y)
{
    if (!setYear(y) || !setMonth(m) || !setDay(d)) //invalid date, set to a default date
    {
        day = 0;
        month = 0;
        year = 0;
    }
}
Date::Date(const Date& other)
    : day(other.day), month(other.month), year(other.year) {}

// Getters
int Date::getDay() const
{
    return day;
}
int Date::getMonth() const
{
    return month;
}
int Date::getYear() const
{
    return year;
}

// Setters
bool Date::setDay(int d)
{
    if (month >= 1 && month <= 12 && d >= 1 && d <= daysInMonth[month - 1])
    {
        day = d;
        return true;
    }
    return false;
}
bool Date::setMonth(int m)
{
    if (m >= 1 && m <= 12)
    {
        month = m;
        if (day >= 0 && day <= daysInMonth[month - 1])
        {
            return true;
        }
    }
    return false;
}
bool Date::setYear(int y)
{
    if (y > 0)
    {
        year = y;
        return true;
    }
    return false;
}

void Date::printDate() const {

    std::cout << day << "/" << month << "/" << year << std::endl;
}


