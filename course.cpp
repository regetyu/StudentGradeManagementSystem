#include "course.h"



const QString Course::filename="course.txt";

Course::Course()
{

}

Course::~Course()
{

}

Course::Course(const QString &_cou_num, const QString &_cou_name, const QString &_cou_credit, const QString &_cou_year, const QString &_cou_season): cou_num(_cou_num), cou_name(_cou_name), cou_credit(_cou_credit), cou_year(_cou_year), cou_season(_cou_season)
{

}

Course::Course(const Course &p): cou_num(p.cou_num), cou_name(p.cou_name), cou_credit(p.cou_credit), cou_year(p.cou_year), cou_season(p.cou_season)
{

}

void Course::Txt_in(QTextStream &in)
{
    QString a, b, c, d, e;
    in >> a >> b >> c >> d >> e;
    cou_num=a;
    cou_name=b;
    cou_credit=c;
    cou_year=d;
    cou_season=e;
}

QString Course::Put_string() const
{
    return(cou_num+" "+cou_name+" "+cou_credit+" "+cou_year+ " "+cou_season);
}


bool Course::operator==(const Course & p) const
{
    return (cou_num == p.cou_num);
}

bool Course::operator ==(const QString &s) const
{
    return (cou_num) ==s;
}



QString Course::get_cou_name() const
{
    return cou_name;
}


QString Course::get_cou_credit() const
{
    return cou_credit;
}

QString Course::get_cou_year() const
{
    return cou_year;
}

QString Course::get_cou_num() const
{
    return cou_num;
}


QString Course::get_cou_season() const
{
    QString a;
    return cou_season;
}
