#ifndef FUN_DIALOG_H
#define FUN_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "stu_gra_dialog.h"
#include "cou_gra_dialog.h"
#include "gpa_dialog.h"

//这是高级功能的菜单

namespace Ui
{
    class fun_Dialog;
}

class fun_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit fun_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~fun_Dialog();


private slots:

    //打印学生成绩单窗口
    void on_stu_grade_list_clicked();

    //查看课程所有学生成绩窗口
    void on_cou_grade_list_clicked();

    //查看学生学分绩和排名窗口
    void on_gpa_clicked();

private:
    Ui::fun_Dialog *ui;
};

#endif // FUN_DIALOG_H
