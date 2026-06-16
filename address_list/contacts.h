#ifndef CONTACTS_H
#define CONTACTS_H

#include <QString>
#include <QDate>
#include "date.h"
#include "csv_file.h"

class Contacts
{
  public:
    Contacts();
    QString getId() const;
    QString getName() const;
    QString getPhoneNumber() const;
    QString getType() const;
    QString getRemarks() const;
    QString getBirth() const;
    bool setId(QString strID);
    bool setName(QString name);
    bool setPhoneNumber(QString number);
    bool setType(QString type);
    bool setBirth(QDate birthday);
    bool setBirth(QString birthStr); // y-m-d
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
