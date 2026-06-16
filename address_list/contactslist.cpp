#include "contactslist.h"
#include "contacts.h"
#include "csv_file.h"
#include <algorithm>
#include "qdebug.h"
#include "qmessagebox.h"
#include <vector>

contactsList::contactsList()
{
    csv_path = "./data.csv";
    readcsv();
}

contactsList::~contactsList()
{
    saveContacts(csv_path);
}
bool contactsList::addNewContacts(Contacts ct)
{

    QString type = ct.getType();
    if (type == "同学")
    {
        typeMap[Contacts::schoolmates]++;
    }
    else if (type == "教师")
    {
        typeMap[Contacts::teachers]++;
    }
    else if (type == "家人")
    {
        typeMap[Contacts::family]++;
    }
    else if (type == "社团")
    {
        typeMap[Contacts::clubs]++;
    }
    else
    {
        typeMap[Contacts::other]++;
    }
    data.emplace_back(ct);
    return true;
}
bool contactsList::removeContacts(std::set<int> rows)
{
    //  从大到小删除避免索引偏移
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
    {
        QTextStream(stdout) << "删除行: " << *it << "\n";
        QString type = (data.begin() + *it)->getType();
        if (type == "同学")
        {
            typeMap[Contacts::schoolmates]--;
        }
        else if (type == "教师")
        {
            typeMap[Contacts::teachers]--;
        }
        else if (type == "家人")
        {
            typeMap[Contacts::family]--;
        }
        else if (type == "社团")
        {
            typeMap[Contacts::clubs]--;
        }
        else
        {
            typeMap[Contacts::other]--;
        }

        data.erase(data.begin() + *it);
    }
    return true;
}
bool contactsList::modifyContacts()
{
    // TODO:
    return true;
}

/*
 * 从表格中加载回 vector
 *
 */
bool contactsList::loadFromTable(QTableWidget *table)
{
    this->data.clear();
    int rows = table->rowCount();
    for (int i = 0; i < rows; i++)
    {
        Contacts new_contacts;
        new_contacts.setId(table->item(i, 0)->text());
        new_contacts.setName(table->item(i, 1)->text());
        new_contacts.setPhoneNumber(table->item(i, 2)->text());
        new_contacts.setType(table->item(i, 3)->text());
        new_contacts.setBirth(table->item(i, 4)->text());
        new_contacts.setRemarks(table->item(i, 5)->text());
        this->data.emplace_back(new_contacts);
    }
    return true;
}

bool contactsList::setPath(const char *path)
{
    csv_path = path;
    return true;
}

size_t contactsList::size()
{
    return data.size();
}
bool contactsList::readcsv()
{
    if (!data.empty())
        data.clear();
    csv = csv_file();
    std::vector<std::vector<std::string>> csv_data = csv.load_from_csv(csv_path.c_str());
    for (auto line : csv_data)
    {
        Contacts ct;

        // 防止空字段导致错误
        auto safeField = [&line](size_t i) -> std::string { return (i < line.size()) ? line[i] : ""; };
        std::string f0 = safeField(0), f1 = safeField(1), f2 = safeField(2);
        std::string f3 = safeField(3), f4 = safeField(4), f5 = safeField(5);

        if (!f0.empty())
            ct.setId(QString::fromStdString(f0));
        if (!f1.empty())
            ct.setName(QString::fromStdString(f1));
        if (!f2.empty())
            ct.setPhoneNumber(QString::fromStdString(f2));
        if (!f3.empty())
            ct.setType(QString::fromStdString(f3));
        if (!f4.empty())
            ct.setBirth(QString::fromStdString(f4));
        if (!f5.empty())
            ct.setRemarks(QString::fromStdString(f5));

        data.emplace_back(ct);
        typeMapRebuild();
    }
    QTextStream(stdout) << "读取成功\n";
    return true;
}
bool contactsList::saveContacts(std::string path)
{
    std::vector<std::vector<std::string>> csv_data(0, std::vector<std::string>(6));
    for (auto contact : data)
    {
        std::vector<std::string> linedata(6);
        linedata[0] = contact.getId().toStdString();
        linedata[1] = contact.getName().toStdString();
        linedata[2] = contact.getPhoneNumber().toStdString();
        linedata[3] = contact.getType().toStdString();
        linedata[4] = contact.getBirth().toStdString();
        linedata[5] = contact.getRemarks().toStdString();
        csv_data.emplace_back(linedata);
    }

    csv.write_to_csv(path.c_str(), csv_data);
    QTextStream(stdout) << csv_data.size() << "保存成功\n";
    return true;
}
std::vector<Contacts> &contactsList::readContactList()
{
    return data;
}

const std::map<int, int> &contactsList::getTypeListMap()
{
    return typeMap;
}

void contactsList::typeMapRebuild()
{
    for (auto &map : typeMap)
    {
        map.second = 0;
    }

    for (auto iter : data)
    {
        QString type = iter.getType();
        if (type == "同学")
        {
            typeMap[Contacts::schoolmates]++;
        }
        else if (type == "教师")
        {
            typeMap[Contacts::teachers]++;
        }
        else if (type == "家人")
        {
            typeMap[Contacts::family]++;
        }
        else if (type == "社团")
        {
            typeMap[Contacts::clubs]++;
        }
        else
        {
            typeMap[Contacts::other]++;
        }
    }
}
