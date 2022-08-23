#include "Pig.hpp"

float Pig::price_kg;
int Pig::n_pigs;


namespace PIG
{
float min_weight = 60;
float max_weight = 120;
int max_age = 6; //months
float food = 2;
string cry = "oinc oinc!";
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
    float w = getweight() - (getweight() * 0.004);

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

bool Pig::eat()// bool
{
    if(getweight() + PIG::food >= PIG::max_weight)// USar um bool para validar e remover da lista, na classe fazenda
    {
        return true;//delete this;// don't use that; //in this way, will the object be deleted from the vector animals?    
    }

    else
    {
        setweight(getweight() + PIG::food);
        return false;
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

    cout << "\nPig    "
         << "\nAge:    " << getage()
         << "\nWeight: " << getweight()
         << "\nGender: " << getgender()
         << "\nPrice:  " << price();
}