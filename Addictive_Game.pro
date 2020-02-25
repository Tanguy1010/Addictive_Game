TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        board.cpp \
        main.cpp \
        manhattandistance.cpp \
        path.cpp \
        point.cpp \
        tools.cpp \
        uiboard.cpp

HEADERS += \
    board.h \
    manhattandistance.h \
    path.h \
    point.h \
    tools.h \
    uiboard.h

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

FORMS += \
    uiboard.ui
