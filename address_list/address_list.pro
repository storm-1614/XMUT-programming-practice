QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    addnewcontacts.cpp \
    contacts.cpp \
    contactslist.cpp \
    csv_file.cpp \
    date.cpp \
    main.cpp \
    mainwindow.cpp \
    search.cpp \
    searchbyname.cpp \
    searchbynumber.cpp \
    statistics.cpp

HEADERS += \
    about.h \
    addnewcontacts.h \
    contacts.h \
    contactslist.h \
    csv_file.h \
    date.h \
    mainwindow.h \
    search.h \
    searchbyname.h \
    searchbynumber.h \
    statistics.h

FORMS += \
    about.ui \
    addnewcontacts.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
