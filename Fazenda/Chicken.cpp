#include "Chicken.hpp"

float Chicken::price_kg;
int Chicken::n_chickens;

namespace CHICKEN //Falta ajeitar;
{
float min_weight = 0.9;
float max_weight = 1.8;
int max_age = 30;   //Days
float food = 0.2;   //Amount (kg) of weight this animal can gain
float weight_loss = 0.001; //Weight loss in percentage of the current weight of the animal
string cry = "CÓ CÓ!"; //Onomatopoeia (portuguese - BR)
}

Chicken::Chicken(Gender gender, float weight, int age)
    : Animals (gender)
{
    
    setweight(weight);
    setage(age);
    n_chickens++;
}

Chicken::~Chicken()
{
    n_chickens--;
}

string Chicken::sound() const
{
    return CHICKEN::cry;
}

void Chicken::displacement() //everytime this function is called the animal will move a fixed distance.
{
    float w = getweight() - (getweight() * CHICKEN::weight_loss); //the animal loses weight at a fixed amount

    if(w <= CHICKEN::min_weight) //the animal has a minimum weight value and it'll be set at 300 if any given value is below that
    setweight(w);
}

void Chicken::setweight(float w) 
{
    if (w > CHICKEN::max_weight && w < CHICKEN::min_weight)
    {
        Animals::setweight((CHICKEN::max_weight + CHICKEN::min_weight) / 2); //if the input value is invalid, it'll be set to have the mean between max and min values  
    }

    Animals::setweight(w);
}

 void Chicken::setprice_kg(float kg)
{
    if(kg > 0) price_kg = kg;

    else price_kg = 30;
}

float Chicken::price()
{
    return getweight() * price_kg; //returns the revenue of an animal
}

void Chicken::eat()
{
    if(getweight() + CHICKEN::food >= CHICKEN::max_weight) //the animal's weight cannot be above the maximum
    {
        setoverweight();
    }

    else
    {
        setweight(getweight() + CHICKEN::food); //the animal gain a fixed amount of weight
    }
}

void Chicken::setage(int n)
{
    if(n > 0 && n <= CHICKEN::max_age) //the animal has a maximum age which is going to be considered when or not it'll be killed
    {
        Animals::setage(n);
    }

    else Animals::setage(1); //if the input value is an invalid one. The age will be 1 (day)
}
void Chicken::print()
{
    cout << "\n\nChicken "
         << "\nAge:    " << getage() << " Days" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}
