
#include "Animals.hpp"

Animals::Animals(Gender gender)
{
    if(gender == Gender::Male)
    this->gender = "Male";

    else
    this->gender = "Female";

    overweight = false;
}

void Animals::setage(int n)
{
      age = n;  
}

void Animals::setweight(float n)
{
    weight = n;
}

void Animals::setoverweight()
{
    overweight = true;
}