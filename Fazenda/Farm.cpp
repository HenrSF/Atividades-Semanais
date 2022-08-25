#include "Farm.hpp"

Farm::Farm(string city, string state, float area)
{
    SetArea(area);
    SetCity(city);
    SetState(state);
}

Farm::~Farm()
{
    farm.clear();
}

void Farm::Add_toFarm(Type_Animal type)
{
    farm.push_back(CreateAnimal(type));
}

Animals* Farm::CreateAnimal(Type_Animal type)
{
    switch(type)
    {
        case Type_Animal::Bull:
            //return new Bull(Gender(rand() % 2), float (BULL::min_weight + (rand()) * (BULL::max_weight - BULL::min_weight) / RAND_MAX), int (rand() % BULL::max_age));
            return new Bull(Gender::Female,10,2);
               
    }
}