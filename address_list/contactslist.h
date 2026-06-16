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
    size_t size();
    bool readcsv(); 
    bool saveContacts();
    bool saveContacts(std::string path);
    std::vector<Contacts> &readContactList();
    const std::map<int, int> &getTypeListMap();
    void typeMapRebuild();

  private:
    std::vector<Contacts> data;
    std::string csv_path;
    csv_file csv;
    std::map<int, int> typeMap{{Contacts::schoolmates, 0},
                               {Contacts::teachers, 0},
                               {Contacts::family, 0},
                               {Contacts::clubs, 0},
                               {Contacts::other, 0}};
};

#endif // CONTACTSLIST_H
