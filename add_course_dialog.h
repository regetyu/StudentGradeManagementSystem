#ifndef ADD_COURSE_DIALOG_H
#define ADD_COURSE_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>

//这是添加课程信息的窗口

namespace Ui
{
    class add_course_Dialog;
}

class add_course_Dialog : public QDialog
{
    Q_OBJECT
public:
    //构造函数
    explicit add_course_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~add_course_Dialog();

    //返回课程号
    QString get_course_num();

    //返回课程名
    QString get_course_name();

    //返回课程学分
    QString get_course_credit();

    //返回年份
    QString get_course_year();

    //返回季节
    QString get_course_season();

private:
    Ui::add_course_Dialog *ui;
};

#endif // ADD_COURSE_DIALOG_H
