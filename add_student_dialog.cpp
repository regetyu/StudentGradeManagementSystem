#include "add_student_dialog.h"
#include "ui_add_student_dialog.h"

add_student_Dialog::add_student_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_student_Dialog)
{
    ui->setupUi(this);
    setFixedSize(660, 530);  //设置固定的窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮

    //通过正则表达式限制输入格式
    QRegExp regx("[0-9]+$");             //数字
    QRegExp regx1("[\u4e00-\u9fa5]+$");  //汉字
    QRegExp regx2("[\\S]+$");            //无空格
    QValidator *validator = new QRegExpValidator(regx, ui->num);
    ui->num->setValidator(validator);
    validator = new QRegExpValidator(regx1, ui->name);
    ui->name->setValidator(validator);
    validator = new QRegExpValidator(regx1, ui->major);
    ui->major->setValidator(validator);
    validator = new QRegExpValidator(regx2, ui->teach_class);
    ui->teach_class->setValidator(validator);

    setTabOrder(ui->num, ui->name);
    setTabOrder(ui->name, ui->male);
    setTabOrder(ui->male, ui->major);
    setTabOrder(ui->major, ui->year);
    setTabOrder(ui->year, ui->teach_class);
    setTabOrder(ui->year, ui->buttonBox);
    setTabOrder(ui->buttonBox, ui->num);
}

add_student_Dialog::~add_student_Dialog()
{
    delete ui;
}


QString add_student_Dialog::get_student_num()
{
    return(ui->num->text());
}

QString add_student_Dialog::get_student_name()
{
    return(ui->name->text());
}

QString add_student_Dialog::get_student_sex()
{
    if (ui->male->isChecked())
        return ui->male->text();
    else
        return ui->female->text();
}

QString add_student_Dialog::get_major()
{
    return(ui->major->text());
}

QString add_student_Dialog::get_year()
{
    return(QString::number(ui->year->value()));
}

QString add_student_Dialog::get_teach_class()
{
    return(ui->teach_class->text());
}
