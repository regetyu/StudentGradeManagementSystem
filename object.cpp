#include "object.h"

Object::Object(QObject *parent) : QObject(parent)
{   //从文本文件中同步数据
    sync_in(stu);
    sync_in(cou);
    sync_in(gra);
}

Object obj;

void Object::add_student(const QString &_stu_num, const QString &_stu_name, const QString &_stu_sex, const QString &_major, const QString &_year, const QString &_teach_class)
{
    stu.push_back(Student(_stu_num,_stu_name,_stu_sex,_major,_year,_teach_class));
    sync_out(stu);
}


void Object::add_course(const QString &_cou_num, const QString &_cou_name, const QString &_cou_credit, const QString &_cou_year, const QString &_cou_season)
{
    cou.push_back(Course(_cou_num,_cou_name,_cou_credit,_cou_year, _cou_season));
    sync_out(cou);
}

void Object::add_grade(const QString &_stu_num, const QString &_cou_num, const QString &_grade)
{
    Student _student;
    Course _course;
    QVector <Student> ::iterator it;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(*it==_stu_num)
            _student=*it;
    }
    QVector <Course> ::iterator it1;
    for(it1=cou.begin(); it1!=cou.end(); it1++)
    {
        if(*it1==_cou_num)
            _course=*it1;
    }
    gra.push_back(Grade(_student,_course,_grade));
    sync_out(gra);
}

bool Object::repeat(const Student &student)
{
    QVector <Student> :: iterator it;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(*it==student)
            return true;
    }
    return false;
}

bool Object::repeat(const Course &course)
{
    QVector <Course> :: iterator it;
    for(it=cou.begin(); it!=cou.end(); it++)
    {
        if(*it==course)
            return true;
    }
    return false;
}

bool Object::repeat(const Grade &grade)
{
    QVector <Grade> :: iterator it;
    for(it=gra.begin(); it!=gra.end(); it++)
    {
        if(*it==grade)
            return true;
    }
    return false;
}


Student Object::find_student(const QString &_stu_num)
{
    QVector <Student> :: iterator it;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(*it==_stu_num)
            return *it;
    }
    Student a;
    return a;
}


Course Object::find_course(const QString &_cou_num)
{
    QVector <Course> :: iterator it;
    for(it=cou.begin(); it!=cou.end(); it++)
    {
        if(*it==_cou_num)
            return *it;
    }
    Course a;
    return a;
}


Grade Object::find_grade(const QString &_stu_num, const QString &_cou_num)
{
    QVector <Student > ::iterator it;
    QVector <Course> :: iterator it1;
    QVector <Grade> :: iterator it2;
    Student student;
    Course course;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(*it==_stu_num)
            student=*it;
    }
    for(it1=cou.begin(); it1!=cou.end(); it1++)
    {
        if(*it1==_cou_num)
            course=*it1;
    }
    Grade grade(student,course);
    for(it2=gra.begin(); it2!=gra.end(); it2++)
    {
        if(*it2==grade)
            return *it2;
    }
    return grade;
}


void Object::delete_student(const QString &stu_num)
{
    for(int i=0; i<stu.size(); i++)
    {
        if(stu[i]==stu_num)
        {
            for(int k=i; k<stu.size()-1; k++)
            {
                stu[k]=stu[k+1];
            }
        }
    }
    stu.pop_back();
    sync_out(stu);
    for(int i=0; i<gra.size(); i++)
    {
        if(gra[i].get_stu_num()==stu_num)
        {
            for(int k=i; k<gra.size()-1; k++)
            {
                gra[k]=gra[k+1];
            }
            gra.pop_back();
            i--;
        }
    }
    sync_out(gra);
}




void Object::change_student(const Student &student)
{
    QVector <Student> :: iterator it;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(*it==student)
            *it=student;
    }
    sync_out(stu);
    QVector <Grade> :: iterator it2;
    for(it2=gra.begin(); it2!=gra.end(); it2++)
    {
        if(Student(*it2)==student)
            it2->change_in_student(student);
    }
    sync_out(gra);
}

