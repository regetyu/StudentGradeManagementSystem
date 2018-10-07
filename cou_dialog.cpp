#include "cou_dialog.h"
#include "ui_cou_dialog.h"

cou_Dialog::cou_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cou_Dialog)
{
    ui->setupUi(this);
    setFixedSize(800,500);  //设置固定窗口的大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮
    connect(this,SIGNAL(add_course_signal(QString,QString,QString,QString,QString)),&obj,SLOT(add_course(QString,QString,QString,QString,QString)));
}

cou_Dialog::~cou_Dialog()
{
    delete ui;
}

void cou_Dialog::on_add_clicked()
{
    add_course_Dialog dialog(this);
    if(dialog.exec()==QDialog::Accepted)
    {
        if(dialog.get_course_num().isEmpty()||dialog.get_course_name().isEmpty())
        {   //如果有信息没填
            QMessageBox box(QMessageBox::Critical, "错误!", "信息不完整!\n重新录入?", QMessageBox::Yes| QMessageBox::No);
            if(box.exec()==QMessageBox::Yes)
            {   //重新输入
                emit ui->add->clicked();
            }
        else
            return;
        }
    if(obj.repeat(Course(dialog.get_course_num(), dialog.get_course_name(), dialog.get_course_credit(), dialog.get_course_year(), dialog.get_course_season())))
    {   //如果存在相同课程号的课程
        QMessageBox box(QMessageBox:: Critical,"错误!", "该课程号的课程已经存在!\n重新录入?",QMessageBox::Yes| QMessageBox::No);
        if(box.exec()==QMessageBox::Yes)
        {   //重新输入
            emit ui->add->clicked();
        }
        else
            return;
    }
    else
    {   //添加课程信息
        emit add_course_signal(dialog.get_course_num(), dialog.get_course_name(), dialog.get_course_credit(), dialog.get_course_year(), dialog.get_course_season());
        QMessageBox box(QMessageBox::Information, "成功!", "录入课程信息成功!\n再次录入?", QMessageBox::Yes| QMessageBox::No);
        if(box.exec()==QMessageBox::Yes)
        {   //再次录入
            emit ui->add->clicked();
        }
        else
            return;
    }
  }
}


void cou_Dialog::on_read_clicked()
{
    read_course_Dialog dialog(this);
    dialog.exec();
}
