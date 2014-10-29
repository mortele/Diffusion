TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    PDESolver.cpp \
    Algorithms/Algorithm.cpp \
    Algorithms/Explicit.cpp \
    Algorithms/Implicit.cpp \
    Algorithms/CrankNicolson.cpp \
    ClosedForm.cpp

HEADERS += \
    PDESolver.h \
    Algorithms/Algorithm.h \
    Algorithms/Explicit.h \
    Algorithms/Implicit.h \
    Algorithms/CrankNicolson.h \
    ClosedForm.h

