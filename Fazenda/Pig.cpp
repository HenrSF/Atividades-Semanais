#include "Pig.hpp"

float Pig::price_kg;
int Pig::n_pigs;


namespace PIG
{
float min_weight = 60;
float max_weight = 120;
int max_age = 6; //months
float food = 2;
float walk = 0.003;
string cry = "OINC OINC!";
}

Pig::Pig(Gender gender, float weight, int age)
    : Animals (gender)
{
    //TODO: codigos adicionais do construtor
    setweight(weight);
    setage(age);
    n_pigs++;
}

Pig::~Pig()
{
    n_pigs--;
    cout << "\nAnimal slaughtered.";
}

string Pig::sound() const
{
    return PIG::cry; //Remind of change;
}

void Pig::displacement()
{
    float w = getweight() - (getweight() * PIG::walk);

    if(w <= PIG::min_weight)
    setweight(w);
}

void Pig::setweight(float w) 
{
    if (w > PIG::max_weight && w < PIG::min_weight)
    {
        Animals::setweight((PIG::max_weight + PIG::min_weight) / 2); //if the input value is invalid, it'll be setted has the mean between max and min values; 
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
    return getweight() * price_kg;
}

void Pig::eat()// bool
{
    if(getweight() + PIG::food >= PIG::max_weight)// USar um bool para validar e remover da lista, na classe fazenda
    {
        setoverweight();
    }

    else
    {
        setweight(getweight() + PIG::food);
    }
}

void Pig::setage(int n)
{
    if(n > 0 && n <= PIG::max_age)
    {
        Animals::setage(n);
    }

    else Animals::setage(1);
}
void Pig::print()
{

    cout << "\n\nPig   "
         << "\nAge:    " << getage() << " Months" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}