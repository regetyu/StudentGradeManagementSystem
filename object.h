#ifndef OBJECT_H
#define OBJECT_H
#pragma execution_character_set("utf-8")

#include <QObject>
#include <QVector>
#include "grade.h"
#include "sync.h"

//这个类包含系统存储的所有信息

class Student;
class Course;
class Grade;

class Object : public QObject
{
    Q_OBJECT
public:
    //构造函数
    explicit Object(QObject *parent = nullptr);

    //学生信息向量
    QVector <Student> stu;

    //课程信息向量
    QVector <Course> cou;

    //成绩信息向量
    QVector <Grade> gra;

    //当学生信息向量中有相同学号的学生时返回真
    bool repeat(const Student &student);

    //当课程信息向量中有相同课程号的课程时返回真
    bool repeat(const Course &course);

    //当存在成绩信息向量中存在相同课程号和学号的成绩信息时返回真
    bool repeat(const Grade &grade);

    //返回该学号的学生
    Student find_student(const QString & _stu_num);

    //返回该课程号的课程
    Course find_course(const QString & _cou_num);

    //返回该学号和课程号的成绩信息
    Grade find_grade(const QString & _stu_num, const QString &_cou_num);

    //返回该学号的学生所有课程的成绩信息组成的向量
    QVector <Grade> get_stu_gra(const QString &num);

    //返回该课程号的课程所有学生的成绩信息组成的向量
    QVector <Grade> get_cou_gra(const QString &num);

    //返回该学号的学生的平均学分绩
    double gpa(const QString &stu_num);

    //返回该学号的学生的班级排名
    QString class_rank(const QString &stu_num);

    //返回该学号的学生的年级排名
    QString major_rank(const QString &stu_num);

public slots:
    //添加学生信息
    void add_student(const QString  &_stu_num, const QString &_stu_name, const QString &_stu_sex, const QString &_major, const QString &_year, const QString &_teach_class);

    //添加课程信息
    void add_course(const QString &_cou_num, const QString &_cou_name, const QString &_cou_credit, const QString &_cou_year, const QString &_cou_season);

    //添加成绩信息
    void add_grade(const QString &_stu_num, const QString &_cou_num, const QString &_grade);

    //删除学生信息
    void delete_student(const QString & stu_num);

    //修改学生信息
    void change_student(const Student &student);

    //删除课程信息
    void delete_course(const QString &cou_num);

    //改变课程信息
    void change_course(const Course &course);

    //删除成绩信息
    void delete_grade(const QString &stu_num, const QString &cou_num);

    //改变成绩信息
    void change_grade(const Grade &grade);

};

//全局变量
extern Object obj;

#endif // OBJECT_H
