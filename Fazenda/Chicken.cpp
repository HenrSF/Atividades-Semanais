#include "Chicken.hpp"

float Chicken::price_kg;
int Chicken::n_chickens;

namespace CHICKEN //Falta ajeitar;
{
float min_weight = 0.9;
float max_weight = 1.8;
int max_age = 30; //Days
float food = 0.2;
float walk = 0.001;
string cry = "CÓ CÓ!";
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
}

string Chicken::sound() const
{
    return CHICKEN::cry;
}

void Chicken::displacement()
{
    float w = getweight() - (getweight() * CHICKEN::walk);

    if(w <= CHICKEN::min_weight)
    setweight(w);
}

void Chicken::setweight(float w) 
{
    if (w > CHICKEN::max_weight && w < CHICKEN::min_weight)
    {
        Animals::setweight((CHICKEN::max_weight + CHICKEN::min_weight) / 2); //if the input value is invalid, it'll be setted has the mean between max and min values; 
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

void Chicken::eat()
{
    if(getweight() + CHICKEN::food >= CHICKEN::max_weight)
    {
        setoverweight();
    }

    else
    {
        setweight(getweight() + CHICKEN::food);
    }
}

void Chicken::setage(int n)
{
    if(n > 0 && n <= CHICKEN::max_age)
    {
        Animals::setage(n);
    }

    else Animals::setage(1);
}
void Chicken::print()
{
    cout << "\n\nChicken "
         << "\nAge:    " << getage() << " Days" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}