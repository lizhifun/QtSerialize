#ifndef COMMONDATA_H
#define COMMONDATA_H

#include <QObject>
#include <QDataStream>

//用于存储公共数据
class CommonData : public QObject
{
    Q_OBJECT
public:
    explicit CommonData(QObject *parent = nullptr);

public:
    //定义静态数据结构
    static struct ParamsData{
        QString m_paramFile="qwe";
        int m_imagenubth=-1;
        bool m_SysInitDone=false;
        int m_grabimgIdx=112;
        float m_axisNum=123.234f;
        bool m_homeState=true;
        QPoint mark1_Center=QPoint(23,23);
        double mark1_Radius=5.0008;

        friend QDataStream &operator<<(QDataStream &stream, const ParamsData &data)//序列化
        {
            stream << data.m_paramFile;
            stream << data.m_imagenubth;
            stream << data.m_SysInitDone;
            stream << data.m_grabimgIdx;
            stream << data.m_axisNum;
            stream << data.m_homeState;
            stream << data.mark1_Center;
            stream << data.mark1_Radius;
            return stream;
        }

        friend QDataStream &operator>>(QDataStream &stream, ParamsData &data)//反序列化
        {
            stream >> data.m_paramFile;
            stream >> data.m_imagenubth;
            stream >> data.m_SysInitDone;
            stream >> data.m_grabimgIdx;
            stream >> data.m_axisNum;
            stream >> data.m_homeState;
            stream >> data.mark1_Center;
            stream >> data.mark1_Radius;
            return stream;
        }
    }paramsData;

};

#endif // COMMONDATA_H
