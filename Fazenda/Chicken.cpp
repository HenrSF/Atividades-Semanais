#include "Chicken.hpp"

string Chicken::sound()
{
    return "có có!";
}
bool Chicken::displacement()
{
    if (displacement() == true)
    {
        return false;
    }
    
    else return true;
}

int Chicken::getweight() const
{   
    if(weight != 0) return weight;
}

void Chicken::setweight(int bw)
{
    weight = bw;
}


float Chicken::mass()
{
    if(displacement() == true)
    {
        return weight * 0,04;
    }
    else return weight;
}

float Chicken::price()
{
    return weight * 10;
}

float Chicken::eat()
{
    if(weight < 1.8) return weight + 5;
    
    if (weight + 5 > 1.8)
    {
        return 1.8;
    }
}