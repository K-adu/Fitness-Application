#include "db_fitnessfirst.h"

#include<QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

 db_fitnessFirst:: db_fitnessFirst(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()){
        qDebug() << "Error: connection with database fail";
    }else{
        qDebug() << "Database: connection ok";
    }
}

 db_fitnessFirst::~ db_fitnessFirst()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

bool  db_fitnessFirst::isOpen() const
{
    return m_db.isOpen();
}

bool  db_fitnessFirst::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE user(id INTEGER PRIMARY KEY, username TEXT,pass TEXT, fname TEXT, lname TEXT, gender TEXT, age TEXT,height TEXT, weight TEXT, bmicalc INTEGER);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'user': one might already exist.";
        success = false;
    }

    return success;
}

bool  db_fitnessFirst::addUser(const QString& username,const QString& password,const QString& fname,const QString& lname,const QString& gender,const QString& age,const QString& height, const QString& weight,double bmicalc){
    bool success = false;
    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO user(username, pass, fname, lname, gender, age, height, weight,bmicalc) VALUES (:username, :pass, :fname, :lname, :gender, :age ,:height , :weight ,:bmicalc)");
    queryAdd.bindValue(":username", username);
    queryAdd.bindValue(":pass", password);
    queryAdd.bindValue(":fname",fname);
    queryAdd.bindValue(":lname",lname);
    queryAdd.bindValue(":gender",gender);
    queryAdd.bindValue(":age",age);
    queryAdd.bindValue(":height",height);
    queryAdd.bindValue(":weight",weight);
    queryAdd.bindValue(":bmicalc",bmicalc);

    if(!queryAdd.exec()){
        qDebug() << "add user failed: " << queryAdd.lastError();
    }else{
        success = true;
    }
    return success;
}



//bool  db_fitnessFirst::removeUser(const QString& name){
//    bool success = false;

//    if (usernameExists(name)){
//        QSqlQuery queryDelete;
//        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
//        queryDelete.bindValue(":name", name);
//        success = queryDelete.exec();
//        if(!success){
//            qDebug() << "remove  failed: " << queryDelete.lastError();
//        }
//    }else{
//        qDebug() << "remove user failed: user doesnt exist";
//    }
//    return success;
//}




bool db_fitnessFirst::addBmiData(const QString &username,double bmi){
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM user WHERE username =('"+ username +"') ");
    if (checkQuery.exec()){
        int count=0;
        while(checkQuery.next())
            count++;
            if (count==1){
            QSqlQuery queryAdd;
            queryAdd.prepare("UPDATE user SET bmicalc = :bmi WHERE username =('"+username+"');");
            queryAdd.bindValue(":bmi",bmi);
            queryAdd.exec();
          }
     }
}



double db_fitnessFirst::checkbmifordiet(const QString &username){
      QSqlQuery checkQuery;
      checkQuery.prepare("SELECT bmicalc FROM user WHERE username =('"+ username +"')");
      if(checkQuery.exec()) {
          while(checkQuery.next()){
              return checkQuery.value(0).toDouble();         
       }
    }
}







bool  db_fitnessFirst::userAuth(const QString &username, const QString &pass)const{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT username FROM user WHERE username = (:username) AND pass = (:pass)");
    checkQuery.bindValue(":username", username);
    checkQuery.bindValue(":pass", pass);
    if (checkQuery.exec()){
        if (checkQuery.next()){
            exists = true;
        }
    }else{
        qDebug() << "user exists failed: " << checkQuery.lastError();
    }
    return exists;
}

//QList<QString>  db_fitnessFirst::getUserInfo(const QString& username) const{
//    QList<QString> userList;

//    qDebug() << "users in db:";
//    QSqlQuery query;
//    query.prepare("SELECT * FROM user WHERE email = (:email)");
//    query.bindValue(":email", email);

//    if(!query.exec()){
//        qDebug()<<"Query err"<<query.lastError();
//    }else{
//        //Query was sucessful :)
//        int email_id = query.record().indexOf("email");
//        int fname_id = query.record().indexOf("fname");
//        int lname_id = query.record().indexOf("lname");
//        int addr_id = query.record().indexOf("addr");
//        int phn_id = query.record().indexOf("phn");

//        if(query.next()){
//            QString email = query.value(email_id).toString();
//            QString fname = query.value(fname_id).toString();
//            QString lname = query.value(lname_id).toString();
//            QString addr = query.value(addr_id).toString();
//            QString phn = query.value(phn_id).toString();

//            userList.push_front(phn);
//            userList.push_front(addr);
//            userList.push_front(lname);
//            userList.push_front(fname);
//            userList.push_front(email);
//        }
//    }

//    return  userList;
//}

//QList<QString>  db_fitnessFirst::getAllUsers(){
//    QList<QString> data;

//    qDebug() << "users in db:";
//    QSqlQuery query("SELECT * FROM user");
//    int idName = query.record().indexOf("email");
//    while (query.next()){
//        QString email = query.value(idName).toString();
//        data.push_front(email);
//    }
//    return data;
//}
