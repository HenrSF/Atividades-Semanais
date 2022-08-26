#ifndef ANIMALS_HPP
#define ANIMALS_HPP

using namespace std;

#include <string>
#include <iostream>
#include <iomanip>

enum Gender //linking a gender to a number (starting from 0)
{
  Male,
  Female
};

enum Type_Animal //linking an animal type to a number (starting from 0)
{
    Type_Bull, Type_Pig, Type_Duck, Type_Chicken
};

class Animals
{
    public:

      Animals(Gender gender); //constructor;
      virtual ~Animals();
      
      virtual string sound() const = 0;
      virtual void displacement()  = 0;
      virtual float price()        = 0;
      virtual void eat()           = 0;
      virtual void print()         = 0;

      //Getters:
      virtual float getweight() const {return weight;}
      virtual string getgender() const {return gender;}
      virtual int getage()      const {return age;}
      virtual bool getoverweight() {return overweight;}
      virtual Type_Animal gettype() const {return type;}

      //Setters:
      virtual void setweight(float weight);
      virtual void setage(int age);
      virtual void setoverweight();
    
    private:
      
      int age;
      string gender;
      float weight;
      bool overweight;
      Type_Animal type;
      
      virtual void settype(Type_Animal type) {this->type = type;} //Private set type;
};
#endif
