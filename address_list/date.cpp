#include "date.h"
#include "qdebug.h"

Date::Date()
{
    
}

Date::Date(int y, int m, int d)
{
    this->year = y;
    this->month = m;
    this->day = d;
}


const QString Date::text() const
{
    const QString text = QString("%1-%2-%3").arg(year).arg(month).arg(day);
    return text;
}

