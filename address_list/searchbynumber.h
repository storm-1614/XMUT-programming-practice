#ifndef SEARCHBYNUMBER_H
#define SEARCHBYNUMBER_H

#include "search.h"
#include <vector>
#include "mainwindow.h"

class searchByNumber:public search
{
  public:
    searchByNumber();
    std::vector<int> find(const QString &Target) override;
};

#endif // SEARCHBYNUMBER_H
