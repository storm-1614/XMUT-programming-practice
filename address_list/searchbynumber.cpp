#include "searchbynumber.h"
#include "mainwindow.h"

searchByNumber::searchByNumber():search()
{
    list = conList.readContactList();
}

std::vector<int> searchByNumber::find(const QString &Target)
{
    std::vector<int> selectList;
    for (size_t i = 0; i < list.size(); ++i)
    {
        // 用 QT 的 CaseInsensitive 实现子串匹配，不过算法复杂度 O(n)
        if (list[i].getName().contains(Target, Qt::CaseInsensitive))
        {
            selectList.emplace_back(i);
        }
    }
    return selectList;
}
