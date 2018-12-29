#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T22:40:15
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JournalAccountRecordSoftware
TEMPLATE = app
RC_FILE=icon.rc
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        main_window.cpp \
    form_creat_journal.cpp \
    form_creat_category.cpp \
    form_show_journal.cpp \
    form_show_category.cpp \
    form_remark.cpp \
    sql_manager.cpp \
    base_tool.cpp \
    titlebar.cpp

HEADERS += \
        main_window.h \
    form_creat_journal.h \
    form_creat_category.h \
    form_show_journal.h \
    form_show_category.h \
    form_remark.h \
    sql_manager.h \
    base_tool.h \
    titlebar.h \
    sql_instruction.h \
    system_config.h

FORMS += \
        main_window.ui \
    form_creat_journal.ui \
    form_creat_category.ui \
    form_show_journal.ui \
    form_show_category.ui \
    form_remark.ui

RESOURCES += \
    resource_file.qrc
