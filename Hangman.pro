#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T13:42:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hangman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hangman.cpp

HEADERS  += mainwindow.h \
    hangman.h

FORMS    += mainwindow.ui

DISTFILES += \
    ../../Desktop/images/gallows0.png \
    ../../Desktop/images/gallows1.png \
    ../../Desktop/images/gallows2.png \
    ../../Desktop/images/gallows3.png \
    ../../Desktop/images/gallows4.png \
    ../../Desktop/images/gallows5.png \
    ../../Desktop/images/gallows6.png

RESOURCES += \
    images.qrc
