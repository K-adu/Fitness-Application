#ifndef BMI_H
#define BMI_H

#include<string.h>
#include <QApplication>

using namespace std;

class bmi
{

public:
        //default constructor
       bmi(){
           newHeight = 0.0;
           newWeight = 0.0;
       }
        //parameterized constructor
        bmi(double height ,double weight)
        {

        newHeight = height ;
        newWeight = weight ;
        }


      //  ~bmi();


        //getter function returns the value of height and weight
        double getHeight()
        {
            return newHeight;
        }

        double getWeight()
        {
            return newWeight;
        }


        //setter function takes the value of height and weight from the user
        void setHeight (double height)
        {
            newHeight=height;
        }
        void setWeight (double weight)
        {
            newWeight=weight;
        }

        // function to calculate BMI
        double calculateBMI()
        {
            newHeight= newHeight / 100;
            return (newWeight/(newHeight*newHeight));
        }

      //Data members stored as private access specifier
private:

    double newHeight;
    double newWeight;
};


#endif // BMI_H
