#ifndef READ_STUDENT_DIALOG_H
#define READ_STUDENT_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <object.h>

//这是查看、修改、删除学生信息的窗口

namespace Ui
{
    class read_student_Dialog;
}

class read_student_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit read_student_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~read_student_Dialog();

    //返回学生学号
    QString get_student_num();

    //返回学生姓名
    QString get_student_name();

    //返回学生性别
    QString get_student_sex();

    //返回学生专业
    QString get_major();

    //返回学生入学年份
    QString get_year();

    //返回学生的教学班级
    QString get_teach_class();

private slots:
    //初始化
    void on_initialize_clicked();

    //查看学生信息
    void on_read_clicked();

    //删除学生信息
    void on__delete_clicked();

    //修改学生信息
    void on_change_clicked();

    //保存学生信息
    void on_save_clicked();

private:
    Ui::read_student_Dialog *ui;

signals:
    //删除学生信息
    void delete_student_signal(const QString &stu_num);

    //修改学生信息
    void change_student_signal(const Student &student);



};

#endif // READ_STUDENT_DIALOG_H
