#include "tclass.h"

Tclass::Tclass()
{

}

Tclass::~Tclass()
{

}

Tclass::Tclass(const QString &_major, const QString &_year, const QString &_teach_class): major(_major), year(_year), teach_class(_teach_class)
{

}

Tclass::Tclass(const Tclass &p): major(p.major), year(p.year), teach_class(p.teach_class)
{

}


QString Tclass::get_major() const
{
    return major;
}


QString Tclass::get_year() const
{
    return year;
}

QString Tclass::get_teach_class() const
{
    return teach_class;
}
