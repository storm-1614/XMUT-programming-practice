#ifndef SEARCHBYID_H
#define SEARCHBYID_H

#include "search.h"
#include "mainwindow.h"

class searchById : public search
{
  public:
    searchById();
    std::vector<int> find(const QString &Target) override;
};

#endif // SEARCHBYID_H
