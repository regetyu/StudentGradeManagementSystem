#include "read_course_dialog.h"
#include "ui_read_course_dialog.h"

read_course_Dialog::read_course_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::read_course_Dialog)
{
    ui->setupUi(this);
    setFixedSize(800,500);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮

    //用正则表达式限制输入格式
    QRegExp regx("[0-9]+$");  //数字
    QRegExp regx1("\\S+$");   //无空格
    QValidator *validator = new QRegExpValidator(regx, ui->num );
    ui->num->setValidator(validator);
    validator = new QRegExpValidator(regx1, ui->name );
    ui->name->setValidator(validator);

    setTabOrder(ui->num, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->num);
    connect(this, SIGNAL(delete_course_signal(QString)), &obj, SLOT(delete_course(QString)));
    connect(this, SIGNAL(change_course_signal(Course)), &obj, SLOT(change_course(Course)));
}

read_course_Dialog::~read_course_Dialog()
{
    delete ui;
}


QString read_course_Dialog::get_course_num()
{
    return(ui->num->text());
}

QString read_course_Dialog::get_course_name()
{
    return(ui->name->text());
}

QString read_course_Dialog::get_course_credit()
{
    return(QString::number(ui->credit->value()));
}

QString read_course_Dialog::get_course_year()
{
    return(QString::number(ui->year->value()));
}

QString read_course_Dialog::get_course_season()
{
    return(ui->season->currentText());
}


void read_course_Dialog::on_initialize_clicked()
{
    QString str;
    ui->num->setEnabled(true);
    ui->num->setText(str);
    ui->name->setEnabled(false);
    ui->name->setText(str);
    ui->credit->setEnabled(false);
    ui->credit->setValue(0);
    ui->year->setEnabled(false);
    ui->year->setValue(2017);
    ui->season->setEnabled(false);
    ui->season->setCurrentIndex(0);
    ui->_delete->setEnabled(false);
    ui->change->setEnabled(false);
    ui->save->setEnabled(false);
    ui->read->setEnabled(true);
    setTabOrder(ui->num, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->num);
}

void read_course_Dialog::on_read_clicked()
{
    if(!(obj.repeat(Course(get_course_num()))))
    {   //如果不存在该课程号的课程
        QMessageBox box(QMessageBox:: Critical,"错误!", "不存在这个课程号的课程!",QMessageBox::Ok,this);
        box.exec();
    }
    else
    {
        QMessageBox box(QMessageBox:: Information,"成功!", "若要修改或删除, 请点击相应的按键!",QMessageBox::Ok,this);
        box.exec();
        ui->num->setEnabled(false);
        ui->_delete->setEnabled(true);
        ui->change->setEnabled(true);
        ui->read->setEnabled(false);
        setTabOrder(ui->_delete, ui->change);
        setTabOrder(ui->change, ui->initialize);
        setTabOrder(ui->initialize, ui->cancel);
        setTabOrder(ui->cancel, ui->_delete);
        Course course=obj.find_course(get_course_num());
        ui->name->setText(course.get_cou_name());
        ui->credit->setValue(course.get_cou_credit().toInt());
        ui->year->setValue((course.get_cou_year().toInt()));
        ui->season->setCurrentText(course.get_cou_season());
    }
}

void read_course_Dialog::on__delete_clicked()
{
    QMessageBox box(QMessageBox:: Warning,"警告!", "若删除该课程的信息, 其相应的成绩信息也会被删除, 该操作不可逆, 是否继续?",QMessageBox::Yes| QMessageBox::No,this);
    if(box.exec()==QMessageBox::Yes)
    {
        emit delete_course_signal(get_course_num());
        QMessageBox box2(QMessageBox:: Information,"成功!", "删除课程信息成功!",QMessageBox::Ok,this);
        box2.exec();
        emit ui->initialize->clicked();
    }
    else
        return;
}

void read_course_Dialog::on_change_clicked()
{
    ui->name->setEnabled(true);
    ui->credit->setEnabled(true);
    ui->year->setEnabled(true);
    ui->season->setEnabled(true);
    ui->_delete->setEnabled(false);
    ui->change->setEnabled(false);
    ui->save->setEnabled(true);
    setTabOrder(ui->name, ui->credit);
    setTabOrder(ui->credit, ui->year);
    setTabOrder(ui->year, ui->season);
    setTabOrder(ui->season, ui->save);
    setTabOrder(ui->save, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->name);
}


void read_course_Dialog::on_save_clicked()
{
    if(get_course_num().isEmpty()||get_course_name().isEmpty())
    {   //如果有信息没填
        QMessageBox box(QMessageBox::Critical, "错误!", "信息不完整!", QMessageBox::Ok);
        box.exec();
    }
    else
    {
        emit change_course_signal(Course(get_course_num(), get_course_name(), get_course_credit(), get_course_year(), get_course_season()));
        QMessageBox box2(QMessageBox:: Information,"成功!", "修改课程信息成功!",QMessageBox::Ok,this);
        box2.exec();
        ui->name->setEnabled(false);
        ui->credit->setEnabled(false);
        ui->year->setEnabled(false);
        ui->season->setEnabled(false);
        ui->_delete->setEnabled(true);
        ui->change->setEnabled(true);
        ui->save->setEnabled(false);
        setTabOrder(ui->_delete, ui->change);
        setTabOrder(ui->change, ui->initialize);
        setTabOrder(ui->initialize, ui->cancel);
        setTabOrder(ui->cancel, ui->_delete);
    }
}
