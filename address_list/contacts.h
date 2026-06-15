#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>
#include "date.h"

class Contacts
{
  public:
    Contacts();
    int getId();
    QString getName();
    QString getPhoneNumber();
    QString getType();
    QString getRemarks();
    Date getBirth();

  private:
    int id;
    QString name;
    QString phoneNumber;
    QString type;
    Date Birth;
    QString remarks;
};

#endif // CONTACTS_H
