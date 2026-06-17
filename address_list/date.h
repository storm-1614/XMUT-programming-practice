#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
  public:
    Date();
    Date(int y, int m, int d);
    bool isLeapYear();
    bool isLeapYear(int y);
    bool isValid();
    int dayTo(Date day, bool year = false);
    const QString text() const;
    int toAbsoluteDay();
    int toAbsoluteDayForYear();
    int getAbsoluteDay();
    int getAbsoluteDayForYear();
    
    static constexpr int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  private:
    int year, month, day;
    int absoluteDay;
    int absoluteDayForYear;
};

#endif // DATE_H
