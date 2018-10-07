#include "gra_dialog.h"
#include "ui_gra_dialog.h"

gra_Dialog::gra_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gra_Dialog)
{
    ui->setupUi(this);
    setFixedSize(800, 500);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮
    connect(this,SIGNAL(add_grade_signal(QString,QString,QString)), &obj, SLOT(add_grade(QString,QString,QString)));
}

gra_Dialog::~gra_Dialog()
{
    delete ui;
}

void gra_Dialog::on_add_clicked()
{
    add_grade_Dialog dialog(this);
    if(dialog.exec()==QDialog::Accepted)
    {
        {
            if(dialog.get_stu_num().isEmpty()||dialog.get_cou_num().isEmpty())
            {   //如果还有信息没填
                QMessageBox box(QMessageBox:: Critical,"错误!", "信息不完整!\n重新录入?",QMessageBox::Yes| QMessageBox::No);
                if(box.exec()==QMessageBox::Yes)
                {   //再次输入
                    emit ui->add->clicked();
                }
                else
                    return;
            }
            else if(obj.repeat(Grade(Student(dialog.get_stu_num()),Course(dialog.get_cou_num()),dialog.get_score())))
            {   //如果成绩信息已经存在
                QMessageBox box(QMessageBox:: Critical,"错误!", "该成绩信息已经存在!\n重新录入?",QMessageBox::Yes| QMessageBox::No);
                if(box.exec()==QMessageBox::Yes)
                {   //再次输入
                    emit ui->add->clicked();
                }
                else
                    return;
            }
            else if(!(obj.repeat(Student(dialog.get_stu_num()))&&obj.repeat(Course(dialog.get_cou_num()))))
            {   //如果学生或课程信息不存在
                QMessageBox box(QMessageBox:: Critical,"错误!", "学生或课程信息不存在!\n重新录入?",QMessageBox::Yes| QMessageBox::No);
                if(box.exec()==QMessageBox::Yes)
                {   //再次输入
                    emit ui->add->clicked();
                }
                else
                    return;
            }
            else
            {   //添加成绩信息
                emit add_grade_signal(dialog.get_stu_num(), dialog.get_cou_num(), dialog.get_score());
                QMessageBox box(QMessageBox:: Information,"成功!", "录入成绩信息成功!\n再次录入?",QMessageBox::Yes| QMessageBox::No);
                if(box.exec()==QMessageBox::Yes)
                {   //再次添加
                    emit ui->add->clicked();
                }
                else
                    return;
            }
        }
    }
}


void gra_Dialog::on_read_clicked()
{
    read_grade_Dialog dialog(this);
    dialog.exec();
}
