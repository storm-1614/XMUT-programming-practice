#ifndef DATE_H
#define DATE_H

class Date
{
  public:
    Date();
    bool isLeapYear();
    bool isValid();
    bool dayTo();

  private:
    int year, month, day;
};

#endif // DATE_H
