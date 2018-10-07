#include "read_student_dialog.h"
#include "ui_read_student_dialog.h"

read_student_Dialog::read_student_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::read_student_Dialog)
{
    ui->setupUi(this);
    setFixedSize(800,600);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮

    //用正则表示限制输入格式
    QRegExp regx("[0-9]+$");            //数字
    QRegExp regx1("[\u4e00-\u9fa5]+$"); //汉字
    QRegExp regx2("[\\S]+$");           //无空格
    QValidator *validator = new QRegExpValidator(regx, ui->num );
    ui->num->setValidator(validator);
    validator=new QRegExpValidator(regx1, ui->name);
    ui->name->setValidator(validator);
    validator=new QRegExpValidator(regx1, ui->major);
    ui->major->setValidator(validator);
    validator=new QRegExpValidator(regx2, ui->teach_class);
    ui->teach_class->setValidator(validator);

    setTabOrder(ui->name, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->name);
    connect(this,SIGNAL(delete_student_signal(QString)), &obj, SLOT(delete_student(QString)));
    connect(this, SIGNAL(change_student_signal(Student)), &obj, SLOT(change_student(Student)));
}


QString read_student_Dialog::get_student_num()
{
    return(ui->num->text());
}

QString read_student_Dialog::get_student_name()
{
    return(ui->name->text());
}

QString read_student_Dialog::get_student_sex()
{
    if(ui->male->isChecked())
        return ui->male->text();
    else
        return ui->female->text();
}

QString read_student_Dialog::get_major()
{
    return(ui->major->text());
}

QString read_student_Dialog::get_year()
{
    return(QString::number(ui->year->value()));
}

QString read_student_Dialog::get_teach_class()
{
    return(ui->teach_class->text());
}



read_student_Dialog::~read_student_Dialog()
{
    delete ui;
}

void read_student_Dialog::on_initialize_clicked()
{
    ui->num->setEnabled(true);
    ui->num->clear();
    ui->name->setEnabled(false);
    ui->name->clear();
    ui->male->setEnabled(false);
    ui->male->setChecked(true);
    ui->female->setEnabled(false);
    ui->female->setChecked(false);
    ui->major->setEnabled(false);
    ui->major->clear();
    ui->year->setEnabled(false);
    ui->year->setValue(2017);
    ui->teach_class->setEnabled(false);
    ui->teach_class->clear();
    ui->_delete->setEnabled(false);
    ui->change->setEnabled(false);
    ui->save->setEnabled(false);
    ui->read->setEnabled(true);
    ui->initialize->setEnabled(true);
    ui->cancel->setEnabled(true);
    setTabOrder(ui->name, ui->read);
    setTabOrder(ui->read, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->name);
}

void read_student_Dialog::on_read_clicked()
{
    if(!(obj.repeat(Student(get_student_num()))))
    {   //如果不存在该学号的学生
        QMessageBox box(QMessageBox:: Critical,"错误!", "不存在这个学号的学生!",QMessageBox::Ok,this);
        box.exec();
    }
    else
    {
       QMessageBox box(QMessageBox:: Information,"成功!", "若要修改或删除, 请点击相应的按键!",QMessageBox::Ok,this);
       box.exec();
        ui->_delete->setEnabled(true);
        ui->change->setEnabled(true);
        ui->read->setEnabled(false);
        ui->num->setEnabled(false);
        setTabOrder(ui->_delete, ui->change);
        setTabOrder(ui->change, ui->save);
        setTabOrder(ui->save, ui->initialize);
        setTabOrder(ui->initialize, ui->cancel);
        setTabOrder(ui->cancel, ui->_delete);
        Student student=obj.find_student(get_student_num());
        ui->name->setText(student.get_stu_name());
        if(student.get_stu_sex()==ui->female->text())
        {
            ui->male->setChecked(false);
            ui->female->setChecked(true);
        }
        ui->major->setText(student.get_major());
        ui->year->setValue(student.get_year().toInt());
        ui->teach_class->setText(student.get_teach_class());
    }
}

void read_student_Dialog::on__delete_clicked()
{
    QMessageBox box(QMessageBox:: Warning,"警告!", "若删除该学生的信息, 其相应的成绩信息也会被删除, 该操作不可逆, 是否继续?",QMessageBox::Yes| QMessageBox::No,this);
    if(box.exec()==QMessageBox::Yes)
    {
        emit delete_student_signal(get_student_num());
        QMessageBox box2(QMessageBox:: Information,"成功!", "删除学生信息成功!",QMessageBox::Ok,this);
        box2.exec();
        emit ui->initialize->clicked();
    }
    else
        return;
}

void read_student_Dialog::on_change_clicked()
{
    ui->name->setEnabled(true);
    ui->male->setEnabled(true);
    ui->female->setEnabled(true);
    ui->major->setEnabled(true);
    ui->year->setEnabled(true);
    ui->teach_class->setEnabled(true);
    ui->_delete->setEnabled(false);
    ui->change->setEnabled(false);
    ui->save->setEnabled(true);
    setTabOrder(ui->name,ui->male);
    setTabOrder(ui->male, ui->major);
    setTabOrder(ui->major, ui->year);
    setTabOrder(ui->year, ui->teach_class);
    setTabOrder(ui->year, ui->save);
    setTabOrder(ui->save, ui->initialize);
    setTabOrder(ui->initialize, ui->cancel);
    setTabOrder(ui->cancel, ui->name);
}

void read_student_Dialog::on_save_clicked()
{
    if(get_student_num().isEmpty()||get_student_name().isEmpty()||get_major().isEmpty()||get_teach_class().isEmpty())
    {   //如果还有信息没填
        QMessageBox box(QMessageBox::Critical, "错误!", "信息不完整!", QMessageBox::Ok);
        box.exec();
    }
    else
    {
        emit change_student_signal(Student(get_student_num(), get_student_name(), get_student_sex(), get_major(), get_year(), get_teach_class()));
        QMessageBox box2(QMessageBox:: Information,"成功!", "修改学生信息成功!",QMessageBox::Ok,this);
        box2.exec();
        ui->name->setEnabled(false);
        ui->male->setEnabled(false);
        ui->female->setEnabled(false);
        ui->major->setEnabled(false);
        ui->year->setEnabled(false);
        ui->teach_class->setEnabled(false);
        ui->_delete->setEnabled(true);
        ui->change->setEnabled(true);
        ui->save->setEnabled(false);
        setTabOrder(ui->_delete, ui->change);
        setTabOrder(ui->change, ui->save);
        setTabOrder(ui->save, ui->initialize);
        setTabOrder(ui->initialize, ui->cancel);
        setTabOrder(ui->cancel, ui->_delete);
    }
}
