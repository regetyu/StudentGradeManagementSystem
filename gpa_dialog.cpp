#include "gpa_dialog.h"
#include "ui_gpa_dialog.h"

gpa_Dialog::gpa_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gpa_Dialog)
{
    ui->setupUi(this);
    setFixedSize(700,550);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮

    //用正则表达式限制用户输入格式
    QRegExp regx("[0-9]+$");  //数字
    QValidator *validator = new QRegExpValidator(regx, ui->num);
    ui->num->setValidator(validator);
    setTabOrder(ui->num, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->num);
}

gpa_Dialog::~gpa_Dialog()
{
    delete ui;
}

QString gpa_Dialog::get_num()
{
    return(ui->num->text());
}

void gpa_Dialog::on_read_clicked()
{
    if(!(obj.repeat(Student(get_num()))))
    {
        QMessageBox box(QMessageBox:: Critical,"错误!", "不存在这个学号的学生!",QMessageBox::Ok,this);
        box.exec();
    }
    else
    {
        ui->num->setEnabled(false);
        ui->read->setEnabled(false);
        setTabOrder(ui->initialize, ui->cancel);
        setTabOrder(ui->cancel, ui->initialize);
        ui->gpa->setText(QString::number(obj.gpa(get_num())));
        ui->class_rank->setText(obj.class_rank(get_num()));
        ui->major_rank->setText(obj.major_rank(get_num()));
    }
}

void gpa_Dialog::on_initialize_clicked()
{
    ui->num->setEnabled(true);
    ui->num->clear();
    ui->gpa->clear();
    ui->class_rank->clear();
    ui->major_rank->clear();
    ui->read->setEnabled(true);
    setTabOrder(ui->num, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->num);
}
