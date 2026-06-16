#include "contactslist.h"
#include "csv_file.h"
#include "qdebug.h"
#include <vector>

contactsList::contactsList()
{
    csv_path = "./data.csv";
    readcsv();
}

contactsList::~contactsList()
{
    saveContacts();
}
bool contactsList::addNewContacts(Contacts ct)
{
    data.emplace_back(ct);
    return true;
}
bool contactsList::removeContacts(std::set<int> rows)
{
    //  从大到小删除避免索引偏移
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
    {
        QTextStream(stdout) << "删除行: " << *it << "\n";
        data.erase(data.begin() + *it);
    }
    return true;
}
bool contactsList::modifyContacts()
{
    // TODO:
    return true;
}

bool contactsList::readcsv()
{
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
    }
    QTextStream(stdout) << "读取成功\n";
    return true;
}
bool contactsList::saveContacts()
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

    csv.write_to_csv(csv_path.c_str(), csv_data);
    QTextStream(stdout) << csv_data.size() << "保存成功\n";
    return true;
}
std::vector<Contacts> &contactsList::readContactList()
{
    return data;
}
