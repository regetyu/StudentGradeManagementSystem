#include "read_grade_dialog.h"
#include "ui_read_grade_dialog.h"

read_grade_Dialog::read_grade_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::read_grade_Dialog)
{
    ui->setupUi(this);
    setFixedSize(700,500);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮

    //用正则表达式限制输入格式
    QRegExp regx("[0-9]+$");  //数字
    QValidator *validator = new QRegExpValidator(regx, ui->student);
    ui->student->setValidator(validator);
    validator = new QRegExpValidator(regx, ui->course);
    ui->course->setValidator(validator);

    setTabOrder(ui->student, ui->course);
    setTabOrder(ui->course, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->student);
    connect(this, SIGNAL(delete_grade_signal(QString,QString)), &obj, SLOT(delete_grade(QString,QString)));
    connect(this, SIGNAL(change_grade_signal(Grade)), &obj, SLOT(change_grade(Grade)));
}

read_grade_Dialog::~read_grade_Dialog()
{
    delete ui;
}

QString read_grade_Dialog::get_stu_num()
{
    return(ui->student->text());
}

QString read_grade_Dialog::get_cou_num()
{
    return(ui->course->text());
}


QString read_grade_Dialog::get_score()
{
    return(QString::number(ui->score->value()));
}


void read_grade_Dialog::on_initialize_clicked()
{
    QString str;
    ui->student->setEnabled(true);
    ui->student->setText(str);
    ui->course->setEnabled(true);
    ui->course->setText(str);
    ui->score->setEnabled(false);
    ui->score->setValue(0);
    ui->_delete->setEnabled(false);
    ui->change->setEnabled(false);
    ui->save->setEnabled(false);
    ui->read->setEnabled(true);
    setTabOrder(ui->student, ui->course);
    setTabOrder(ui->course, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->student);
}

void read_grade_Dialog::on_read_clicked()
{
    if(!(obj.repeat(Grade(get_stu_num(),get_cou_num()))))
    {   //如果成绩信息不存在
        QMessageBox box(QMessageBox:: Critical,"错误!", "成绩不存在!",QMessageBox::Ok,this);
        box.exec();
    }
    else
    {
        QMessageBox box(QMessageBox:: Information,"成功!", "若要修改或删除, 请点击相应的按键!",QMessageBox::Ok,this);
        box.exec();
        ui->student->setEnabled(false);
        ui->course->setEnabled(false);
        ui->score->setEnabled(false);
        ui->_delete->setEnabled(true);
        ui->change->setEnabled(true);
        ui->read->setEnabled(false);
        setTabOrder(ui->_delete, ui->change);
        setTabOrder(ui->change, ui->initialize);
        setTabOrder(ui->initialize, ui->cancel);
        setTabOrder(ui->cancel, ui->_delete);
        Grade grade=obj.find_grade(get_stu_num(), get_cou_num());
        ui->score->setValue(grade.get_score().toInt());
    }
}

void read_grade_Dialog::on__delete_clicked()
{
    QMessageBox box(QMessageBox:: Warning,"警告!", "删除不可逆, 是否继续?",QMessageBox::Yes| QMessageBox::No,this);
    if(box.exec()==QMessageBox::Yes)
    {
        emit delete_grade_signal(get_stu_num(), get_cou_num());
        QMessageBox box2(QMessageBox:: Information,"成功!", "删除成绩信息成功!",QMessageBox::Ok,this);
        box2.exec();
        emit ui->initialize->clicked();
    }
    else
        return;
}

void read_grade_Dialog::on_change_clicked()
{
    ui->score->setEnabled(true);
    ui->_delete->setEnabled(false);
    ui->change->setEnabled(false);
    ui->save->setEnabled(true);
    setTabOrder(ui->score, ui->save);
    setTabOrder(ui->save, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->score);
}

void read_grade_Dialog::on_save_clicked()
{
    Grade grade(obj.find_student(get_stu_num()), obj.find_course(get_cou_num()), get_score());
    emit change_grade_signal(grade);
    QMessageBox box2(QMessageBox:: Information,"成功!", "修改成绩成功!",QMessageBox::Ok,this);
    box2.exec();
    ui->student->setEnabled(true);
    ui->course->setEnabled(true);
    ui->score->setEnabled(false);
    ui->save->setEnabled(false);
    ui->read->setEnabled(true);
    setTabOrder(ui->student, ui->course);
    setTabOrder(ui->course, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->student);
}
