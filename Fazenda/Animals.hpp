#ifndef ANIMALS_HPP
#define ANIMALS_HPP

using namespace std;

#include <string>
#include <iostream>
#include <iomanip>

enum Gender
{
  Male,
  Female
};

class Animals
{
    public:

      Animals(Gender gender); //constructor;

      virtual string sound() const = 0;
      virtual void displacement()  = 0;
      virtual float price()        = 0;
      virtual bool eat()           = 0;
      virtual void print()         = 0;

      //Getters:
      virtual float getweight() const {return weight;}
      virtual string getgender() const {return gender;}
      virtual int getage()      const {return age;}

      //Setters:
      virtual void setweight(float weight);
      virtual void setage(int age);
    
    private:
      
      int age;
      string gender;
      float weight;

};
#endif