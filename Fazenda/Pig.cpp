#include "Pig.hpp"

string Pig::sound()
{
    return "oinc oinc!";
}
bool Pig::displacement()
{
    if (displacement() == true)
    {
        return false;
    }
    
    else return true;
}

int Pig::getweight() const
{   
    if(weight != 0) return weight;
}

void Pig::setweight(int bw)
{
    weight = bw;
}


float Pig::mass()
{
    if(displacement() == true)
    {
        return weight * 0,04;
    }
    else return weight;
}

float Pig::price()
{
    return weight * 10;
}

float Pig::eat()
{
    if(weight < 120) return weight + 5;
    
    if (weight + 5 > 120)
    {
        return 120;
    }
}