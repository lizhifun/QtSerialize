#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commondata.h"
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_Read_clicked()// 从文件中读取/初始化数据
{
    QFile file("data.sx");//文件在程序运行目录下
    if(file.exists())//如果文件存在 则从文件读取数据
    {
        file.open(QIODevice::ReadOnly);
        QDataStream input(&file);
        input >> CommonData::paramsData;
        file.close();

        //打印出各个变量的值
        qDebug() << QStringLiteral("打印出文件中读出的值.......");
        PrintContent();
    }
    else//如果文件不存在 则使用初始化数据
    {
        //打印出各个变量的值
        qDebug() << QStringLiteral("打印出初始化的值.......");
        PrintContent();
    }
}

void MainWindow::on_btn_Write_clicked()//将数据写入文件保存
{
    QFile file("data.sx");//文件在程序运行目录下
    file.open(QIODevice::WriteOnly);
    QDataStream output(&file);
    output << CommonData::paramsData;
    file.close();
}

void MainWindow::on_btn_ChangeVal_clicked()//改变数据的值，查看是否能正确写入文件并读出
{
    CommonData::paramsData.m_axisNum=234.123f;
    CommonData::paramsData.m_homeState=false;
    CommonData::paramsData.m_paramFile="wer";
    CommonData::paramsData.m_grabimgIdx=113;
    CommonData::paramsData.m_imagenubth=168;
    CommonData::paramsData.mark1_Center=QPoint(66,88);
    CommonData::paramsData.mark1_Radius=6.08080808;
    CommonData::paramsData.m_SysInitDone=true;
    qDebug() << QStringLiteral("打印改变后的值.......");
    PrintContent();
}

void MainWindow::PrintContent()//打印数据 便于调试查看
{
    qDebug() << CommonData::paramsData.m_axisNum;
    qDebug() << CommonData::paramsData.m_homeState;
    qDebug() << CommonData::paramsData.m_paramFile;
    qDebug() << CommonData::paramsData.m_grabimgIdx;
    qDebug() << CommonData::paramsData.m_imagenubth;
    qDebug() << CommonData::paramsData.mark1_Center;
    qDebug() << CommonData::paramsData.mark1_Radius;
    qDebug() << CommonData::paramsData.m_SysInitDone;
}
