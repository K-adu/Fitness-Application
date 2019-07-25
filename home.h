#include"mainwindow.h"
#ifndef HOME_H
#define HOME_H

#include <QMainWindow>

#include"timer.h"

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr,QString username="user");
    ~Home();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();



    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_exercise_clicked();

    void on_pushButton_dietsuggestion_clicked();

private:
    Ui::Home *ui;
    QString username;
    MainWindow *mainwindow;

};

#endif // HOME_H
