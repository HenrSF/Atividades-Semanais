#ifndef BULL_HPP
#define BULL_HPP

#include "Animals.hpp"

class Bull : public Animals
{
    public:  
      virtual string sound(); 
      virtual bool displacement ();
      virtual float eat ();
      virtual float mass();
      virtual float price ();
      virtual void print ();
    
    void set_weight(int );
    int get_weight() const;

    private:
        int weight;
};
#endif