#-------------------------------------------------
#
# Project created by QtCreator 2016-02-04T16:27:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

DESTDIR = $$PWD


SOURCES += main.cpp\
    qsfmlcanvas.cpp

HEADERS  += \
    qsfmlcanvas.h

#FORMS    +=

INCLUDEPATH += 'C:/SFML 2.3.2 Qt/include'
LIBS += -L'C:/SFML 2.3.2 Qt/lib'

LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
