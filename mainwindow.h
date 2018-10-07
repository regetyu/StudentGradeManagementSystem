#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QMessageBox>
#include "stu_dialog.h"
#include "cou_dialog.h"
#include "gra_dialog.h"
#include "fun_dialog.h"
#include "help_dialog.h"
#include "about_dialog.h"

//这是主窗口

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //构造函数
    explicit MainWindow(QWidget *parent = nullptr);

    //析构函数
    ~MainWindow();

private slots:
    //对学生信息操作的菜单
    void on_student_clicked();

    //对课程信息操作的菜单
    void on_course_clicked();

    //对成绩信息操作的菜单
    void on_grade_clicked();

    //高级功能菜单
    void on_advance_clicked();

    //打印学生成绩成绩单窗口
    void on_action_stu_gra_triggered();

    //打印课程所有学生成绩窗口
    void on_action_cou_gra_triggered();

    //查看学生平均学分绩和排名窗口
    void on_action_gpa_triggered();

    //添加学生信息窗口
    void on_action_add_student_triggered();

    //查看、修改、删除学生信息窗口
    void on_action_read_student_triggered();

    //添加课程信息窗口
    void on_action_add_course_triggered();

    //查看、修改、删除课程信息窗口
    void on_action_read_course_triggered();

    //添加成绩信息窗口
    void on_action_add_grade_triggered();

    //查看、修改、删除成绩信息窗口
    void on_action_read_grade_triggered();

    //帮助窗口
    void on_help_clicked();
    void on_action_help_triggered();

    //关于窗口
    void on_about_clicked();
    void on_action_about_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
