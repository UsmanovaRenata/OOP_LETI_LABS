QT -= gui
QT += network

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../common/common.cpp \
        ../common/communicator.cpp \
        application.cpp \
        main.cpp \
        matrix.cpp \
        rational.cpp

TRANSLATIONS += \
    server_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

INCLUDEPATH += ../common

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../common/common.h \
    ../common/communicator.h \
    application.h \
    matrix.h \
    number.h \
    rational.h