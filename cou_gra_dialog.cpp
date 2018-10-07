#include "cou_gra_dialog.h"
#include "ui_cou_gra_dialog.h"

cou_gra_Dialog::cou_gra_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cou_gra_Dialog)
{
    ui->setupUi(this);
    setWindowTitle("打印课程所有学生成绩");
    setFixedSize(1600,1000);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);//去除"?"按钮
    ui->tableWidget->verticalHeader()->setVisible(false);

    //用正则表达式限制用户的输入格式
    QRegExp regx("[0-9]+$");  //数字
    QValidator *validator = new QRegExpValidator(regx, ui->num );
    ui->num->setValidator(validator);
    setTabOrder(ui->num, ui->read);
    setTabOrder(ui->read, ui->cancel);
    setTabOrder(ui->cancel, ui->num);
}

cou_gra_Dialog::~cou_gra_Dialog()
{
    delete ui;
}

QString cou_gra_Dialog::get_num()
{
    return(ui->num->text());
}

void cou_gra_Dialog::on_read_clicked()
{
    if(!(obj.repeat(Course(get_num()))))
    {   //如果不存在该课程号的课程
        QMessageBox box(QMessageBox:: Critical,"错误!", "不存在该课程号的课程!",QMessageBox::Ok,this);
        box.exec();
    }
    else
    {   //按表格形式显示
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        QStringList header;
        header<<"学号"<<"姓名"<<"班级"<<"百分制成绩"<<"等级制成绩"<<"绩点";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        QVector <Grade> cou_gra=obj.get_cou_gra(get_num());
        QVector <Grade> ::iterator it;
        for(it=cou_gra.begin(); it!=cou_gra.end(); it++)
        {
            int i=ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(i+1);
            QTableWidgetItem *num=new QTableWidgetItem(it->get_stu_num());
            num->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *name=new QTableWidgetItem(it->get_stu_name());
            name->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *teach_class=new QTableWidgetItem(it->get_teach_class());
            teach_class->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *score=new QTableWidgetItem(it->get_score());
            score->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *grade=new QTableWidgetItem(it->get_score_rank());
            grade->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *gradepoint=new QTableWidgetItem(it->get_gradepoint());
            gradepoint->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(i,0,num);
            ui->tableWidget->setItem(i,1,name);
            ui->tableWidget->setItem(i,2,teach_class);
            ui->tableWidget->setItem(i,3,score);
            ui->tableWidget->setItem(i,4,grade);
            ui->tableWidget->setItem(i,5,gradepoint);
        }
    }
}

