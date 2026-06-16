#ifndef CONTACTSLIST_H
#define CONTACTSLIST_H

#include "contacts.h"
#include "csv_file.h"
#include <vector>

class contactsList
{
  public:
    contactsList();
    ~contactsList();
    bool addNewContacts(Contacts ct);
    bool removeContacts();
    bool modifyContacts();
    bool readcsv();
    bool saveContacts();
    std::vector<Contacts>& readContactList();

  private:
    std::vector<Contacts> data;
    csv_file csv;

};

#endif // CONTACTSLIST_H
