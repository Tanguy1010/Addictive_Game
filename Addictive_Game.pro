TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        main.cpp \
        manhattandistance.cpp \
        path.cpp \
        point.cpp \
        tools.cpp

HEADERS += \
    board.h \
    manhattandistance.h \
    path.h \
    point.h \
    tools.h
