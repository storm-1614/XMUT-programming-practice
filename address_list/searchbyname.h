#ifndef SEARCHBYNAME_H
#define SEARCHBYNAME_H

#include "contacts.h"
#include "search.h"
#include <vector>

class searchByName : public search
{
  public:
    searchByName();
    std::vector<int> find(const QString &Target) override;

};

#endif // SEARCHBYNAME_H
