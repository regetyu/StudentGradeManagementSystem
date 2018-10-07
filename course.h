#ifndef COURSE_H
#define COURSE_H
#pragma execution_character_set("utf-8")

#include "figure.h"
#include <QString>

//这个类中包含一门课程的相关信息

class Course : virtual public Figure
{
protected:
    //课程号
    QString cou_num;

    //课程名
    QString cou_name;

    //课程学分
    QString cou_credit;

    //课程年份
    QString cou_year;

    //课程季节
    QString cou_season;
public:
    //构造函数
    Course();

    //析构函数
    ~Course();

    //构造函数
    Course(const QString &_cou_num, const QString &_cou_name="0", const QString &_cou_credit="0", const QString &_cou_year="0", const QString &_cou_season="0");

    //复制构造函数
    Course(const Course &p);

    //文件名
    //用于同步
    static const QString filename;

    //按照文件的内容改变对象的值
    //用于同步
    void Txt_in(QTextStream &in);

    //返回一个包含全部信息的QString类
    //用于同步
    QString Put_string() const;

    //当两门课程的课程号相同时返回真
    bool operator ==(const Course &p) const;

    //当课程号等于字符串时返回真
    bool operator ==(const QString &s) const;

    //返回课程名
    QString get_cou_name() const;

    //返回课程学分
    QString get_cou_credit() const;

    //返回课程年份
    QString get_cou_year() const;

    //返回课程季节
    QString get_cou_season() const;

    //返回课程号
    QString get_cou_num() const;
};

#endif // COURSE_H
