#ifndef CONTACTSLIST_H
#define CONTACTSLIST_H

#include "contacts.h"
#include <vector>

class contactsList
{
  public:
    contactsList();
    bool addNewContacts(Contacts ct);
    bool removeContacts();
    bool modifyContacts();
    const std::vector<Contacts>& readContactList() const;

  private:
    std::vector<Contacts> data;
};

#endif // CONTACTSLIST_H
