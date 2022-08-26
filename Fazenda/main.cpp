#include <iostream>

#include "Farm.hpp"

int main()
{
    srand(time(NULL));

    Farm farm ("city", "state", 50);

    for (int i = 0; i < 50; i++)
    {
    farm.Add_toFarm (Type_Animal (rand() % 5));
    }
     
    farm.print();
    return 0;
}