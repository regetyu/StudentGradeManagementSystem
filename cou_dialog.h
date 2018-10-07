#ifndef COU_DIALOG_H
#define COU_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "add_course_dialog.h"
#include "read_course_dialog.h"
#include "object.h"

//这是对课程信息操作的菜单

namespace Ui
{
    class cou_Dialog;
}

class cou_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit cou_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~cou_Dialog();

private slots:
    //添加课程信息窗口
    void on_add_clicked();

    //查看、修改、删除课程信息窗口
    void on_read_clicked();


private:
    Ui::cou_Dialog *ui;

signals:
    //添加课程信息时传递参数
    void add_course_signal(QString,QString,QString,QString,QString);
};

#endif // COU_DIALOG_H
