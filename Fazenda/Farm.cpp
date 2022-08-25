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