void Object::delete_course(const QString &cou_num)
{
    for(int i=0; i<cou.size(); i++)
    {
        if(cou[i]==cou_num)
        {
            for(int k=i; k<cou.size()-1; k++)
            {
                cou[k]=cou[k+1];
            }
        }
    }
    cou.pop_back();
    sync_out(cou);
    for(int i=0; i<gra.size(); i++)
    {
        if(gra[i].get_cou_num()==cou_num)
        {
            for(int k=i; k<gra.size()-1; k++)
            {
                gra[k]=gra[k+1];
            }
            gra.pop_back();
            i--;
        }
    }
    sync_out(gra);
}

void Object::change_course(const Course &course)
{
    QVector <Course> :: iterator it;
    for(it=cou.begin(); it!=cou.end(); it++)
    {
        if(*it==course)
            *it=course;
    }
    sync_out(cou);
    QVector <Grade> :: iterator it2;
    for(it2=gra.begin(); it2!=gra.end(); it2++)
    {
        if(Course(*it2)==course)
            it2->change_in_course(course);
    }
    sync_out(gra);
}

void Object::delete_grade(const QString &stu_num, const QString &cou_num)
{
    for(int i=0; i<gra.size(); i++)
    {
        if(gra[i]==Grade(Student(stu_num), Course(cou_num)))
        {
            for(int k=i; k<gra.size()-1; k++)
            {
                gra[k]=gra[k+1];
            }
        }
    }
    gra.pop_back();
    sync_out(gra);
}

void Object::change_grade(const Grade &grade)
{
    QVector <Grade> :: iterator it;
    for(it=gra.begin(); it!=gra.end(); it++)
    {
        if(*it==grade)
            *it=grade;
    }
    sync_out(gra);
}


QVector <Grade> Object::get_stu_gra(const QString &num)
{
    QVector <Grade> stu_gra;
    QVector <Grade> :: iterator it;
    for(it=gra.begin(); it!=gra.end(); it++)
    {
        if(Student(*it)==num)
            stu_gra.push_back(*it);
    }
    return stu_gra;
}

QVector <Grade> Object::get_cou_gra(const QString &num)
{
    QVector <Grade> cou_gra;
    QVector <Grade> :: iterator it;
    for(it=gra.begin(); it!=gra.end(); it++)
    {
        if(Course(*it)==num)
            cou_gra.push_back(*it);
    }
    return cou_gra;
}


double Object::gpa(const QString &stu_num)
{
    double total_gradepoint=0;
    int total_credit=0;
    QVector <Grade> :: iterator it;
    for(it=gra.begin(); it!=gra.end(); it++)
    {
        if(Student(*it)==stu_num)
        {
            total_credit+=it->get_cou_credit().toInt();
            total_gradepoint+=it->get_gradepoint().toDouble()*it->get_cou_credit().toInt();
        }
    }
    return (total_gradepoint/total_credit);
}

QString Object::class_rank(const QString &stu_num)
{
    int rank=1;
    int total_num=0;
    Student student=find_student(stu_num);
    QVector <Student> ::iterator it;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(it->get_teach_class()==student.get_teach_class())
        {
            total_num++;
            if(gpa(it->get_stu_num())>gpa(stu_num))
                rank++;
        }
    }
    QString str;
    str=QString::number(rank)+'/'+QString::number(total_num);
    return str;
}

QString Object::major_rank(const QString &stu_num)
{
    int rank=1;
    int total_num=0;
    Student student=find_student(stu_num);
    QVector <Student> ::iterator it;
    for(it=stu.begin(); it!=stu.end(); it++)
    {
        if(it->get_major()==student.get_major()&&it->get_year()==student.get_year())
        {
            total_num++;
            if(gpa(it->get_stu_num())>gpa(stu_num))
                rank++;
        }
    }
    QString str;
    str=QString::number(rank)+'/'+QString::number(total_num);
    return str;
}

