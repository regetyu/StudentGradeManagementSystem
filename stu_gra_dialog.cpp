#include "stu_gra_dialog.h"
#include "ui_stu_gra_dialog.h"

stu_gra_Dialog::stu_gra_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stu_gra_Dialog)
{
    ui->setupUi(this);
    setWindowTitle("打印学生成绩单");
    setFixedSize(1600,1000);  //设置固定窗口大小
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);  //去除"?"按钮
    ui->tableWidget->verticalHeader()->setVisible(false);

    //用正则表达式限制输入格式
    QRegExp regx("[0-9]+$");  //输入
    QValidator *validator = new QRegExpValidator(regx, ui->num );
    ui->num->setValidator(validator);
    setTabOrder(ui->num, ui->read);
    setTabOrder(ui->read, ui->cancel);
    setTabOrder(ui->cancel, ui->num);
}

stu_gra_Dialog::~stu_gra_Dialog()
{
    delete ui;
}

QString stu_gra_Dialog::get_num()
{
    return ui->num->text();
}

void stu_gra_Dialog::on_read_clicked()
{
    if(!(obj.repeat(Student(get_num()))))
    {   //如果不存在该课程号的课程
        QMessageBox box(QMessageBox:: Critical,"错误!", "不存在这个学号的学生!",QMessageBox::Ok,this);
        box.exec();
    }
    else
    {
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        QStringList header;
        header<<"课程号"<<"课程名"<<"学分"<<"成绩"<<"绩点"<<"所属学期";
        ui->tableWidget->setHorizontalHeaderLabels(header);
        QVector <Grade> stu_gra=obj.get_stu_gra(get_num());
        QVector <Grade> ::iterator it;
        for(it=stu_gra.begin(); it!=stu_gra.end(); it++)
        {   //用表格形式显示
            int i=ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(i+1);
            QTableWidgetItem *num=new QTableWidgetItem(it->get_cou_num());
            num->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *name=new QTableWidgetItem(it->get_cou_name());
            name->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *credit=new QTableWidgetItem(it->get_cou_credit());
            credit->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *grade=new QTableWidgetItem(it->get_score_rank());
            grade->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *gradepoint=new QTableWidgetItem(it->get_gradepoint());
            gradepoint->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            QTableWidgetItem *semester=new QTableWidgetItem((it->get_cou_year()+"-"+it->get_cou_season()));
            semester->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(i,0,num);
            ui->tableWidget->setItem(i,1,name);
            ui->tableWidget->setItem(i,2,credit);
            ui->tableWidget->setItem(i,3,grade);
            ui->tableWidget->setItem(i,4,gradepoint);
            ui->tableWidget->setItem(i,5,semester);
        }
    }
}
