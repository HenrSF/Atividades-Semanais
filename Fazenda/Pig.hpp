#ifndef PIG_HPP
#define PIG_HPP

#include "Animals.hpp"

namespace PIG
{
extern float min_weight;
extern float max_weight;
extern int max_age; //months
extern float food;
extern float weight_loss;
extern string cry;
}

class Pig : public Animals
{
    public:

        Pig(Gender gender, float weight, int age); //Constructor
        ~Pig(); //Destructor

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
        static int getn_pigs()    {return n_pigs;}

    private:
    
        static float price_kg;
        static int n_pigs; //number of pings being raised in the farm
};
#endif
