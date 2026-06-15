#include "contacts.h"
#include "qdebug.h"
#include "qlogging.h"
#include <QTextStream>
#include <iostream>

Contacts::Contacts()
{
}

QString Contacts::getId() const
{
    return id;
}

QString Contacts::getName() const
{
    return name;
}
QString Contacts::getPhoneNumber() const
{
    return phoneNumber;
}
QString Contacts::getType() const
{
    return type;
}
QString Contacts::getRemarks() const
{
    return remarks;
}
QString Contacts::getBirth() const
{
    return Birth.text();
}

bool Contacts::setId(QString strID)
{
    this->id = strID;
    return true;
}
bool Contacts::setName(QString n)
{
    this->name = n;
    return true;
}

bool Contacts::setPhoneNumber(QString number)
{
    this->phoneNumber = number;
    return true;
}
bool Contacts::setType(QString type)
{
    this->type = type;
    return true;
}

bool Contacts::setBirth(QDate birthday)
{
    int day = birthday.day();
    int month = birthday.month();
    int year = birthday.year();
    Date birth(year, month, day);
    this->Birth = birth;
    return true;
}

bool Contacts::setRemarks(QString strInfo)
{
    this->remarks = strInfo;
    return true;
}

void Contacts::debugInfo()
{
    QTextStream(stdout) << "联系人信息：\n";
    QTextStream(stdout) << "编号：" << id << "\n";
    QTextStream(stdout) << "姓名：" << name << "\n";
    QTextStream(stdout) << "电话号码：" << phoneNumber << "\n";
    QTextStream(stdout) << "类型：" << type << "\n";
    QTextStream(stdout) << "生日：" << Birth.text() << "\n";
    QTextStream(stdout) << "标记：" << type << "\n";
}
