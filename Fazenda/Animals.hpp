#ifndef ANIMALS_HPP
#define ANIMALS_HPP

using namespace std;

#include <string>
#include "Farm.hpp"

class Animals : public Farm
{
    public:
      virtual string sound () = 0;
      virtual bool displacement () = 0;
      virtual float eat () = 0;
      virtual float mass() = 0;
      virtual float price () = 0;
      virtual void print () = 0; 
      
    private:

};
#endif