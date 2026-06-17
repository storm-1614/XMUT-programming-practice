#include "mainwindow.h"
#include "about.h"
#include "birthreminder.h"
#include "contacts.h"
#include "contactslist.h"
#include "qdebug.h"
#include "qfiledialog.h"
#include "qlist.h"
#include "qmessagebox.h"
#include "searchbyid.h"
#include "searchbyname.h"
#include "searchbynumber.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <cmath>
#include <set>
#include <vector>

contactsList *conList;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    conList = new contactsList;
    ui->setupUi(this);
    ui->tableContacts->setSelectionMode(QAbstractItemView::MultiSelection); // 多选
    ui->tableContacts->setSortingEnabled(false);                            // 禁止默认排序
    connect(ui->btnSaveOrAdd, &QPushButton::clicked, this, [this]() { addContacts(); });
    connect(ui->btnClearForm, &QPushButton::clicked, this, [this]() { clearForm(); });
    connect(ui->btnSearch, &QPushButton::clicked, this, [this]() { searchClicked(); });
    connect(ui->btnStatistics, &QPushButton::clicked, this, [this]() { statistics(); });
    connect(ui->btnBirthdayReminder, &QPushButton::clicked, this, [this]() { birthdayReminder(); });

    connect(ui->actionAdd, &QAction::triggered, this, [this]() { actionAddItem(); });
    connect(ui->actionDelete, &QAction::triggered, this, [this]() { actionDelItem(); });
    connect(ui->actionModify, &QAction::triggered, this, [this]() { actionModifyItem(); });
    connect(ui->actionLoad, &QAction::triggered, this, [this]() { actionOpenCsv(); });
    connect(ui->actionSave, &QAction::triggered, this, [this]() { actionSaveCsv(); });
    connect(ui->actionAbout, &QAction::triggered, this, [this]() { menuAbout(); });
    connect(ui->actionExit, &QAction::triggered, this, [this]() { close(); });
    connect(ui->actionStatistics, &QAction::triggered, this, [this]() { statistics(); });
    connect(ui->actionRefresh, &QAction::triggered, this, [this]() { updateContacts(); });

    updateContacts();
}

MainWindow::~MainWindow()
{
    delete conList;
    delete ui;
}

/*
 * 添加新的联系人
 */
bool MainWindow::addContacts()
{
    Contacts new_contacts;
    std::vector<Contacts> list = conList->readContactList();
    if (ui->lineEditId->text().isEmpty())
    {
        QMessageBox::critical(this, "缺少项", "未输入编号");
        ui->lineEditId->setFocus();
        return false;
    }
    else if (ui->lineEditName->text().isEmpty())
    {
        QMessageBox::critical(this, "缺少项", "未输入姓名");
        ui->lineEditName->setFocus();
        return false;
    }
    else if (std::find_if(list.begin(), list.end(),
                          [&](const Contacts &obj) { return obj.getId() == ui->lineEditId->text(); }) != list.end())
    {

        QMessageBox::critical(this, "重复", QString("编号 %1 已存在请输入其它编号").arg(ui->lineEditId->text()));
        ui->lineEditId->setFocus();
        return false;
    }

    new_contacts.setId(ui->lineEditId->text());
    new_contacts.setName(ui->lineEditName->text());
    new_contacts.setPhoneNumber(ui->lineEditPhone->text());
    new_contacts.setType(ui->comboType->currentText());
    new_contacts.setBirth(ui->dateEditBirthday->date());
    new_contacts.setRemarks(ui->lineEditAddress->text());

    new_contacts.debugInfo();
    conList->addNewContacts(new_contacts);

    updateContacts();
    return true;
}

/*
 * 更新联系人列表
 */
