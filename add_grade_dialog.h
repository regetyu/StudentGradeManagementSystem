#ifndef ADD_GRADE_DIALOG_H
#define ADD_GRADE_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>

//这是添加成绩信息的窗口

namespace Ui
{
    class add_grade_Dialog;
}

class add_grade_Dialog : public QDialog
{
    Q_OBJECT
public:
    //构造函数
    explicit add_grade_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~add_grade_Dialog();

    //返回学生学号
    QString get_stu_num();

    //返回课程号
    QString get_cou_num();

    //返回百分制成绩
    QString get_score();

private:
    Ui::add_grade_Dialog *ui;
};

#endif // ADD_GRADE_DIALOG_H
