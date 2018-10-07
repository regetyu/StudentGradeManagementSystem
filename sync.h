#ifndef SYNC_H
#define SYNC_H
#pragma execution_character_set("utf-8")

#include <QFile>
#include <QVector>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include "grade.h"
#include "iostream"

//这两个模板函数用于双向同步

template <typename T>
void sync_in ( QVector <T> &vec)
{
    QString str;
    QFile file(T::filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {   //如果文件不存在就创建文件
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        return;
    }
    QTextStream in(&file);
    for(;;)
    {
        Figure *f;
        T a;
        f=&a;
        f->Txt_in(in);
        vec.push_back(a);
        if(in.atEnd())
            break;
    }
    file.close();
}

template <typename T>
void sync_out(QVector <T> &vec)
{
    QString str;
    QFile file(T::filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for(int i=0;i<vec.size();i++)
    {
        Figure *f = &(vec[i]);
        out << endl;
        out << f->Put_string();
    }
    file.close();
}





#endif // SYNC_H
