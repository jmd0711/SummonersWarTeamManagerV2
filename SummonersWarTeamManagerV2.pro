QT       += \
    core \
    gui \
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    areamenu.cpp \
    boxmenu.cpp \
    main.cpp \
    mainmenu.cpp \
    monster.cpp \
    monsterdisplay.cpp \
    monsterlistview.cpp \
    monsterrequest.cpp \
    profile.cpp \
    team.cpp \
    teamdisplay.cpp \
    teamlistview.cpp \
    teammanager.cpp \
    teammenu.cpp \
    teamwidget.cpp

HEADERS += \
    areamenu.h \
    boxmenu.h \
    mainmenu.h \
    monster.h \
    monsterdisplay.h \
    monsterlistview.h \
    monsterrequest.h \
    profile.h \
    team.h \
    teamdisplay.h \
    teamlistview.h \
    teammanager.h \
    teammenu.h \
    teamwidget.h

FORMS += \
    areamenu.ui \
    boxmenu.ui \
    mainmenu.ui \
    monsterdisplay.ui \
    monsterlistview.ui \
    monsterrequest.ui \
    teamdisplay.ui \
    teamlistview.ui \
    teammanager.ui \
    teammenu.ui \
    teamwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
