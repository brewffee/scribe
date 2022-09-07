TEMPLATE = app
TARGET = scribe
INCLUDEPATH += . \
        classes/

# Input
HEADERS += menus_.h \
        populateMenus.h \
        classes/FakeModal.h \
        classes/MenuBar.h \
        classes/StatusBar.h \
        classes/TextEdit.h \
        classes/LineEdit.h \
        classes/PushButton.h \

SOURCES += scribe.cpp
QT += widgets 
QT += gui
