#-------------------------------------------------
#
# Project created by QtCreator 2017-12-18T20:47:36
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DiscreteEventSystemSimulation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    DialogSimulation.cpp \
    DumpTruck.cpp \
    LoadingQueue.cpp \
    Loader.cpp \
    WeighQueue.cpp \
    Queue.cpp \
    Scale.cpp \
    Event.cpp \
    FutureEventList.cpp \
    DataProvider.cpp \
    CumulativeStatistics.cpp \
    DialogCharts.cpp

HEADERS += \
        MainWindow.hpp \
    DialogSimulation.hpp \
    DumpTruck.hpp \
    LoadingQueue.hpp \
    Loader.hpp \
    WeighQueue.hpp \
    Queue.hpp \
    Scale.hpp \
    Event.hpp \
    FutureEventList.hpp \
    DataProvider.hpp \
    CumulativeStatistics.hpp \
    DialogCharts.hpp

FORMS += \
        MainWindow.ui \
    DialogSimulation.ui \
    DialogCharts.ui
