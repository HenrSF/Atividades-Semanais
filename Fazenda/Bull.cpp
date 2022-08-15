#include "Bull.hpp"

string Bull::sound()
{
    return "muu!";
}
bool Bull::displacement()
{
    if (displacement() == true)
    {
        return false;
    }
    
    else return true;
}

int Bull::get_weight() const
{   
    if(weight != 0) return weight;
}

void Bull::set_weight(int bw)
{
    weight = bw;
}


float Bull::mass()
{
    if(displacement() == true)
    {
        return weight * 0,04;
    }
    else return weight;
}

float Bull::price()
{
    return weight * 10;
}

float Bull::eat()
{
    if(weight < 120) return weight + 5;
    
    if (weight + 5 > 120)
    {
        return 120;
    }
}