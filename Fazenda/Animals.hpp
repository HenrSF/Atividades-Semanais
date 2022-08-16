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

      Animals (Gender gender, float weight); //constructor;

      virtual string sound () = 0;
      virtual void displacement () = 0;
      virtual float eat () = 0;
      virtual void print () = 0;

      //Methods get:
      float getweight() {return weight;}
      float getgender() {return gender;}

      //Methods set:
      virtual void setweight (float weight) = 0;

    private:

      Gender gender;
      float weight;
};
#endif