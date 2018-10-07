#ifndef TCLASS_H
#define TCLASS_H
#pragma execution_character_set("utf-8")


#include <QString>

//这个类包含学生的部分信息
//主要用于排名



class Tclass
{
protected:
    //学生的专业
    QString major;

    //学生的入学年份
    QString year;

    //学生的教学班级
    QString teach_class;

public:
    //构造函数
    Tclass();

    //复制构造函数
    ~Tclass();

    //构造函数
    Tclass(const QString &_major, const QString &_year, const QString &_teach_class);

    //复制构造函数
    Tclass(const Tclass &p);

    //返回学生的专业
    QString get_major() const;

    //返回学生的入学年份
    QString get_year() const;

    //返回学生的教学班级
    QString get_teach_class() const;

};

#endif // TCLASS_H
