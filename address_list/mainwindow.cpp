#include "mainwindow.h"
#include "contacts.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnSaveOrAdd, &QPushButton::clicked, this, [this]() { addContacts(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::addContacts()
{
    Contacts new_contacts;
    new_contacts.setId(ui->lineEditId->text());
    new_contacts.setName(ui->lineEditName->text());
    new_contacts.setType(ui->comboType->currentText());
    new_contacts.setBirth(ui->dateEditBirthday->date());
    new_contacts.setRemarks(ui->lineEditAddress->text());

    new_contacts.debugInfo();

    return false;
}
