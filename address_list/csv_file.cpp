#include "csv_file.h"
#include <QTextStream>
#include <fstream>
#include <vector>

csv_file::csv_file()
{
}

csv_file::csv_file(const char *path)
{
}

std::vector<std::vector<std::string>> csv_file::load_from_csv(const char *path)
{
    std::ifstream in(path, std::fstream::in);
    if (!in)
    {
        return std::vector<std::vector<std::string>>{};
    }
    std::vector<std::vector<std::string>> data;
    std::string line;
    while (std::getline(in, line))
    {
        std::vector<std::string> lineData = {};
        if (line.empty())
        {
            data.emplace_back(lineData);
            continue;
        }

        lineData = division(line);
        data.emplace_back(lineData);
    }
    return data;
}
bool csv_file::write_to_csv(const char *path, std::vector<std::vector<std::string>> data)
{
    std::ofstream out(path);
    for (auto s : data)
    {
        for (auto i : s)
        {
            out << i << ",";
            QTextStream(stdout) << i.c_str() << "\n";
        }
        out << "\n";
    }
    return true;
}

std::vector<std::string> csv_file::division(const std::string &line)
{
    std::vector<std::string> column;
    std::string item;
    for (char ch : line)
    {
        if (ch == ',')
        {
            column.emplace_back(item);
            item.clear();
        }
        else
        {
            item += ch;
        }
    }
    column.emplace_back(item);
    return column;
}
