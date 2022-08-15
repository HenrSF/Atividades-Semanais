#ifndef ANIMALS_HPP
#define ANIMALS_HPP

using namespace std;

#include <string>
#include <iostream>
#include <iomanip>

class Animals
{
    public:

      virtual string sound () = 0;
      virtual void displacement () = 0;
      virtual float eat () = 0;
      virtual float mass() = 0;
      virtual float price () = 0;
      virtual void print () = 0;

      //Methods get:

      //Methods set:
      
    private:

      float mass;
      string gender;
      float weight;
};
#endif