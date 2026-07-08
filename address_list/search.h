#ifndef SEARCH_H
#define SEARCH_H

#include "contacts.h"
#include <QString>

/*
 * 搜索基类，应该差不多是一个抽象类吧？
 */
class search
{
  public:
    search();
    virtual ~search() = default;
    virtual std::vector<int> find(const QString &Target) = 0;

    void setTarget(const QString &target);

  protected:
    std::vector<Contacts> list;
};

#endif // SEARCH_H
