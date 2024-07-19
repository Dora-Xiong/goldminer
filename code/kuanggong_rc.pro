#-------------------------------------------------
#
# Project created by QtCreator 2014-12-28T14:05:53
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kuanggong_rc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Item.cpp \
    map.cpp \
    miner.cpp \
    shop.cpp

HEADERS  += mainwindow.h \
    miner.h \
    item.h \
    map.h \
    shop.h

FORMS    += mainwindow.ui \
    shop.ui

RESOURCES += \
bgm.qrc \
image.qrc \
newimage.qrc \
shop_image.qrc
RC_FILE = myicon.rc
