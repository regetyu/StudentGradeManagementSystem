#ifndef STUDENT_H
#define STUDENT_H
#pragma execution_character_set("utf-8")

#include <QTextStream>
#include "tclass.h"
#include "figure.h"

//这各类包含学生的信息

class Student : public Tclass, virtual public Figure
{
protected:
    //学号
    QString stu_num;

    //姓名
    QString stu_name;

    //性别
    //男或女
    QString stu_sex;

public:
    //构造函数
    Student();

    //析构函数
     ~Student();

    //构造函数
    Student(const QString  &_stu_num, const QString &_stu_name="0", const QString &_stu_sex="0", const QString &_major="0", const QString &_year="0", const QString &_teach_class="0");

    //复制构造函数
    Student(const Student &p);

    //文件名
    //用于同步
    static const QString filename;

    //按照文件的内容改变对象的值
    //用于同步
    void Txt_in(QTextStream &in);

    //返回一个包含全部信息的QString类
    //用于同步
    QString Put_string() const;

    //当学号相同是返回真
    bool operator ==(const Student &p) const;

    //当学号等于字符串时返回真
    bool operator ==(const QString &s) const;

    //返回学生姓名
    QString get_stu_name() const;

    //返回学生性别
    QString get_stu_sex() const;

    //返回学生学号
    QString get_stu_num() const;
};

#endif // STUDENT_H
