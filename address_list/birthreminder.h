#ifndef BIRTHREMINDER_H
#define BIRTHREMINDER_H

#include <QMainWindow>
#include <vector>
#include "contacts.h"

namespace Ui
{
class birthReminder;
}

class birthReminder : public QMainWindow
{
    Q_OBJECT

  public:
    explicit birthReminder(QWidget *parent = nullptr);
    ~birthReminder();
    bool initialList(std::vector<Contacts> list);
    void doReminder();

  private:
    Ui::birthReminder *ui;
    std::vector<Contacts> selectedContacts;
};

#endif // BIRTHREMINDER_H
