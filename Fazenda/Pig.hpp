#ifndef PIG_HPP
#define PIG_HPP

#include "Animals.hpp"

class Pig : public Animals
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