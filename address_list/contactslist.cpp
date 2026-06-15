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

std::vector<Contacts>& contactsList::readContactList()
{
    return data;
}
