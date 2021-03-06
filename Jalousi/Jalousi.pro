TEMPLATE = app

QT += qml quick widgets core gui declarative androidextras bluetooth

TARGET = Jalousi

SOURCES += main.cpp \
    alarm.cpp \
    jalousi.cpp \
    androidrfcomm.cpp \
    massagebox.cpp

RESOURCES += \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    alarm.h \
    settings.h \
    jalousi.h \
    androidrfcomm.h \
    massagebox.h

DISTFILES +=

CONFIG += mobility

MOBILITY =

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += android/AndroidManifest.xml
