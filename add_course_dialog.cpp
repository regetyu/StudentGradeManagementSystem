#include "add_course_dialog.h"
#include "ui_add_course_dialog.h"

add_course_Dialog::add_course_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_course_Dialog)
{
    ui->setupUi(this);
    setFixedSize(700, 600);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint); //去除"?"按钮

    //通过正则表达式限制输入格式
    QRegExp regx("[0-9]+$");  //数字
    QRegExp regx1("\\S+$");   //无空格
    QValidator *validator = new QRegExpValidator(regx, ui->num);
    ui->num->setValidator(validator);
    validator = new QRegExpValidator(regx1, ui->name);
    ui->name->setValidator(validator);

    setTabOrder(ui->num, ui->name);
    setTabOrder(ui->name, ui->credit);
    setTabOrder(ui->credit, ui->year);
    setTabOrder(ui->year, ui->season);
    setTabOrder(ui->season, ui->buttonBox);
    setTabOrder(ui->buttonBox, ui->num);
}

add_course_Dialog::~add_course_Dialog()
{
    delete ui;
}


QString add_course_Dialog::get_course_num()
{
    return(ui->num->text());
}

QString add_course_Dialog::get_course_name()
{
    return(ui->name->text());
}

QString add_course_Dialog::get_course_credit()
{
    return(QString::number(ui->credit->value()));
}

QString add_course_Dialog::get_course_year()
{
    return(QString::number(ui->year->value()));
}

QString add_course_Dialog::get_course_season()
{
    return(ui->season->currentText());
}
