#include "addnewcontacts.h"
#include "mainwindow.h"
#include "ui_addnewcontacts.h"
#include "contacts.h"

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
