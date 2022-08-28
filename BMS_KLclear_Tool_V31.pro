#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T10:30:29
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#CONFIG += webkit2

TARGET = BMS_KLclear_Tool_V31
TEMPLATE = app

RC_ICONS = animal_bird_twitter_72px.ico

#LIBS += -LC:/Qt/Qt5.5.1/5.5/msvc2013/lib -lqwt
#INCLUDEPATH += C:/Qt/Qt5.5.1/5.5/msvc2013/include/Qwt
#include (F:/QT/Qwt/qwt.prf)

#编译加速选项
PRECOMPILED_HEADER = $$PWD/Core/Public.h    #头文件作为编译预处理文件
QMAKE_CXXFLAGS += /MP                       #并行编译

SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    ui_class/open_can_ui.cpp \
    Core/Communicate.cpp \
    Core/Public.cpp \
    ui_class/bmumaintabwidget.cpp \
    ui_class/generaltab.cpp \
    ui_class/bsusettab.cpp \
    ui_class/sysinfotab.cpp \
    ui_class/specifyparatab.cpp \
    ui_class/maintainparatab.cpp \
    ui_class/chargeparatab.cpp \
    ui_class/advancedparatab.cpp \
    ui_class/calibrationparatab.cpp \
    ui_class/toolmodeltab.cpp \
    ui_class/mainsider.cpp \
    ui_class/batsub.cpp \
    Core/EchartTest.cpp \
    ui_class/modifypara.cpp \
    ui_class/canitemstree.cpp \
    ui_class/bsumaintabwidget.cpp \
    ui_class/bsupidtabwidget.cpp \
    ui_class/bsuvidtabwidget.cpp \
    ui_class/bsubroadcast.cpp \
    ui_class/bsuvidfrombmu.cpp \
    ui_class/bsucellfrombmu.cpp \
    ui_class/bsupidfrombsu.cpp \
    ui_class/bsupidfromchannel.cpp \
    ui_class/bsupidfromcopper.cpp \
    ui_class/datalogset.cpp \
    ui_class/alarmhistory.cpp \
    ui_class/alarmactive.cpp \
    ui_class/alarmset.cpp \
    ui_class/bsuaddrmodify.cpp \
    HexEdit/HexEdit.cpp \
    HexEdit/optionsdialog.cpp \
    HexEdit/searchdialog.cpp \
    HexEdit/src/chunks.cpp \
    HexEdit/src/commands.cpp \
    HexEdit/src/qhexedit.cpp \
    Core/QRoundProgressBar.cpp \
    ChartDirector/qchartviewer.cpp \
    ChartDirector/usercharts.cpp \
    ChartDirector/realtimetrack.cpp \
    ChartDirector/roundmeterreadout.cpp \
    ChartDirector/userplot.cpp \
    ChartDirector/adddatadialog.cpp \
    ChartDirector/setvaluedialog.cpp \
    ui_class/btsmaintabwidget.cpp \
    ui_class/btsbroadcast.cpp \
    Tools/alarmsuspendwidget.cpp \
    Tools/ToolPushButton.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    ui_class/open_can_ui.h \
    CAN/IKlCanBase.h \
    CAN/IKlCanServe.h \
    CAN/klCanFactory.h \
    Core/Communicate.h \
    Core/Public.h \
    ui_class/bmumaintabwidget.h \
    ui_class/generaltab.h \
    ui_class/bsusettab.h \
    ui_class/sysinfotab.h \
    ui_class/specifyparatab.h \
    ui_class/maintainparatab.h \
    ui_class/chargeparatab.h \
    ui_class/advancedparatab.h \
    ui_class/calibrationparatab.h \
    ui_class/toolmodeltab.h \
    ui_class/mainsider.h \
    ui_class/batsub.h \
    Core/EchartTest.h \
    ui_class/modifypara.h \
    ui_class/canitemstree.h \
    ui_class/bsumaintabwidget.h \
    ui_class/bsupidtabwidget.h \
    ui_class/bsuvidtabwidget.h \
    ui_class/bsubroadcast.h \
    ui_class/bsuvidfrombmu.h \
    ui_class/bsucellfrombmu.h \
    ui_class/bsupidfrombsu.h \
    ui_class/bsupidfromchannel.h \
    ui_class/bsupidfromcopper.h \
    ui_class/datalogset.h \
    ui_class/alarmhistory.h \
    ui_class/alarmactive.h \
    ui_class/alarmset.h \
    ui_class/bsuaddrmodify.h \
    HexEdit/HexEdit.h \
    HexEdit/optionsdialog.h \
    HexEdit/searchdialog.h \
    HexEdit/src/chunks.h \
    HexEdit/src/commands.h \
    HexEdit/src/qhexedit.h \
    Core/QRoundProgressBar.h \
    ChartDirector/qchartviewer.h \
    ChartDirector/usercharts.h \
    ChartDirector/qchartcolour.h \
    ChartDirector/realtimetrack.h \
    ChartDirector/roundmeterreadout.h \
    ChartDirector/userplot.h \
    ChartDirector/adddatadialog.h \
    ChartDirector/setvaluedialog.h \
    ui_class/btsmaintabwidget.h \
    ui_class/btsbroadcast.h \
    Tools/alarmsuspendwidget.h \
    Tools/ToolPushButton.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    ui_class/open_can_ui.ui \
    ui_class/bmumaintabwidget.ui \
    ui_class/generaltab.ui \
    ui_class/bsusettab.ui \
    ui_class/sysinfotab.ui \
    ui_class/specifyparatab.ui \
    ui_class/maintainparatab.ui \
    ui_class/chargeparatab.ui \
    ui_class/advancedparatab.ui \
    ui_class/calibrationparatab.ui \
    ui_class/toolmodeltab.ui \
    ui_class/mainsider.ui \
    ui_class/batsub.ui \
    ui_class/modifypara.ui \
    ui_class/canitemstree.ui \
    ui_class/bsumaintabwidget.ui \
    ui_class/bsupidtabwidget.ui \
    ui_class/bsuvidtabwidget.ui \
    ui_class/bsubroadcast.ui \
    ui_class/bsuvidfrombmu.ui \
    ui_class/bsucellfrombmu.ui \
    ui_class/bsupidfrombsu.ui \
    ui_class/bsupidfromchannel.ui \
    ui_class/bsupidfromcopper.ui \
    ui_class/datalogset.ui \
    ui_class/alarmhistory.ui \
    ui_class/alarmactive.ui \
    ui_class/alarmset.ui \
    ui_class/bsuaddrmodify.ui \
    HexEdit/optionsdialog.ui \
    HexEdit/searchdialog.ui \
    ChartDirector/adddatadialog.ui \
    ChartDirector/setvaluedialog.ui \
    ui_class/btsmaintabwidget.ui \
    ui_class/btsbroadcast.ui \
    Tools/alarmsuspendwidget.ui