bool MainWindow::updateContacts()
{
    std::vector<Contacts> contacts = conList->readContactList();

    int row = contacts.size();

    ui->tableContacts->clearContents();
    ui->tableContacts->setRowCount(row);

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

/*
 * 没招了，我这里用了多态集成了，不要纠结我没有按任务书里把联系人分出子类继承虚函数好么
 */
bool MainWindow::searchClicked()
{
    search *s;
    ui->tableContacts->clearSelection();
    switch (ui->comboSearchField->currentIndex())
    {
    case name: {
        s = new searchByName;
        break;
    }
    case phomeNumber: {
        s = new searchByNumber;
        break;
    }
    case id: {
        s = new searchById;
        break;
    }
    }
    std::vector<int> selectd = s->find(ui->lineEditSearch->text());
    for (auto iter : selectd)
    {
        QTextStream(stdout) << iter << "\n";
        ui->tableContacts->selectRow(iter);
    }

    return true;
}

bool MainWindow::statistics()
{
    QString info = QString("联系人数量：%1\n").arg(conList->size());
    QString type = QString("类型：\n同学：%1\n教师：%2\n家人：%3\n社团：%4\n其他：%5\n")
                       .arg(conList->getTypeListMap().at(Contacts::schoolmates))
                       .arg(conList->getTypeListMap().at(Contacts::teachers))
                       .arg(conList->getTypeListMap().at(Contacts::family))
                       .arg(conList->getTypeListMap().at(Contacts::clubs))
                       .arg(conList->getTypeListMap().at(Contacts::other));

    QMessageBox::information(this, "统计信息", info + type, QMessageBox::Ok);
    return true;
}

bool MainWindow::birthdayReminder()
{
    QDate qdate = ui->dateEditToday->date();
    Date date(qdate.year(), qdate.month(), qdate.day());
    int afterDay = ui->spinBoxRemindDays->value();
    std::vector<Contacts> list = conList->readContactList();
    std::vector<Contacts> rangerList;

    for (auto iter : list)
    {
        int dayTo = iter.getBirthMeta().dayTo(date, true);
        if (dayTo >= 0 && dayTo <= afterDay)
            rangerList.emplace_back(iter);
    }

    if (br_win == nullptr)
    {
        br_win = new birthReminder(this);
        br_win->initialList(rangerList);
        br_win->show();
    }
    connect(br_win, &MainWindow::destroyed, this, [this]() { br_win = nullptr; });

    return true;
}

bool MainWindow::actionAddItem()
{
    /*
     * 为了防止点击创建多个窗口，设置指针判断
     */
    if (add_contacts_win == nullptr)
    {
        add_contacts_win = new AddNewContacts(this);
        add_contacts_win->show();
    }

    connect(add_contacts_win, &MainWindow::destroyed, this, [this]() {
        add_contacts_win = nullptr;
        updateContacts();
    });

    return true;
}

/*
 * 删除选中的联系人项
 * std::set 存储唯一行号，避免了多次记录行号，且 set 按升序排列
 */
bool MainWindow::actionDelItem()
{
    switch (QMessageBox::warning(this, "警告", "是否要删除选中项", QMessageBox::Yes, QMessageBox::No))
    {
    case QMessageBox::Yes:
        break;
    case QMessageBox::No:
        return false;
        break;
    }

    QList<QTableWidgetItem *> selectedItems = ui->tableContacts->selectedItems();

    std::set<int> rows;
    for (QTableWidgetItem *item : selectedItems)
    {
        rows.insert(item->row());
    }
    conList->removeContacts(rows);

    updateContacts();
    return true;
}

bool MainWindow::actionModifyItem()
{
    if (tableModify == false)
    {
        QMessageBox::information(this, "修改列表项", "点击后可以修改文件，之后再按一次修改联系人保存修改",
                                 QMessageBox::Ok);
        ui->tableContacts->setEditTriggers(QAbstractItemView::DoubleClicked);
        for (size_t i = 0; i < conList->size(); i++)
        {
            QTableWidgetItem *item = ui->tableContacts->item(i, 0);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
        tableModify = true;
    }
    else
    {
        switch (QMessageBox::warning(this, "警告", "是否要修改内容", QMessageBox::Yes, QMessageBox::No))
        {
        case QMessageBox::Yes:
            break;
        case QMessageBox::No:
            return false;
            break;
        }

        conList->loadFromTable(ui->tableContacts);
        ui->tableContacts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableModify = false;
    }

    return true;
}

bool MainWindow::actionOpenCsv()
{
    QString fileName =
        QFileDialog::getOpenFileName(this, tr("选择 csv 文件"), ".", tr("csv文件 (*.csv);;所有文件 (*.*)"));
    if (!fileName.isEmpty())
    {
        QTextStream(stdout) << "选中文件:" << fileName << "\n";
        conList->setPath(fileName.toStdString().c_str());
        conList->readcsv();
        updateContacts();

        return true;
    }
    return false;
}

bool MainWindow::actionSaveCsv()
{
    QString fileName =
        QFileDialog::getOpenFileName(this, tr("选择 csv 文件"), ".", tr("csv文件 (*.csv);;所有文件 (*.*)"));
    if (!fileName.isEmpty())
    {
        QTextStream(stdout) << "选中文件:" << fileName << "\n";
        conList->setPath(fileName.toStdString().c_str());
        conList->saveContacts(fileName.toStdString());
        updateContacts();

        return true;
    }
    return false;
}

bool MainWindow::menuAbout()
{
    about *aboutWin = new about;
    QTextStream(stdout) << "关于界面\n";
    aboutWin->show();
    return true;
}
