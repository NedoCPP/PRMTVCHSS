TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt
CONFIG += console
CONFIG += c++14
SOURCES += main.cpp \
    knightchess.cpp \
    pawnchess.cpp \
    boardchess.cpp \
    bishopchess.cpp
QMAKE_CXXFLAGS += -std=c++14
CONFIG += c++14

HEADERS += \
    knightchess.h \
    pawnchess.h \
    basechess.h \
    boardchess.h \
    bishopchess.h

