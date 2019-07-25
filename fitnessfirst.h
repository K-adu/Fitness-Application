#ifndef FITNESSFIRST_H
#define FITNESSFIRST_H

#include <QMainWindow>
#include "db_fitnessfirst.h"
#include "home.h"

namespace Ui {
class fitnessFirst;
}

class fitnessFirst : public QMainWindow
{
    Q_OBJECT

public:
    explicit fitnessFirst(QWidget *parent = nullptr);
    ~fitnessFirst();

private slots:
    void on_homeButton_clicked();

    void on_loginButton_clicked();



    void on_registerButton_clicked();

    void on_registerDone_clicked();

    void on_pushButton_clicked();

private:
    Ui::fitnessFirst *ui;
    Home* home;

};

#endif // FITNESSFIRST_H
