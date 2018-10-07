#include "stu_dialog.h"
#include "ui_stu_dialog.h"

stu_Dialog::stu_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stu_Dialog)
{
    ui->setupUi(this);
    setFixedSize(800,500);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮
    connect(this,SIGNAL(add_student_signal(QString,QString,QString,QString,QString,QString)),&obj,SLOT(add_student(QString,QString,QString,QString,QString,QString)));
}

stu_Dialog::~stu_Dialog()
{
    delete ui;
}

void stu_Dialog::on_add_clicked()
{
    add_student_Dialog dialog(this);
    if(dialog.exec()==QDialog::Accepted)
    {
        if(dialog.get_student_num().isEmpty()||dialog.get_student_name().isEmpty()||dialog.get_major().isEmpty()||dialog.get_teach_class().isEmpty())
        {   //如果还有信息没填
            QMessageBox box(QMessageBox::Critical, "错误!", "信息不完整!\n重新录入?", QMessageBox::Yes| QMessageBox::No);
            if(box.exec()==QMessageBox::Yes)
            {  //重新输入
               emit ui->add->clicked();
            }
            else
                return;
        }
    else if(obj.repeat(Student(dialog.get_student_num(), dialog.get_student_name(), dialog.get_student_sex(), dialog.get_major(), dialog.get_year(), dialog.get_teach_class())))
        {   //如果已经存在相同学号的学生
            QMessageBox box(QMessageBox:: Critical,"错误!", "该学号的学生已经存在!\n重新录入?",QMessageBox::Yes| QMessageBox::No);
            if(box.exec()==QMessageBox::Yes)
            {   //再次输入
                emit ui->add->clicked();
            }
            else
                return;
            }
        else
        {   //添加学生信息
            emit add_student_signal(dialog.get_student_num(), dialog.get_student_name(), dialog.get_student_sex(), dialog.get_major(), dialog.get_year(), dialog.get_teach_class());
            QMessageBox box(QMessageBox::Information, "成功!", "录入学生信息成功!\n再次录入?", QMessageBox::Yes| QMessageBox::No);
            if(box.exec()==QMessageBox::Yes)
            {   //再次添加
                emit ui->add->clicked();
            }
            else
                return;
        }
    }
}


void stu_Dialog::on_read_clicked()
{
    read_student_Dialog dialog(this);
    dialog.exec();
}
