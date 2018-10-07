#ifndef STU_DIALOG_H
#define STU_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "add_student_dialog.h"
#include "read_student_dialog.h"
#include "object.h"

//这是对学生信息操作的菜单


namespace Ui
{
    class stu_Dialog;
}

class stu_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit stu_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~stu_Dialog();

private slots:
    //添加学生信息窗口
    void on_add_clicked();

    //查看、修改、删除学生信息窗口
    void on_read_clicked();

private:
    Ui::stu_Dialog *ui;

signals:
    //在添加学生信息时传递参数
    void add_student_signal(QString,QString,QString,QString,QString,QString);


};

#endif // STU_DIALOG_H
