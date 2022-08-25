#ifndef BULL_HPP
#define BULL_HPP

#include "Animals.hpp"

namespace BULL
{
extern float min_weight;
extern float max_weight;
extern int max_age; //months
extern float food;
extern float walk;
extern string cry;
}

class Bull : public Animals
{
    public:

      Bull(Gender gender, float weight, int age); //Constructor;
      ~Bull(); //Destructor;

      virtual void displacement ();
      virtual bool eat ();
      virtual float price (); 
      virtual void print ();
      virtual string sound () const;

      //Setters
      virtual void setweight(float );
      static void setprice_kg(float price);
      virtual void setage(int age);

      //Getters
      static float getprice_kg() {return price_kg;}
      static int getn_bulls()    {return n_bulls;}

    private:
    
        static float price_kg;
        static int n_bulls;
};
#endif