#include "Pig.hpp"

float Pig::price_kg;
int Pig::n_pigs;


namespace PIG
{
float min_weight = 60;
float max_weight = 120;
int max_age = 6;    //Months
float food = 2;     //Amount (kg) of weight this animal can gain
float weight_loss = 0.003; //Weight loss in percentage of the current weight of the animal
string cry = "OINC OINC!"; //Onomatopoeia (portuguese - BR)
}

Pig::Pig(Gender gender, float weight, int age)
    : Animals (gender, Type_Pig)
{
    
    setweight(weight);
    setage(age);
    n_pigs++;
}

Pig::~Pig()
{
    n_pigs--;
}

string Pig::sound() const
{
    return PIG::cry; //Remind of change;
}

void Pig::displacement() //everytime this function is called the animal will move a fixed distance.
{
    float w = getweight() - (getweight() * PIG::weight_loss); //the animal loses weight at a fixed amount

    if(w <= PIG::min_weight) //the animal has a minimum weight value and it'll be set at 300 if any given value is below that
    setweight(w);
}

void Pig::setweight(float w) 
{
    if (w > PIG::max_weight && w < PIG::min_weight)
    {
        Animals::setweight((PIG::max_weight + PIG::min_weight) / 2); //if the input value is invalid, it'll be set to have the mean between max and min values; 
    }

    Animals::setweight(w);
}

 void Pig::setprice_kg(float kg)
{
    if(kg > 0) price_kg = kg;

    else price_kg = 30;
}

float Pig::price()
{
    return getweight() * price_kg; //returns the revenue of an animal
}

void Pig::eat()// bool
{
    if(getweight() + PIG::food >= PIG::max_weight) //the animal's weight cannot be above the maximum 
    {
        setoverweight();
    }

    else
    {
        setweight(getweight() + PIG::food); //the animal gain a fixed amount of weight
    }
}

void Pig::setage(int n)
{
    if(n > 0 && n <= PIG::max_age) //the animal has a maximum age which is going to be considered when or not it'll be killed
    {
        Animals::setage(n);
    }

    else Animals::setage(1); //if the input value is an invalid one. The age will be 1 (month)
}
void Pig::print()
{

    cout << "Pig   "
         << "\nAge:    " << getage() << " Months" << fixed << setprecision(3)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender() << setprecision(2)
         << "\nPrice:  R$" << price();
}
