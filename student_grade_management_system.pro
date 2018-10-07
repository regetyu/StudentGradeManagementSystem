#-------------------------------------------------
#
# Project created by QtCreator 2018-07-25T20:42:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student_grade_management_system
TEMPLATE = app

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
        mainwindow.cpp \
    stu_dialog.cpp \
    cou_dialog.cpp \
    gra_dialog.cpp \
    fun_dialog.cpp \
    add_student_dialog.cpp \
    read_student_dialog.cpp \
    add_course_dialog.cpp \
    read_course_dialog.cpp \
    add_grade_dialog.cpp \
    read_grade_dialog.cpp \
    tclass.cpp \
    student.cpp \
    course.cpp \
    grade.cpp \
    object.cpp \
    stu_gra_dialog.cpp \
    cou_gra_dialog.cpp \
    gpa_dialog.cpp \
    help_dialog.cpp \
    about_dialog.cpp

HEADERS += \
        mainwindow.h \
    stu_dialog.h \
    cou_dialog.h \
    gra_dialog.h \
    fun_dialog.h \
    add_student_dialog.h \
    read_student_dialog.h \
    add_course_dialog.h \
    read_course_dialog.h \
    add_grade_dialog.h \
    read_grade_dialog.h \
    figure.h \
    tclass.h \
    student.h \
    course.h \
    grade.h \
    object.h \
    sync.h \
    stu_gra_dialog.h \
    cou_gra_dialog.h \
    gpa_dialog.h \
    help_dialog.h \
    about_dialog.h

FORMS += \
        mainwindow.ui \
    stu_dialog.ui \
    cou_dialog.ui \
    gra_dialog.ui \
    fun_dialog.ui \
    add_student_dialog.ui \
    read_student_dialog.ui \
    add_course_dialog.ui \
    read_course_dialog.ui \
    add_grade_dialog.ui \
    read_grade_dialog.ui \
    stu_gra_dialog.ui \
    cou_gra_dialog.ui \
    gpa_dialog.ui \
    help_dialog.ui \
    about_dialog.ui

RESOURCES +=
