#ifndef ADD_STUDENT_DIALOG_H
#define ADD_STUDENT_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>

//这是添加学生信息的窗口

namespace Ui
{
    class add_student_Dialog;
}

class add_student_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit add_student_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~add_student_Dialog();

    //返回学号
    QString get_student_num();

    //返回学生名
    QString get_student_name();

    //返回学生性别
    QString get_student_sex();

    //返回学生专业
    QString get_major();

    //返回学生入学年份
    QString get_year();

    //返回学生的教学班级
    QString get_teach_class();

private:
    Ui::add_student_Dialog *ui;
};

#endif // ADD_STUDENT_DIALOG_H
