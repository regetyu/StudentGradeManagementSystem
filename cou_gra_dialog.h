#ifndef COU_GRA_DIALOG_H
#define COU_GRA_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include "object.h"

//这是查看课程所有学生成绩窗口

namespace Ui
{
    class cou_gra_Dialog;
}

class cou_gra_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit cou_gra_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~cou_gra_Dialog();

    //返回课程号
    QString get_num();

private slots:

    //显示信息
    void on_read_clicked();

private:
    Ui::cou_gra_Dialog *ui;
};

#endif // COU_GRA_DIALOG_H
