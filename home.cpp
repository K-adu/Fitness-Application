#include "home.h"
#include "ui_home.h"
#include"bmi.h"
#include"db_fitnessfirst.h"
#include"fitnessfirst.h"
#include"calories.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include"mainwindow.h"
#include "timer.h"
#include<QDebug>



Home::Home(QWidget *parent,QString username) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
     ui->homeStack->setCurrentIndex(0);
     ui->name->setText("Welcome "+username);
    this->username = username;
     QPixmap pix(":/homepage.jpg");
     ui->label_6->setPixmap(pix.scaled(970,570));
     QPixmap pix1(":/whitebackground.jpg");
     ui->label_22->setPixmap(pix1.scaled(2000,2000));
}


Home::~Home()
{
    delete ui;
}

    void Home::on_pushButton_clicked()
{
    QString username ;
      ui->homeStack->setCurrentIndex(0);
        QPixmap pix(":/homepage.jpg");
        ui->label_6->setPixmap(pix.scaled(900,500));


}

void Home::on_pushButton_2_clicked()
{
     ui->homeStack->setCurrentIndex(1);
}

void Home::on_pushButton_3_clicked()
{
       db_fitnessFirst db_f1("database.db") ;

       int weight = ui-> lineEdit_2 -> text().toInt();

       int height = ui-> lineEdit-> text().toInt();
       bmi b1(height,weight);
       ui->label_4-> setText(QString::number( b1.calculateBMI() ));

       double bmival =b1.calculateBMI();

       qDebug()<<bmival;
       qDebug()<<username;
       db_f1.addBmiData(username,bmival);


}


void Home::on_pushButton_4_clicked()
{

    ui->homeStack->setCurrentIndex(2);
    //QLabel *label_5;
    //label_5->openExternalLinks(true);
   // ui->label_5->setText("<a href=\"http://www.qtcentre.org\">QtCentre</a>");
   // ui->label_8->setText("Name:Manish Baral\ncontact number:9863474868\ne-mail:manishbaral112@gmail.com");
    ui->textBrowser_2->setText("1.Manish Baral \ncontact:9817115100\nE-mail:manishbaral112@gmail.com \n\n\n2.Sanjay Khanal \ncontact:9846877099 \nE-mail:sanjayakhanal10@gmail.com \n\n\n3.Sumit Khanal \ncontact:9843557022\nE-mail:sumit.khanal80@gmail.com\n\n\n4.Prabin Lamsal \ncontact:9846825271\nE-mail:lamsalprabin74@gmail.com");

}

void Home::on_pushButton_5_clicked()
{
    ui->homeStack->setCurrentIndex(3);

}



void Home::on_pushButton_6_clicked()
{
    int i ;
    int total=0;
//    calories *c ;
  //  chickenBreast f1 ;
//    milk *f2 ;
//    egg *f3 ;
//    oatmeal *f4;

    int calc = ui->spinBox -> text().toInt() ;
    for(i=0;i<calc;i++){

        //f1.food();

        total = total + (165) ;
    }

    int calc2 = ui->spinBox_2 -> text().toInt();
    for(i=0;i<calc2;i++){
       // c=f2 ;
        total = total + (149) ;
    }
     int calc3 = ui->spinBox_3 -> text().toInt();
     for(i=0;i<calc3;i++){
         //c=f3 ;
         total = total + (52) ;
     }
     int calc4 = ui->spinBox_4 -> text().toInt();
     for(i=0;i<calc4;i++){
        // c=f4 ;
         total = total + (68) ;
     }
     int calc5 = ui->spinBox_5 -> text().toInt();
     for(i=0;i<calc5;i++){
        // c=f4 ;
         total = total + (205) ;
     }
     int calc6 = ui->spinBox_6 -> text().toInt();
     for(i=0;i<calc6;i++){
        // c=f4 ;
         total = total + (72) ;
     }
     int calc7 = ui->spinBox_7 -> text().toInt();
     for(i=0;i<calc7;i++){
        // c=f4 ;
         total = total + (105) ;
     }
     int calc8 = ui->spinBox_8 -> text().toInt();
     for(i=0;i<calc8;i++){
        // c=f4 ;
         total = total + (97) ;
     }
     int calc9 = ui->spinBox_9 -> text().toInt();
     for(i=0;i<calc9;i++){
        // c=f4 ;
         total = total + (117) ;
     }
     int calc10 = ui->spinBox_10 -> text().toInt();
     for(i=0;i<calc10;i++){
        // c=f4 ;
         total = total + (59) ;
     }







     //total = calc + calc2 + calc3 ;
    ui->label_7->setText("Total calorie :"+QString::number(total)+" Cal");
}

void Home::on_pushButton_7_clicked()
{
    ui->homeStack->setCurrentIndex(4);
    ui->textBrowser->setText("1.KU Fitness Center \nLocation : University Rd , Dhulikhel 45200 \nContact :9817115200 \n\n\n2.Universal Gym \nLocation : Dhulikhel \nContact: 9841299409 \n\n\n3.Fitness Station Banepa \nLocation : Tindobato , Banepa 00977 \nConatct : 011-663223 \n\n\n4.Banepa Power House Gym \nBanepa 45210 \nContact :9849262569 \n\n\n5. National Gym Club \nLocation: Dhulikhel 45210 \nContact :9819147570  ");
}

void Home::on_pushButton_8_clicked()
{
     ui->homeStack->setCurrentIndex(5);

}

void Home::on_pushButton_exercise_clicked()
{
  mainwindow = new MainWindow(this);
  mainwindow->show();
}

void Home::on_pushButton_dietsuggestion_clicked()
{

  db_fitnessFirst db_f1("database.db") ;
  int num=db_f1.checkbmifordiet(username);
  qDebug()<<num;


            if(num>=190000&&num<=240000){
                ui->homeStack->setCurrentIndex(5);
                QFile file(":/diet/diet/average.txt");

                if (!file.open(QFile::ReadOnly | QFile::Text))
                    QMessageBox::warning(this,"title","File not open.");
                QTextStream in(&file);
                QString text  = in.readAll();
                ui->dietsuggestion_textBrowser->setText(text);
//                QFile file(":/diet/diet/overweight.txt");
//                if (!file.open(QFile::ReadOnly | QFile::Text)){
//                    QMessageBox::warning(this,"title","File not open.");


//                }
//                QTextStream in(&file);
//               QString text  = in.readAll();
//               QMessageBox msg;
//              msg.setText(text);
//              msg.exec();
              }

//               file.close();
            else if (num>240000) {
                ui->homeStack->setCurrentIndex(5);
                QFile file(":/diet/diet/overweight.txt");
                QTextStream in(&file);
                if (!file.open(QFile::ReadOnly | QFile::Text))
                  QMessageBox::warning(this,"title","File not open.");
                ui->dietsuggestion_textBrowser->setText(in.readAll());
          }
            else if (num<190000) {
                ui->homeStack->setCurrentIndex(5);
                QFile file(":/diet/diet/underweight.txt");
                QTextStream in(&file);
                if (!file.open(QFile::ReadOnly | QFile::Text))
                   QMessageBox::warning(this,"title","File not open.");
                ui->dietsuggestion_textBrowser->setText(in.readAll());

}
}

