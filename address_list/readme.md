# 校园通讯录管理系统的设计与实现
XMUT 大一下程序设计实践必做题  

![](./res/mainwindow.png)

## 框架
采用 QT6 C++ 库。采用 QWidget  

## 代码结构
### main.cpp
启动窗口  

###  mainwindow
窗口交互逻辑  

``` cpp
extern contactsList conList;
```

全局变量对象  
#### `MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)`
窗口配置。连接槽。  

#### `MainWindow::~MainWindow()`
析构 MainWindow  

#### `bool MainWindow::addContacts()`
添加新的联系人，按下添加联系人按钮时运行该函数。  
#### `bool MainWindow::updateContacts()`
更新联系人列表。在 addContacts 函数最后执行该函数，更新联系人列表。  

#### `bool MainWindow::clearForm()`
清理表单，按下清空表单按钮的时候出发。  

#### `bool MainWindow::searchClicked()`
按下搜索按钮的时候触发。目前实现了按姓名搜索和按电话号码搜索，还有 bug，没完全实现。  

### date
日期类  
#### `const QString Date::text() const`
输出字符串。  
这两 const 真的是自己写的！！！  

### contacts
联系人类  
``` cpp
    QString id;
    QString name;
    QString phoneNumber;
    QString type;
    Date Birth;
    QString remarks;
```

目前就是 get 和 set 两种函数，所有数据都实现了一遍，确保封装性。  
### contactslist
联系人列表  

#### `bool contactsList::addNewContacts(Contacts ct)`
添加新的联系人  

#### `bool contactsList::removeContacts()`
还没实现！！！

#### `bool contactsList::modifyContacts()`
还没实现！！！


#### `const std::vector<Contacts>& contactsList::readContactList() const`

返回数据数组。  
### search
搜索基类  

### searchbyname
按姓名搜索子类  

### searchbynumber
按电话号码搜索子类  

### statistics
统计输出类  

## 进度
- [x] Contact 初始化
- [x] 添加联系人 toolBar 子窗口实现
- [ ] 搜索
