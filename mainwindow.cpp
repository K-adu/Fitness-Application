#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include"home.h"
#include"timer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/exercisebackground.jpg");
    ui->exercise_background->setPixmap(pix.scaled(1490,851));


    mthread = new timer(this);
    connect(mthread,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged(int)));
   // connect(mthread,SIGNAL(void timerStopped(int)),this,SLOT(void reset1()));



    mthread2 = new timer(this);
    connect(mthread2,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged2(int)));


    mthread3 = new timer(this);
    connect(mthread3,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged3(int)));

    mthread4 = new timer(this);
    connect(mthread4,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged4(int)));

    mthread5 = new timer(this);
    connect(mthread5,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged5(int)));


    mthread6 = new timer(this);
    connect(mthread6,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged6(int)));

    mthread7 = new timer(this);
    connect(mthread7,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged7(int)));

    mthread8 = new timer(this);
    connect(mthread8,SIGNAL(numberChanged(int)),this,SLOT(onnumberchanged8(int)));




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onnumberchanged(int number)
{

   ui->label_4->setText(QString::number(number));
}






void MainWindow::onnumberchanged2(int number)
{

   ui->label_17->setText(QString::number(number));
}

void MainWindow::onnumberchanged3(int number)
{

   ui->label_15->setText(QString::number(number));
}


void MainWindow::onnumberchanged4(int number)
{

   ui->label_9->setText(QString::number(number));
}

void MainWindow::onnumberchanged5(int number)
{

   ui->label_13->setText(QString::number(number));
}


void MainWindow::onnumberchanged6(int number)
{

   ui->label_5->setText(QString::number(number));
}


void MainWindow::onnumberchanged7(int number)
{

   ui->label_11->setText(QString::number(number));
}


void MainWindow::onnumberchanged8(int number)
{

   ui->label_7->setText(QString::number(number));
}






void MainWindow::on_pushButton_2_clicked()
{
    mthread->start();
}

void MainWindow::on_pushButton_clicked()
{
          mthread->terminate();
}




void MainWindow::on_pushButton_22_clicked()
{
    mthread2->start();
}

void MainWindow::on_pushButton_23_clicked()
{
//timer t1;
//t1.stop=true;
//if(t1.stop){
//      ui->label_17->setText("120");
      mthread2->terminate();

//    }
}




void MainWindow::on_pushButton_19_clicked()
{
    mthread3->start();
}

void MainWindow::on_pushButton_20_clicked()
{
        mthread3->terminate();
}




void MainWindow::on_pushButton_10_clicked()
{
     mthread4->start();
}


void MainWindow::on_pushButton_16_clicked()
{
      mthread5->start();
}

void MainWindow::on_pushButton_17_clicked()
{
           mthread5->terminate();
}

void MainWindow::on_pushButton_4_clicked()
{
    mthread6->start();
}


void MainWindow::on_pushButton_5_clicked()
{
          mthread6->terminate();
}

void MainWindow::on_pushButton_13_clicked()
{
     mthread7->start();
}

void MainWindow::on_pushButton_14_clicked()
{
          mthread7->terminate();
}


void MainWindow::on_pushButton_7_clicked()
{
       mthread8->start();
}

void MainWindow::on_pushButton_8_clicked()
{
          mthread8->terminate();
}


void MainWindow::on_pushButton_3_clicked()
{
  QPixmap pix(":/warmups.png");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/warmup.txt");
   QTextStream in(&file);
   if (!file.open(QFile::ReadOnly | QFile::Text))
      QMessageBox::warning(this,"title","File not open.");
      ui->exercise_textBrowser->setText(in.readAll());
}

void MainWindow::on_pushButton_24_clicked()
{


  QPixmap pix(":/pushup.jpg");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/pushup.txt");
      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text)){
          QMessageBox::warning(this,"title","File not open.");}
         ui->exercise_textBrowser->setText(in.readAll());

}


void MainWindow::on_pushButton_21_clicked()
{
  QPixmap pix(":/jumpsquats");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));

  QFile file(":/txt/files/jump squats.txt");
      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text))
         QMessageBox::warning(this,"title","File not open.");
         ui->exercise_textBrowser->setText(in.readAll());
}

void MainWindow::on_pushButton_12_clicked()
{
  QPixmap pix(":/crunches.png");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/crunches.txt");
      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text))
         QMessageBox::warning(this,"title","File not open.");
         ui->exercise_textBrowser->setText(in.readAll());
}

void MainWindow::on_pushButton_18_clicked()
{

  QPixmap pix(":/mountainclimbing.jpg");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/mountain climb.txt");
      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text))
         QMessageBox::warning(this,"title","File not open.");
         ui->exercise_textBrowser->setText(in.readAll());
}
void MainWindow::on_pushButton_6_clicked()
{
  QPixmap pix(":/supermanhold.JPG");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/superman hold.txt");
      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text))
         QMessageBox::warning(this,"title","File not open.");
         ui->exercise_textBrowser->setText(in.readAll());


    }


void MainWindow::on_pushButton_15_clicked()
{
  QPixmap pix(":/burpees.jpg");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/burpee.txt");
      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text))
         QMessageBox::warning(this,"title","File not open.");
         ui->exercise_textBrowser->setText(in.readAll());
}

void MainWindow::on_pushButton_9_clicked()
{
  QPixmap pix(":/plank.jpg");
  ui->exercisepanel_image->setPixmap(pix.scaled(400,300));
    QFile file(":/txt/files/plank.txt");

      QTextStream in(&file);
      if (!file.open(QFile::ReadOnly | QFile::Text))
         QMessageBox::warning(this,"title","File not open.");
         ui->exercise_textBrowser->setText(in.readAll());
}
