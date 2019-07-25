#include "timer.h"
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    timer *mthread;
    timer *mthread2;
    timer *mthread3;
    timer *mthread4;
    timer *mthread5;
    timer *mthread6;
    timer *mthread7;
    timer *mthread8;

private:
    Ui::MainWindow *ui;
public slots:
    void onnumberchanged(int);
     void onnumberchanged2(int);
     void onnumberchanged3(int);
      void onnumberchanged4(int);
      void onnumberchanged5(int);
       void onnumberchanged6(int);
       void onnumberchanged7(int);
        void onnumberchanged8(int);
        //void reset1();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_10_clicked();
    //void on_pushButton_11_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_9_clicked();
};

#endif // MAINWINDOW_H
