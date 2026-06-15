#include "contactslist.h"

contactsList::contactsList()
{
}
bool contactsList::addNewContacts(Contacts ct)
{
    data.emplace_back(ct);
    return true;
}
bool contactsList::removeContacts()
{
    // TODO:
}
bool contactsList::modifyContacts()
{
    // TODO:
}

const std::vector<Contacts>& contactsList::readContactList() const
{
    return data;
}
