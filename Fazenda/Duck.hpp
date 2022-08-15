#ifndef DUCK_HPP
#define DUCK_HPP

#include "Animals.hpp"

class Duck : public Animals
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