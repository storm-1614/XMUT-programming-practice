#ifndef CONTACTSLIST_H
#define CONTACTSLIST_H

#include "contacts.h"
#include "csv_file.h"
#include <QTableWidget>
#include <set>
#include <string>
#include <vector>

class contactsList
{
  public:
    contactsList();
    ~contactsList();
    bool addNewContacts(Contacts ct);
    bool removeContacts(std::set<int> rows);
    bool modifyContacts();
    bool loadFromTable(QTableWidget *table);
    bool setPath(const char *path);
    bool readcsv();
    bool saveContacts();
    bool saveContacts(std::string path);
    std::vector<Contacts> &readContactList();

  private:
    std::vector<Contacts> data;
    std::string csv_path;
    csv_file csv;
};

#endif // CONTACTSLIST_H
