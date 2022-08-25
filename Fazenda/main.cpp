#include <iostream>

#include "Farm.hpp"

int main()
{
    Farm farm("city", "state", 50);

    farm.Add_toFarm (new Bull(Gender::Male, 450, 10));

    farm.Add_toFarm (Type_Animal::Bull);

    
    return 0;
}