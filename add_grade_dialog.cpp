#include "add_grade_dialog.h"
#include "ui_add_grade_dialog.h"

add_grade_Dialog::add_grade_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_grade_Dialog)
{
    ui->setupUi(this);
    setFixedSize(735, 545);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮
    //用正则表达式限制用户的输入格式
    QRegExp regx("[0-9]+$");  //数字
    QValidator *validator = new QRegExpValidator(regx, ui->student);
    ui->student->setValidator(validator);
    validator = new QRegExpValidator(regx, ui->course);
    ui->course->setValidator(validator);

    setTabOrder(ui->student, ui->course);
    setTabOrder(ui->course, ui->score);
    setTabOrder(ui->score, ui->buttonBox);
    setTabOrder(ui->buttonBox, ui->student);
}

add_grade_Dialog::~add_grade_Dialog()
{
    delete ui;
}

QString add_grade_Dialog::get_stu_num()
{
    return(ui->student->text());
}

QString add_grade_Dialog::get_cou_num()
{
    return(ui->course->text());
}


QString add_grade_Dialog::get_score()
{
    return(QString::number(ui->score->value()));
}
