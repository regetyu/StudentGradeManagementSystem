#ifndef GPA_DIALOG_H
#define GPA_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "object.h"
#include <QRegExpValidator>

//这是查看学生平均学分绩和排名窗口

namespace Ui
{
    class gpa_Dialog;
}

class gpa_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit gpa_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~gpa_Dialog();

    //返回学生学号
    QString get_num();

private slots:
    //显示信息
    void on_read_clicked();

    //初始化
    void on_initialize_clicked();

private:
    Ui::gpa_Dialog *ui;
};

#endif // GPA_DIALOG_H
