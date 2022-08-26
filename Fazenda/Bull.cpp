#include "Bull.hpp"

float Bull::price_kg;
int Bull::n_bulls;

namespace BULL
{
float min_weight = 300;
float max_weight = 600;
int max_age = 18;   //months
float food = 5;     //amount (kg) of weight this animal can gain
float walk = 0.004; //distance travelled
string cry = "MUUUU!"; //onomatopoeia (portuguese - BR)
}

Bull::Bull(Gender gender, float weight, int age) //constructor
    : Animals (gender)
{
    setweight(weight);
    setage(age);
    
    n_bulls++;
}

Bull::~Bull() //destructor
{
    n_bulls--;
}

string Bull::sound() const
{
    return BULL::cry; 
}

void Bull::displacement() //everytime this function is called the animal will move a fixed distance.
{
    float w = getweight() - (getweight() * BULL::walk); //the animal loses weight at a fixed amount

    if(w <= BULL::min_weight) //the animal has a minimum weight value and it'll be set at 300 if any given value is below that
    setweight(w);
}

void Bull::setweight(float w) 
{
    if (w > BULL::max_weight && w < BULL::min_weight) 
    {
        Animals::setweight((BULL::max_weight + BULL::min_weight) / 2); //if the input value is invalid, it'll be set to have the mean between max and min values; 
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
    return getweight() * price_kg; //returns the revenue of an animal
}

void Bull::eat()
{
    if(getweight() + BULL::food >= BULL::max_weight) //the animal's weight cannot be above the maximum 
    {
        setoverweight();
    }

    else
    {
        setweight(getweight() + BULL::food); //the animal gain a fixed amount of weight
    }
}

void Bull::setage(int n)
{
    if(n > 0 && n <= BULL::max_age) //the animal has a maximum age which is going to be considered when or not it'll be killed
    {
        Animals::setage(n);
    }

    else Animals::setage(1); //if the input value is an invalid one. The age will be 1 (month)
}
void Bull::print()
{

    cout << "\n\nBull  "
         << "\nAge:    " << getage() << " Months" << fixed << setprecision(2)
         << "\nWeight: " << getweight() << " Kg"
         << "\nGender: " << getgender()
         << "\nPrice:  R$" << price();
}
