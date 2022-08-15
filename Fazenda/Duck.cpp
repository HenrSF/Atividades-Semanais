#include "Duck.hpp"

string Duck::sound()
{
    return "quack! ";
}
bool Duck::displacement()
{
    if (displacement() == true)
    {
        return false;
    }
    
    else return true;
}

int Duck::getweight() const
{   
    if(weight != 0) return weight;
}

void Duck::setweight(int bw)
{
    weight = bw;
}


float Duck::mass()
{
    if(displacement() == true)
    {
        return weight * 0,04;
    }
    else return weight;
}

float Duck::price()
{
    return weight * 10;
}

float Duck::eat()
{
    if(weight < 120) return weight + 5;
    
    if (weight + 5 > 120)
    {
        return 120;
    }
}