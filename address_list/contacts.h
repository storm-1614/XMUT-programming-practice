#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>
#include <QDate>
#include "date.h"

class Contacts
{
  public:
    Contacts();
    int getId();
    QString getName() const;
    QString getPhoneNumber() const;
    QString getType() const;
    QString getRemarks() const;
    Date getBirth() const;
    bool setId(QString strID);
    bool setName(QString name);
    bool setType(QString type);
    bool setBirth(QDate birthday);
    bool setRemarks(QString strInfo);

    void debugInfo();


  private:
    QString id;
    QString name;
    QString phoneNumber;
    QString type;
    Date Birth;
    QString remarks;
};

#endif // CONTACTS_H
