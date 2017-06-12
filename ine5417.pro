#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T08:41:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ine5417
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/include

SOURCES += src/item-manager/item-manager.cpp \
    src/item-manager/item.cpp \
    src/item-manager/month.cpp \
    src/view/items-widget.cpp \
    src/view/main-window.cpp \
    src/view/stats-window.cpp \
    src/main.cpp \
    src/view/login-window.cpp \
    src/mappers/item-mapper.cpp \
    src/mappers/user-mapper.cpp

HEADERS += include/item-manager.h \
    include/item-mapper.h \
    include/item.h \
    include/items-widget.h \
    include/main-window.h \
    include/month.h \
    include/stats-window.h \
    include/login-window.h \
    include/user-mapper.h

FORMS += forms/mainwindow.ui \
    forms/statswindow.ui \
    forms/loginwindow.ui

SUBDIRS += \
    ine5417.pro
