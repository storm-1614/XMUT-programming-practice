#ifndef SEARCH_H
#define SEARCH_H

#include "contacts.h"
#include <QString>

class search
{
  public:
    search();
    virtual std::vector<int> find(const QString &Target) = 0;

    void setTarget(const QString &target);

  protected:
    std::vector<Contacts> list;
};

#endif // SEARCH_H
