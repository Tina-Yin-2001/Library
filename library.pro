QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book.cpp \
    bookstore.cpp \
    init.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    show_stuinfo.cpp \
    signin.cpp \
    student.cpp \
    studentstore.cpp \
    importstudent.cpp \
    show_stulist.cpp \
    utils.cpp \
    debug.cpp

HEADERS += \
    book.h \
    bookstore.h \
    init.h \
    login.h \
    mainwindow.h \
    show_stuinfo.h \
    signin.h \
    student.h \
    studentstore.h \
    importstudent.h \
    show_stulist.h \
    utils.h \
    debug.h

FORMS += \
    login.ui \
    mainwindow.ui \
    show_stuinfo.ui \
    signin.ui \
    importstudent.ui \
    show_stulist.ui \
    debug.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    student.dat
