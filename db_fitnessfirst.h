#ifndef DB_FITNESSFIRST_H
#define DB_FITNESSFIRST_H

#include <QSqlDatabase>
#include<QList>

class db_fitnessFirst
{
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up connection with db and opens it
     * @param path - absolute path to db file
     */
    db_fitnessFirst(const QString& path);

    /**
     * @brief Destructor
     *
     * Close the db connection
     */
    ~db_fitnessFirst();

    bool isOpen() const;

    /**
     * @brief Creates a new 'user' table if it doesn't already exist
     * @return true - 'user' table created successfully, false - table not created
     */
    bool createTable();

    /**
     * @brief Add user data to db
     * @param username - add username
     * @param password - password of user to add
     * @param fname
     * @param lname
     * @param gender
     * @param age
     * @param height
     * @param weight
     * @return true - person added successfully, false - person not added
     */
    bool addUser(const QString& username,const QString& password,const QString& fname,const QString& lname,const QString& gender,const QString& age,const QString& height, const QString& weight,double bmicalc);

    /*
      add username, password ,fname , lname , gender , age ,height , weight
     */
    bool addBmiData(const QString& username,double bmi);

    /*
      add bmi in table after calculation
     */

    double checkbmifordiet(const QString &username);

    /**
     * @brief Remove users data from db
     * @param email - email of user to remove.
     * @return true - user removed successfully, false - user not removed
     */
//    bool removeUser(const QString& name);



//    /**
//     *@brief Check if the email is already taken
//     */
//    bool emailExists(const QString& email);


//    void printAllUsers() const;

//    /**
//     * @brief Remove all users email from db
//     * @return true - all users removed successfully, false - not removed
//     */
//    bool removeAllUsers();


//    /**
//     * @brief Authenticate the users via user email and password
//     * @return db_primary_key - , 0 - log in failed
//     */
    bool userAuth(const QString& name, const QString& pass) const;

    /**
     * @brief Get all the user data from the database
     * @return Returns list of strings
     */
     QList<QString> getUserInfo(const QString& email)const;

    /**
     * @brief Get all the email/id of the registerd users from database
     * @return Returns list of strings
     */
     QList<QString> getAllUsers();

public:
    QSqlDatabase m_db;
};


#endif // DB_FITNESSFIRST_H
