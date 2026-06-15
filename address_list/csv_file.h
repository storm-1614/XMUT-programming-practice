#ifndef CSV_FILE_H
#define CSV_FILE_H

#include <string>
class csv_file
{
  public:
    csv_file();
    bool load_from_csv(const char * path);
    bool write_to_csv(const char * path);
    bool division(const std::string &line);

  private:
};

#endif // CSV_FILE_H
