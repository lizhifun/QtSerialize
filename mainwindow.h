#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void PrintContent();

private slots:
    void on_btn_Read_clicked();
    void on_btn_Write_clicked();
    void on_btn_ChangeVal_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
