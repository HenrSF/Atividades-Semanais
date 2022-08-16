#ifndef BULL_HPP
#define BULL_HPP

#include "Animals.hpp"

class Bull : public Animals
{
    public: 
      Bull(Gender gender, float weight);

      virtual void displacement ();
      virtual float eat ();
      virtual float price ();
      virtual void print ();
    
      virtual void set_weight(float );

    private:
        static float price_kg;
};
#endif