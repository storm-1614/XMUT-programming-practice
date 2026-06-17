#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addnewcontacts.h"
#include "birthreminder.h"
#include "contactslist.h"
#include <QMainWindow>

extern contactsList *conList;

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    bool addContacts();
    bool updateContacts();
    bool clearForm();
    bool searchClicked();
    bool statistics();
    bool birthdayReminder();

    bool actionAddItem();
    bool actionDelItem();
    bool actionModifyItem();
    bool actionOpenCsv();  
    bool actionSaveCsv(); 

    bool menuAbout();

  private slots:
  private:
    Ui::MainWindow *ui;
    AddNewContacts *add_contacts_win = nullptr;
    birthReminder *br_win = nullptr;

    bool tableModify = false;

    enum searchType
    {
        name = 0,
        phomeNumber,
        id
    };
};
#endif // MAINWINDOW_H
