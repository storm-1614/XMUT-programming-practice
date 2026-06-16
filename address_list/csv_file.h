#ifndef CSV_FILE_H
#define CSV_FILE_H

#include <string>
#include <vector>

class csv_file
{
  public:
    csv_file();
    csv_file(const char * path);
    std::vector<std::vector<std::string>> load_from_csv(const char *path);
    bool write_to_csv(const char *path, std::vector<std::vector<std::string>> data);
    std::vector<std::string> division(const std::string &line);

  private:
};

#endif // CSV_FILE_H
