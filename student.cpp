#include "student.h"



const QString Student::filename = "student.txt";

Student::Student()
{

}


Student::~Student()
{

}

Student::Student(const QString &_stu_num, const QString &_stu_name, const QString &_stu_sex, const QString &_major, const QString &_year, const QString &_teach_class): Tclass(_major, _year, _teach_class),stu_num(_stu_num), stu_name(_stu_name), stu_sex(_stu_sex)
{

}

Student::Student(const Student &p): Tclass(p), stu_num(p.stu_num), stu_name(p.stu_name), stu_sex(p.stu_sex)
{

}



void Student::Txt_in(QTextStream &in)
{
    QString a, b, d, f;
    QString c;
    QString e;
    in >> a >> b >> c >> d >> e >> f;
    stu_num=a;
    stu_name=b;
    stu_sex=c;
    major=d;
    year=e;
    teach_class=f;
}


QString Student::Put_string() const
{
    return(stu_num+" "+stu_name+" "+stu_sex+" "+major+" "+year+" "+teach_class);
}


bool Student::operator==(const Student &p) const
{
    return (stu_num == p.stu_num);
}


bool Student::operator ==(const QString &s) const
{
    return (stu_num == s);
}


QString Student::get_stu_name() const
{
    return(stu_name);
}

QString Student::get_stu_sex() const
{
    return(stu_sex);
}

QString Student::get_stu_num() const
{
    return(stu_num);
}

