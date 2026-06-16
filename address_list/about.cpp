#include "about.h"
#include "ui_about.h"
#include <QPushButton>

about::about(QWidget *parent) : QMainWindow(parent), ui(new Ui::about)
{
    ui->setupUi(this);
    connect(ui->btnOK,&QPushButton::clicked, this, [this]() { close(); });
}

about::~about()
{
    delete ui;
}
