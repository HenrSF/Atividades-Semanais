#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "Animals.hpp"

namespace CHICKEN
{
extern float min_weight;
extern float max_weight;
extern int max_age; //Days
extern float food;
extern float walk;
extern string cry;
}

class Chicken : public Animals
{
    public:

      Chicken(Gender gender, float weight, int age); //Constructor;
      ~Chicken(); //Destructor;

      virtual void displacement ();
      virtual void eat ();
      virtual float price (); 
      virtual void print ();
      virtual string sound () const;

      //Setters
      virtual void setweight(float );
      static void setprice_kg(float price);
      virtual void setage(int age);

      //Getters
      static float getprice_kg() {return price_kg;}
      static int getn_chickens()    {return n_chickens;}

    private:
    
        static float price_kg;
        static int n_chickens; //number of chickens being raised in the farm
};
#endif