LIBS += -L$$PWD/CAN/ -lcan_interface

INCLUDEPATH += $$PWD/ChartDirector/X86/include \
                $$PWD/ChartDirector \
                $$PWD/Tools

LIBS += -L$$PWD/ChartDirector/X86/lib -lchartdir60 \
        -LC:/Qt/Qt5.5.1/5.5/msvc2013_static_x86/icu-56.1-vs2013/lib \
        -LC:/Qt/Qt5.5.1/5.5/msvc2013_static_x86/openssl-1.0.2h/out32 -lssleay32 \
        -LC:/Qt/Qt5.5.1/5.5/msvc2013_static_x86/lib -lQt5MultimediaWidgets \

INCLUDEPATH += ./ChartDirector/ \
    ./ChartDirector/X86/include

DISTFILES += \
    BMS_Center/Image/SOC/空.png \
    BMS_Center/Image/SOC/满.png \
    BMS_Center/Image/SOC/五分之二.png \
    BMS_Center/Image/SOC/五分之三.png \
    BMS_Center/Image/SOC/五分之四.png \
    BMS_Center/Image/SOC/五分之一(红).png \
    BMS_Center/Image/SOC/五分之一.png \
    版本更新说明.txt \
    animal_bird_twitter_72px.ico

RESOURCES += \
    HexEdit/qhexedit.qrc \
    ChartDirector/chartdirector.qrc \
    main.qrc

#CODECFORTR = GB2312
#CODECFORTR = UTF-8 #or gbk
#CODECFORSRC = GB2312
#DEFAULTCODEC = utf-8
#CODEC = utf-8

TRANSLATIONS += \
    HexEdit/translations/qhexedit_cs.ts \
    HexEdit/translations/qhexedit_de.ts \
    HexEdit/translations/qhexedit_zh_CN.ts \
    translations/qhexedit_zh_CN.ts \
    translations/qhexedit_en_US.ts

win32 { #support xp
QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01

DEFINES += _ATL_XP_TARGETING
QMAKE_CFLAGS += /D _USING_V110_SDK71
QMAKE_CXXFLAGS += /D _USING_V110_SDK71
LIBS *= -L"%ProgramFiles(x86)%/Microsoft SDKs/Windows/7.1A/Lib"
INCLUDEPATH += "%ProgramFiles(x86)%/Microsoft SDKs/Windows/7.1A/Include"
}

#win32:CONFIG += console
