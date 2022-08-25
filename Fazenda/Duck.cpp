#include "Duck.hpp"

float Duck::price_kg;
int Duck::n_ducks;

namespace DUCK
{
float min_weight = 2.25;
float max_weight = 4.5;
int max_age = 60; //Days
float food = 0.5;
float walk = 0.002;
string cry = "QUÁ QUÁ!";
}

Duck::Duck(Gender gender, float weight, int age)
    : Animals (gender)
{
    //TODO: codigos adicionais do construtor
    setweight(weight);
    setage(age);
    n_ducks++;
}

Duck::~Duck()
{
    n_ducks--;
    cout << "\nAnimal slaughtered.";
}

string Duck::sound() const
{
    return DUCK::cry;
}

void Duck::displacement()
{
    float w = getweight() - (getweight() * DUCK::walk);

    if(w <= DUCK::min_weight)
    setweight(w);
}

void Duck::setweight(float w) 
{
    if (w > DUCK::max_weight && w < DUCK::min_weight)
    {
        Animals::setweight((DUCK::max_weight + DUCK::min_weight) / 2); //if the input value is invalid, it'll be setted has the mean between max and min values; 
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
    return getweight() * price_kg;
}

bool Duck::eat()
{
    if(getweight() + DUCK::food >= DUCK::max_weight)
    {
        return true; //in this way, will the object be deleted from the vector animals?    
    }

    else
    {
        setweight(getweight() + DUCK::food);
        return false;
    }
}

void Duck::setage(int n)
{
    if(n > 0 && n <= DUCK::max_age)
    {
        Animals::setage(n);
    }

    else Animals::setage(1);
}

void Duck::print()
{
    cout << "\n\nDuck    "
         << "\nAge:    " << getage() << " Days" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}