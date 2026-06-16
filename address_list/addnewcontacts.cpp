#include "addnewcontacts.h"
#include "contacts.h"
#include "mainwindow.h"
#include "ui_addnewcontacts.h"
#include <QMessageBox>

AddNewContacts::AddNewContacts(QWidget *parent) : QMainWindow(parent), ui(new Ui::AddNewContacts)
{
    setAttribute(Qt::WA_DeleteOnClose); // 在关闭窗口时自动销毁
    ui->setupUi(this);
    connect(ui->btnClearForm, &QPushButton::clicked, this, [this]() { clearForm(); });
    connect(ui->btnSaveOrAdd, &QPushButton::clicked, this, [this]() { SaveOrAdd(); });
}

AddNewContacts::~AddNewContacts()
{
    delete ui;
}

void AddNewContacts::clearForm()
{
    ui->lineEditId->clear();
    ui->labelName->clear();
    ui->lineEditPhone->clear();
    ui->comboType->setCurrentIndex(0);
    ui->dateEditBirthday->clear();
    ui->lineEditAddress->clear();
}

void AddNewContacts::SaveOrAdd()
{
    Contacts new_contacts;
    std::vector<Contacts> list = conList->readContactList();
    if (ui->lineEditId->text().isEmpty())
    {
        QMessageBox::critical(this, "缺少项", "未输入编号");
        return;
    }
    else if (ui->lineEditName->text().isEmpty())
    {
        QMessageBox::critical(this, "缺少项", "未输入姓名");
        return;
    }
    else if (std::find_if(list.begin(), list.end(),
                          [&](const Contacts &obj) { return obj.getId() == ui->lineEditId->text(); }) != list.end())
    {

        QMessageBox::critical(this, "重复", "重复编号");
        return;
    }

    new_contacts.setId(ui->lineEditId->text());
    new_contacts.setName(ui->lineEditName->text());
    new_contacts.setPhoneNumber(ui->lineEditPhone->text());
    new_contacts.setType(ui->comboType->currentText());
    new_contacts.setBirth(ui->dateEditBirthday->date());
    new_contacts.setRemarks(ui->lineEditAddress->text());

    new_contacts.debugInfo();
    conList->addNewContacts(new_contacts);

    this->close();
}
