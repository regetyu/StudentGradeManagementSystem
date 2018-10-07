#ifndef GRA_DIALOG_H
#define GRA_DIALOG_H
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "add_grade_dialog.h"
#include "read_grade_dialog.h"
#include "object.h"

//这是对成绩信息操作的菜单

namespace Ui
{
    class gra_Dialog;
}

class gra_Dialog : public QDialog
{
    Q_OBJECT

public:
    //构造函数
    explicit gra_Dialog(QWidget *parent = nullptr);

    //析构函数
    ~gra_Dialog();

private slots:
    //添加成绩信息窗口
    void on_add_clicked();

    //查看、修改、删除成绩信息窗口
    void on_read_clicked();



private:
    Ui::gra_Dialog *ui;
signals:
    //添加成绩信息时传递参数
    void add_grade_signal(const QString, const QString, const QString);


};

#endif // GRA_DIALOG_H
