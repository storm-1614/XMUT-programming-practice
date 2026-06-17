#include "birthreminder.h"
#include "qnamespace.h"
#include "ui_birthreminder.h"

birthReminder::birthReminder(QWidget *parent) : QMainWindow(parent), ui(new Ui::birthReminder)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    QTextStream(stdout) << "生日提醒窗口打开\n";
    connect(ui->btnNo, &QPushButton::clicked, this, [this](){close();});
    connect(ui->btnYes, &QPushButton::clicked, this, [this](){doReminder();});
}

birthReminder::~birthReminder()
{
    delete ui;
}

bool birthReminder::initialList(std::vector<Contacts> list)
{
    selectedContacts = list;
    int row = list.size();
    ui->tableContacts->clearContents();
    ui->tableContacts->setRowCount(row);

    for (int i = 0; i < row; i++)
    {
        ui->tableContacts->setItem(i, 0, new QTableWidgetItem(list[i].getId()));
        ui->tableContacts->setItem(i, 1, new QTableWidgetItem(list[i].getName()));
        ui->tableContacts->setItem(i, 2, new  QTableWidgetItem(list[i].getPhoneNumber()));
        ui->tableContacts->setItem(i, 3, new  QTableWidgetItem(list[i].getType()));
        ui->tableContacts->setItem(i, 4, new  QTableWidgetItem(list[i].getBirth()));
        ui->tableContacts->setItem(i, 5, new  QTableWidgetItem(list[i].getRemarks()));
    }
    return true;
}


void birthReminder::doReminder()
{
    QList<QTableWidgetItem *> selectedItems = ui->tableContacts->selectedItems();
    
    close();
}
