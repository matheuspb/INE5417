#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T08:41:00
#
#-------------------------------------------------

QT       += core gui

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

SOURCES += src/item-manager/item.cpp \
    src/item-manager/items.cpp \
    src/view/mainwidget.cpp \
    src/view/mainwindow.cpp \
    src/main.cpp

HEADERS  += include/item.h \
    include/items.h \
    include/mainwidget.h \
    include/mainwindow.h

FORMS    += src/view/mainwindow.ui
