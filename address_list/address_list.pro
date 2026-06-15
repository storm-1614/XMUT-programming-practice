QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contacts.cpp \
    contactslist.cpp \
    date.cpp \
    main.cpp \
    mainwindow.cpp \
    search.cpp \
    searchbyname.cpp \
    searchbynumber.cpp \
    statistics.cpp

HEADERS += \
    contacts.h \
    contactslist.h \
    date.h \
    main.h \
    mainwindow.h \
    search.h \
    searchbyname.h \
    searchbynumber.h \
    statistics.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
