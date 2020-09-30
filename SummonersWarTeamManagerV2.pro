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
    monsterlistview.cpp \
    profile.cpp \
    team.cpp \
    teamlistview.cpp \
    teammanager.cpp \
    teammenu.cpp

HEADERS += \
    areamenu.h \
    boxmenu.h \
    mainmenu.h \
    monster.h \
    monsterlistview.h \
    profile.h \
    team.h \
    teamlistview.h \
    teammanager.h \
    teammenu.h

FORMS += \
    areamenu.ui \
    boxmenu.ui \
    mainmenu.ui \
    monsterlistview.ui \
    teamlistview.ui \
    teammanager.ui \
    teammenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
