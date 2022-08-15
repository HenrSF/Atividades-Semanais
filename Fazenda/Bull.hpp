#ifndef BULL_HPP
#define BULL_HPP

#include "Animals.hpp"

class Bull : public Animals
{
    public: 
      virtual void displacement ();
      virtual float eat ();
      virtual float mass();
      virtual float price ();
      virtual void print ();
    
    void set_weight(int );
    int get_weight() const;

    private:
        int weight;
        static double price_kg;
};
#endif