QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autoaddevent.cpp \
    calendar_data_manager.cpp \
    edit_calendar_dialog.cpp \
    form.cpp \
    googleoauth.cpp \
    job.cpp \
    jobscheduler.cpp \
    main.cpp \
    mainwindow.cpp \
    new_event_dialog.cpp \
    oauth2.cpp

HEADERS += \
    autoaddevent.h \
    calendar_data_manager.h \
    edit_calendar_dialog.h \
    form.h \
    googleoauth.h \
    googleoauth2wrapper.h \
    job.h \
    jobscheduler.h \
    mainwindow.h \
    new_event_dialog.h \
    oauth2.h

FORMS += \
    autoaddevent.ui \
    edit_calendar_dialog.ui \
    form.ui \
    googleoauth.ui \
    mainwindow.ui \
    new_event_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT += network networkauth

INCLUDEPATH += C:/Users/xiaoduo/WorkSpace/c-workspace/QtSpace/MyGoogleCalendar/include/qjson-qt5
#LIBS += "C:/Users/xiaoduo/WorkSpace/c-workspace/QtSpace/qt-google-calendar/lib/libqjson.dll.a"
LIBS += C:/Users/xiaoduo/WorkSpace/c-workspace/QtSpace/build-MyGoogleCalendar-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/debug/lib/libqjson-qt5.dll.a
LIBS += C:/Users/xiaoduo/WorkSpace/c-workspace/QtSpace/build-MyGoogleCalendar-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/debug/lib/libqjson-qt5.dll
#LIBS += C:/Users/xiaoduo/WorkSpace/c-workspace/QtSpace/qt-google-calendar-copy/release/lib/libqjson.dll.a
#LIBS += C:/Users/xiaoduo/WorkSpace/c-workspace/QtSpace/qt-google-calendar-copy/release/lib/libqjson.dll
