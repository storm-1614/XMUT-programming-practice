#ifndef ADDNEWCONTACTS_H
#define ADDNEWCONTACTS_H

#include <QMainWindow>

namespace Ui
{
class AddNewContacts;
}

class AddNewContacts : public QMainWindow
{
    Q_OBJECT

  public:
    explicit AddNewContacts(QWidget *parent = nullptr);
    ~AddNewContacts();
    void clearForm();
    void SaveOrAdd();



  private:
    Ui::AddNewContacts *ui;
};

#endif // ADDNEWCONTACTS_H
