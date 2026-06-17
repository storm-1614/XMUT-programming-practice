#include "date.h"
#include "qdebug.h"
#include <stdexcept>
#include <QTextStream>
Date::Date()
{
}

Date::Date(int y, int m, int d)
{
    if (m < 1 || m > 12 || d > monthDays[m - 1] || d < 1)
    {
        throw std::invalid_argument("非法日期");
    }
    this->year = y;
    this->month = m;
    this->day = d;
    this->absoluteDay = toAbsoluteDay();
    this->absoluteDayForYear = toAbsoluteDayForYear();
}

const QString Date::text() const
{
    const QString text = QString("%1-%2-%3").arg(year).arg(month).arg(day);
    return text;
}

bool Date::isLeapYear()
{
    return (this->year % 4 == 0 && this->year % 100 != 0) || (this->year % 400 == 0);
}

bool Date::isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}
bool Date::isValid()
{
    return !(month < 1 || month > 12 || day > monthDays[month - 1] || day < 1);
}
int Date::dayTo(Date day, bool year)
{
    if (year == true)
        return day.getAbsoluteDayForYear() - this->absoluteDayForYear;
    return day.getAbsoluteDay() - this->absoluteDay;
}

int Date::toAbsoluteDay()
{
    int total = 0;
    for (int y = 1; y < this->year; y++)
    {
        total += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 0; m < this->month - 1; m++)
    {
        total += monthDays[m];
    }
    if (isLeapYear(this->year) && this->month > 2)
    {
        total += 1;
    }
    return total;
}

int Date::getAbsoluteDay()
{
    return this->absoluteDay;
}

int Date::getAbsoluteDayForYear()
{
    return this->absoluteDayForYear;
}

int Date::toAbsoluteDayForYear()
{
    int total = 0;
    for (int m = 0; m < this->month - 1; m++)
    {
        total += monthDays[m];
    }
    if (isLeapYear(this->year) && this->month > 2)
    {
        total += 1;
    }
    return total;
}
