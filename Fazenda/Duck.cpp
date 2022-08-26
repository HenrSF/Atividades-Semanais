#include "Duck.hpp"

float Duck::price_kg;
int Duck::n_ducks;

namespace DUCK
{
float min_weight = 2.25;
float max_weight = 4.5;
int max_age = 60; //Days
float food = 0.5; //Amount (kg) of weight this animal can gain
float weight_loss = 0.002; //Weight loss in percentage of the current weight of the animal
string cry = "QUÁ QUÁ!"; //Onomatopoeia (portuguese - BR)
}

Duck::Duck(Gender gender, float weight, int age)
    : Animals (gender)
{
    
    setweight(weight);
    setage(age);
    n_ducks++;
}

Duck::~Duck()
{
    n_ducks--;
}

string Duck::sound() const
{
    return DUCK::cry;
}

void Duck::displacement() //everytime this function is called the animal will move a fixed distance.
{
    float w = getweight() - (getweight() * DUCK::weight_loss); //the animal loses weight at a fixed amount

    if(w <= DUCK::min_weight) //the animal has a minimum weight value and it'll be set at 300 if any given value is below that
    setweight(w);
}

void Duck::setweight(float w) 
{
    if (w > DUCK::max_weight && w < DUCK::min_weight)
    {
        Animals::setweight((DUCK::max_weight + DUCK::min_weight) / 2); //if the input value is invalid, it'll be set to have the mean between max and min values;
    }

    Animals::setweight(w);
}

 void Duck::setprice_kg(float kg)
{
    if(kg > 0) price_kg = kg;

    else price_kg = 30;
}

float Duck::price()
{
    return getweight() * price_kg; //returns the revenue of an animal
}

void Duck::eat()
{
    if(getweight() + DUCK::food >= DUCK::max_weight) //the animal's weight cannot be above the maximum 
    {
        setoverweight();
    }

    else
    {
        setweight(getweight() + DUCK::food); //the animal gain a fixed amount of weight
    }
}

void Duck::setage(int n)
{
    if(n > 0 && n <= DUCK::max_age) //the animal has a maximum age which is going to be considered when or not it'll be killed
    {
        Animals::setage(n);
    }

    else Animals::setage(1); //if the input value is an invalid one. The age will be 1 (day)
} 

void Duck::print()
{
    cout << "\n\nDuck    "
         << "\nAge:    " << getage() << " Days" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}
