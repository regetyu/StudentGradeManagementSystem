#include "grade.h"



const QString Grade::filename="grade.txt";


Grade::Grade()
{

}

Grade::~Grade()
{

}


Grade::Grade(const QString &_stu_num, const QString &_stu_name, const QString &_stu_sex, const QString &_major, const QString &_year, const QString &_teach_class, const QString &_cou_num, const QString &_cou_name, const QString &_cou_credit, const QString &_cou_year, const QString &_cou_season, const QString &_score, const QString &_score_rank, const QString &_gradepoint): Student(_stu_num, _stu_name, _stu_sex, _major, _year, _teach_class), Course(_cou_num, _cou_name, _cou_credit, _cou_year, _cou_season), score(_score), score_rank(_score_rank), gradepoint(_gradepoint)
{
                                                                                                                                                                                                                                                                              }

Grade::Grade(const Grade &p): Student(p), Course(p), score(p.score), score_rank(p.score_rank), gradepoint(p.gradepoint)
{

}

void Grade::Txt_in(QTextStream &in)
{
    QString a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    in >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m >>n;
    stu_num=a;
    stu_name=b;
    stu_sex=c;
    major=d;
    year=e;
    teach_class=f;
    cou_num=g;
    cou_name=h;
    cou_credit=i;
    cou_year=j;
    cou_season=k;
    score=l;
    score_rank=m;
    gradepoint=n;
}


QString Grade::Put_string() const
{
    return(Student::Put_string() + " " + Course::Put_string() + " "+score+" "+score_rank+" "+gradepoint);
}

Grade::Grade(const Student &_student, const Course &_course, const QString &_score):Student(_student), Course(_course), score(_score)
{
    //将百分制成绩转化为等级制成绩
    if (score == "100")
    {
        score_rank = "A+";
        gradepoint = "4.0";
    }
    else if (score <= "99" && score >= "95")
    {
        score_rank = "A";
        gradepoint = "4.0";
    }
    else if (score <= "94" && score >= "90")
    {
        score_rank = "A-";
        gradepoint = "3.7";
    }
    else if (score <= "89" && score >= "85")
    {
        score_rank = "B+";
        gradepoint = "3.3";
    }
    else if (score <= "84" && score >= "80")
    {
        score_rank = "B";
        gradepoint = "3.0";
    }
    else if (score <= "79" && score >= "77")
    {
        score_rank = "B-";
        gradepoint = "2.7";
    }
    else if (score <= "76" && score >= "73")
    {
        score_rank = "C+";
        gradepoint = "2.3";
    }
    else if (score <= "72" && score >= "70")
    {
        score_rank = "C";
        gradepoint = "2.0";
    }
    else if (score <= "69" && score >= "67")
    {
        score_rank = "C-";
        gradepoint = "1.7";
    }
    else if (score <= "66" && score >= "63")
    {
        score_rank = "D+";
        gradepoint = "1.3";
    }
    else if (score <= "62" && score >= "60")
    {
        score_rank = "D";
        gradepoint = "1.0";
    }
    else if ((score <= "59" && score >= "50")|| (score <= "49" && score >= "40") || (score <= "39" && score >= "30") || (score <= "29" && score >= "20") || (score <= "19" && score >= "10") || (score <= "9" && score >= "0"))
    {
        score_rank = "F";
        gradepoint = "0";
    }
}



bool Grade::operator ==(const Grade &gra) const
{
    return((stu_num==gra.stu_num)&&(cou_num==gra.cou_num));
}


QString Grade::get_score() const
{
    return score;
}


QString Grade::get_score_rank() const
{
    return score_rank;
}

QString Grade::get_gradepoint() const
{
    return gradepoint;
}




void Grade::change_in_student(const Student &student)
{
    stu_num=student.get_stu_num();
    stu_name=student.get_stu_name();
    stu_sex=student.get_stu_sex();
    major=student.get_major();
    year=student.get_year();
}

void Grade::change_in_course(const Course &course)
{
    cou_num=course.get_cou_num();
    cou_name=course.get_cou_name();
    cou_credit=course.get_cou_credit();
    cou_year=course.get_cou_year();
    cou_season=course.get_cou_season();
}

void Grade::change_score(const QString _score)
{
    score=_score;
}
