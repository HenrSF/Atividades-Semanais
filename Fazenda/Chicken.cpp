#include "Chicken.hpp"

float Chicken::price_kg;
int Chicken::n_chickens;

namespace CHICKEN //Falta ajeitar;
{
float min_weight = 0.9;
float max_weight = 1.8;
int max_age = 2; //months
float food = 0.2;
string cry = "có có!";
}

Chicken::Chicken(Gender gender, float weight, int age)
    : Animals (gender)
{
    //TODO: codigos adicionais do construtor
    setweight(weight);
    setage(age);
    n_chickens++;
}

Chicken::~Chicken()
{
    n_chickens--;
    cout << "\nAnimal slaughtered.";
}

string Chicken::sound() const
{
    return CHICKEN::cry; //Remind of change;
}

void Chicken::displacement()
{
    float w = getweight() - (getweight() * 0.004);

    if(w <= Chicken::min_weight)
    setweight(w);
}

void Chicken::setweight(float w) 
{
    if (w > Chicken::max_weight && w < Chicken::min_weight)
    {
        Animals::setweight((Chicken::max_weight + Chicken::min_weight) / 2); //if the input value is invalid, it'll be setted has the mean between max and min values; 
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
    return getweight() * price_kg;
}

bool Chicken::eat()
{
    if(getweight() + Chicken::food >= Chicken::max_weight)
    {
        return true; //in this way, will the object be deleted from the vector animals?    
    }

    else
    {
        setweight(getweight() + Chicken::food);
        return false;
    }
}

void Chicken::setage(int n)
{
    if(n > 0 && n <= Chicken::max_age)
    {
        Animals::setage(n);
    }

    else Animals::setage(1);
}
void Chicken::print()
{

    cout << "\nchicken    "
         << "\nAge:    " << getage()
         << "\nWeight: " << getweight()
         << "\nGender: " << getgender()
         << "\nPrice:  " << price();
}