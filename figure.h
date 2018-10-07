#ifndef FIGURE_H
#define FIGURE_H
#pragma execution_character_set("utf-8")

#include <QTextStream>
#include <QString>

//这是虚基类
//在"sync.h"中使用

class Figure
{
public:
    //虚析构函数
    virtual ~Figure()
    {

    }

    //按照文件的内容改变对象的值
    //用于同步
    virtual void Txt_in(QTextStream &in)=0;

    //返回一个包含全部信息的QString类
    //用于同步
    virtual QString Put_string() const=0 ;
};

#endif // FIGURE_H
