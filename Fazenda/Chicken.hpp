#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "Animals.hpp"

class Chicken : public Animals
{
    public:
     virtual string sound ();
     virtual bool displacement ();
     virtual float eat ();
     virtual float mass();
     virtual float price ();
     virtual void print ();
    
     int getweight() const;
     void setweight(int weight);

    private:
        int weight;
        

};
#endif