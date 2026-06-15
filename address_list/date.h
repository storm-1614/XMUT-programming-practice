#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{
  public:
    Date();
    Date(int y, int m, int d);
    bool isLeapYear();
    bool isValid();
    bool dayTo();
    QString text();
    

  private:
    int year, month, day;
};

#endif // DATE_H
