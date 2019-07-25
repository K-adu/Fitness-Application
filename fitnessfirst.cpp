#include "fitnessfirst.h"
#include "ui_fitnessfirst.h"
#include<QDebug>
#include<QMovie>
#include<QMessageBox>

fitnessFirst::fitnessFirst(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fitnessFirst)
{
    ui->setupUi(this);
    ui->mainStack->setCurrentIndex(0);
    QPixmap pix(":/4.jpg");
    ui->label_3->setPixmap(pix.scaled(900,500));



}

fitnessFirst::~fitnessFirst()
{
    delete ui;
}

void fitnessFirst::on_homeButton_clicked()
{
    ui->mainStack->setCurrentIndex(0);

}

void fitnessFirst::on_loginButton_clicked()
{
    ui->mainStack->setCurrentIndex(1);
    QPixmap pix(":/3.jpg");
    ui->label_7->setPixmap(pix.scaled(900,500));
}




void fitnessFirst::on_registerButton_clicked()
{
    ui->mainStack->setCurrentIndex(2);
    QPixmap pix(":/registerone.jpg");
    ui->label_5->setPixmap(pix.scaled(900,500));


}

void fitnessFirst::on_registerDone_clicked()
{
    //bool ok = false ;
    QString firstName , lastName , username , password , gender , weight , height , age;
    double bmicalc ;
    firstName = ui->s_lineeditfirstname->text();
    lastName = ui->s_lineeditlastname->text();
    username = ui->s_lineeditusername->text();
    password = ui->s_lineeditpassword->text();
    gender = ui->s_lineeditgender->text();
    weight = ui->s_lineeditweight->text();
    height = ui->s_lineeditheight->text();
    age = ui->s_lineeditage->text();
    bmicalc =0;
   // bmicalc.toDouble(&ok) = weight.toDouble(&ok) * ((height.toDouble(&ok)/100)*(height.toDouble(&ok)/100)) ;
     if(firstName == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter first name \n ");
     }
     if(lastName == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter last name \n ");
     }
     if(username == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter username \n ");
     }
     if(password == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter password \n ");
     }
     if(gender == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter gender \n ");
     }
     if(weight == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter weight \n ");
     }
     if(height == "") {
       QMessageBox::information(this,"REGISTER FAILED","enter height \n ");
     }

     else {
         QMessageBox::information(this,"REGISTER SUCCESSFUL","Registration process is successful \nNow you can login in  ");
         //add into database
         db_fitnessFirst db_f1("database.db") ;
         db_f1.createTable();
         db_f1.addUser(
             username,
             password,
             firstName,
             lastName,
             gender,
             age,
             height,
             weight,
             bmicalc
                     );
     }


}

void fitnessFirst::on_pushButton_clicked()
{
    QString username , password ;

    username = ui-> loginusername ->text();
    password = ui-> loginpass ->text();

    db_fitnessFirst db_f1("database.db") ;

    if(!db_f1.userAuth(username,password)){
      qDebug()<<"Login failed";
      QMessageBox::information(this,"LOGIN FAILED","Login failed  \n enter your data again ");
       }
    else {
         qDebug()<<"Login Success";
         QMessageBox::information(this,"LOGIN SUCCESS","Login successful  \n enjoy ! ");
         this->hide();
         home = new Home(this, username);
         home->show();
     }

}


