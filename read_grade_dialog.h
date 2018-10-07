#ifndef READ_GRADE_DIALOG_H
#define READ_GRADE_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "object.h"

//这是查看、修改、删除成绩信息窗口

namespace Ui
{
    class read_grade_Dialog;
}

class read_grade_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit read_grade_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~read_grade_Dialog();

    //返回学生学号
    QString get_stu_num();

    //返回课程的课程号
    QString get_cou_num();

    //返回百分制成绩
    QString get_score();

private slots:
    //初始化
    void on_initialize_clicked();

    //查看成绩信息
    void on_read_clicked();

    //删除成绩信息
    void on__delete_clicked();

    //修改成绩信息
    void on_change_clicked();

    //保存成绩信息
    void on_save_clicked();

private:
    Ui::read_grade_Dialog *ui;

signals:
    //删除成绩信息
    void delete_grade_signal(const QString &stu_num, const QString &cou_num);

    //改变成绩信息
    void change_grade_signal(const Grade &grade);
};

#endif // READ_GRADE_DIALOG_H
