QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alchemylab.cpp \
    bigcookie.cpp \
    clicker.cpp \
    factory.cpp \
    grandma.cpp \
    info.cpp \
    main.cpp \
    cookieclicker.cpp \
    mine.cpp \
    portal.cpp \
    producer.cpp \
    shipment.cpp \
    timemachine.cpp

HEADERS += \
    alchemylab.h \
    bigcookie.h \
    clicker.h \
    cookieclicker.h \
    factory.h \
    grandma.h \
    info.h \
    mine.h \
    portal.h \
    producer.h \
    shipment.h \
    timemachine.h

FORMS += \
    cookieclicker.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Assets.qrc
