#ifndef STU_GRA_DIALOG_H
#define STU_GRA_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include "object.h"

//这是打印学生成绩单窗口

namespace Ui
{
    class stu_gra_Dialog;
}

class stu_gra_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit stu_gra_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~stu_gra_Dialog();

    //返回学生学号
    QString get_num();

private slots:
    void on_read_clicked();

private:
    Ui::stu_gra_Dialog *ui;



};

#endif // STU_GRA_DIALOG_H
