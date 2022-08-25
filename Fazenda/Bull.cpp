#include "Bull.hpp"

float Bull::price_kg;
int Bull::n_bulls;

namespace BULL
{
float min_weight = 300;
float max_weight = 600;
int max_age = 18; //months
float food = 5;
float walk = 0.004;
string cry = "MUUUU!";
}

Bull::Bull(Gender gender, float weight, int age)
    : Animals (gender)
{
    //TODO: codigos adicionais do construtor
    setweight(weight);
    setage(age);
    n_bulls++;
}

Bull::~Bull()
{
    n_bulls--;
    cout << "\nAnimal slaughtered.";
}

string Bull::sound() const
{
    return BULL::cry; //Remind of change;
}

void Bull::displacement()
{
    float w = getweight() - (getweight() * BULL::walk);

    if(w <= BULL::min_weight)
    setweight(w);
}

void Bull::setweight(float w) 
{
    if (w > BULL::max_weight && w < BULL::min_weight)
    {
        Animals::setweight((BULL::max_weight + BULL::min_weight) / 2); //if the input value is invalid, it'll be setted has the mean between max and min values; 
    }

    Animals::setweight(w);
}

 void Bull::setprice_kg(float kg)
{
    if(kg > 0) price_kg = kg;

    else price_kg = 30;
}

float Bull::price()
{
    return getweight() * price_kg;
}

bool Bull::eat()
{
    if(getweight() + BULL::food >= BULL::max_weight)
    {
        return true; //in this way, will the object be deleted from the vector animals?    
    }

    else
    {
        setweight(getweight() + BULL::food);
        return false;
    }
}

void Bull::setage(int n)
{
    if(n > 0 && n <= BULL::max_age)
    {
        Animals::setage(n);
    }

    else Animals::setage(1);
}
void Bull::print()
{

    cout << "\n\nBull  "
         << "\nAge:    " << getage() << " Months" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}