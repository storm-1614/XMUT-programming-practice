#include "mainwindow.h"
#include "contacts.h"
#include "qdebug.h"
#include "searchbyname.h"
#include "searchbynumber.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <vector>

contactsList conList;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableContacts->setSelectionMode(QAbstractItemView::MultiSelection); // 多选
    connect(ui->btnSaveOrAdd, &QPushButton::clicked, this, [this]() { addContacts(); });
    connect(ui->btnClearForm, &QPushButton::clicked, this, [this]() { clearForm(); });
    connect(ui->btnSearch, &QPushButton::clicked, this, [this]() { searchClicked(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * 添加新的联系人
 */
bool MainWindow::addContacts()
{
    Contacts new_contacts;
    new_contacts.setId(ui->lineEditId->text());
    new_contacts.setName(ui->lineEditName->text());
    new_contacts.setPhoneNumber(ui->lineEditPhone->text());
    new_contacts.setType(ui->comboType->currentText());
    new_contacts.setBirth(ui->dateEditBirthday->date());
    new_contacts.setRemarks(ui->lineEditAddress->text());

    new_contacts.debugInfo();
    conList.addNewContacts(new_contacts);

    updateContacts();
    return true;
}

/*
 * 更新联系人列表
 */
bool MainWindow::updateContacts()
{
    const std::vector<Contacts> contacts = conList.readContactList();

    int row = contacts.size();

    ui->tableContacts->clearContents();
    ui->tableContacts->setRowCount(contacts.size());

    for (int i = 0; i < row; i++)
    {
        ui->tableContacts->setItem(i, 0, new QTableWidgetItem(contacts[i].getId()));
        ui->tableContacts->setItem(i, 1, new QTableWidgetItem(contacts[i].getName()));
        ui->tableContacts->setItem(i, 2, new QTableWidgetItem(contacts[i].getPhoneNumber()));
        ui->tableContacts->setItem(i, 3, new QTableWidgetItem(contacts[i].getType()));
        ui->tableContacts->setItem(i, 4, new QTableWidgetItem(contacts[i].getBirth()));
        ui->tableContacts->setItem(i, 5, new QTableWidgetItem(contacts[i].getRemarks()));
    }
    ui->labelCount->setText(QString("共 %1 位联系人").arg(row));
    return true;
}

/*
 * 清理表单
 */
bool MainWindow::clearForm()
{
    ui->lineEditId->clear();
    ui->lineEditName->clear();
    ui->lineEditPhone->clear();
    ui->comboType->setCurrentIndex(0);
    ui->dateEditBirthday->clear();
    ui->lineEditAddress->clear();

    return true;
}

bool MainWindow::searchClicked()
{
    switch (ui->comboSearchField->currentIndex())
    {
    case name: {
        searchByName s;
        std::vector<int> selectd = s.find(ui->lineEditSearch->text());
        for (auto iter : selectd)
        {
            QTextStream(stdout) << iter << "\n";
            ui->tableContacts->selectRow(iter);
        }
    }

    case phomeNumber: {
        searchByNumber s;
        std::vector<int> selectd = s.find(ui->lineEditSearch->text());
        for (auto iter : selectd)
        {
            QTextStream(stdout) << iter << "\n";
            ui->tableContacts->selectRow(iter);
        }
    }
    case id: {
    }
    }
    return true;
}
