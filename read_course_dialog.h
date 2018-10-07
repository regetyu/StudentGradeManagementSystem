#ifndef READ_COURSE_DIALOG_H
#define READ_COURSE_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "object.h"

//这是查看、修改、删除课程信息的窗口

namespace Ui
{
    class read_course_Dialog;
}

class read_course_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit read_course_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~read_course_Dialog();

    //返回课程号
    QString get_course_num();

    //返回课程名
    QString get_course_name();

    //返回课程学分
    QString get_course_credit();

    //返回课程年份
    QString get_course_year();

    //返回课程季节
    QString get_course_season();

private slots:
    //初始化
    void on_initialize_clicked();

    //显示课程信息
    void on_read_clicked();

    //删除课程信息
    void on__delete_clicked();

    //修改课程信息
    void on_change_clicked();

    //保存课程信息
    void on_save_clicked();

private:
    Ui::read_course_Dialog *ui;

signals:
    //删除课程信息
    void delete_course_signal(const QString &cou_num);

    //改变课程信息
    void change_course_signal(const Course &course);
};

#endif // READ_COURSE_DIALOG_H
