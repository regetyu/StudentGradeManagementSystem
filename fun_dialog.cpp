#include "fun_dialog.h"
#include "ui_fun_dialog.h"

fun_Dialog::fun_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fun_Dialog)
{
    ui->setupUi(this);
    setFixedSize(800,600);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮
}

fun_Dialog::~fun_Dialog()
{
    delete ui;
}



void fun_Dialog::on_stu_grade_list_clicked()
{
    stu_gra_Dialog dialog(this);
    dialog.exec();
}

void fun_Dialog::on_cou_grade_list_clicked()
{
    cou_gra_Dialog dialog(this);
    dialog.exec();
}

void fun_Dialog::on_gpa_clicked()
{
    gpa_Dialog dialog(this);
    dialog.exec();
}
