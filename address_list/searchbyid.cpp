#include "searchbyid.h"

searchById::searchById() : search()
{
    list = conList->readContactList();
}

std::vector<int> searchById::find(const QString &Target)
{
    std::vector<int> selectList;
    for (size_t i = 0; i < list.size(); ++i)
    {
        if (list[i].getPhoneNumber() == Target)
        {
            selectList.emplace_back(i);
        }
    }
    return selectList;
}
