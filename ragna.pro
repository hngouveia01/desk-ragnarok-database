#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T11:39:15
#
#-------------------------------------------------

QT       += core gui sql
QT_DEBUG_PLUGINS=1
DEFINES += QT_DEBUG_PLUGINS=1

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ragna
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


SOURCES += main.cpp\
        database.cpp \
        dbexception.cpp \
        element.cpp \
        mainwindow.cpp \
        monsterdao.cpp

HEADERS  += mainwindow.h \
    dao.h \
    database.h \
    dbexception.h \
    element.h \
    monsterdao.h

FORMS    += mainwindow.ui
