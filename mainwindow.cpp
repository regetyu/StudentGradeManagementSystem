#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1000,1000);  //设置固定窗口大小
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_student_clicked()
{
    stu_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_course_clicked()
{
    cou_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_grade_clicked()
{
    gra_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_advance_clicked()
{
    fun_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_stu_gra_triggered()
{
    stu_gra_Dialog dialog (this);
    dialog.exec();
}

void MainWindow::on_action_cou_gra_triggered()
{
    cou_gra_Dialog dialog (this);
    dialog.exec();
}

void MainWindow::on_action_gpa_triggered()
{
    gpa_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_add_student_triggered()
{
    add_student_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_read_student_triggered()
{
    read_student_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_add_course_triggered()
{
    add_course_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_read_course_triggered()
{
    read_course_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_add_grade_triggered()
{
    add_grade_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_read_grade_triggered()
{
    read_grade_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_help_clicked()
{
    help_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_help_triggered()
{
    help_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_about_clicked()
{
    about_Dialog dialog(this);
    dialog.exec();
}

void MainWindow::on_action_about_triggered()
{
    about_Dialog dialog(this);
    dialog.exec();
}
