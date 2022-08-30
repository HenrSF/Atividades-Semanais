
#include "Animals.hpp"

Animals::Animals(Gender gender, Type_Animal type) //using a pointer to give an animal a gender
{
    if(gender == Gender::Male)
    this->gender = "Male";

    else
    this->gender = "Female";

    overweight = false;

    signature = type;
}

Animals::~Animals()
{

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
