TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    trie.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    trie.h

