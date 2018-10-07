#ifndef GRADE_H
#define GRADE_H
#pragma execution_character_set("utf-8")


#include "student.h"
#include "course.h"

//这个类中包含成绩信息


class Grade: public Student, public Course
{
protected:

    //百分制成绩
    QString score;

    //等级制成绩
    QString score_rank;

    //学分绩
    QString gradepoint;


public:
    //构造函数
    Grade();

    //析构函数
    ~Grade();

    //构造函数
    Grade(const QString  &_stu_num, const QString &_stu_name, const QString &_stu_sex, const QString &_major, const QString &_year, const QString &_teach_class, const QString &_cou_num, const QString &_cou_name, const QString &_cou_credit, const QString &_cou_year, const QString &_cou_season, const QString &_score, const QString &_score_rank, const QString &_gradepoint);

    //复制构造函数
    Grade(const Grade &p);

    //文件名
    //用于同步
    static const QString filename;

    //按照文件的内容改变对象的值
    //用于同步
    void Txt_in(QTextStream &in);

    //返回一个包含全部信息的QString类
    //用于同步
    QString Put_string () const;

    //构造函数
    Grade(const Student &_student, const Course &_course, const QString &_score="0");

    //当学号和课程号都相同时返回真
    bool operator ==(const Grade &grade) const;

    //返回百分制成绩
    QString get_score() const;

    //返回等级制成绩
    QString get_score_rank() const;

    //返回学分绩
    QString get_gradepoint() const;

    //当学生信息改变时进行相应的改变
    void change_in_student(const Student &student);

    //当课程信息改变时进行相应的改变
    void change_in_course(const Course &course);

    //改变百分制成绩
    void change_score(const QString _score);
};

#endif // GRADE_H
