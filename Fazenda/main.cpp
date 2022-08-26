#include <iostream>

#include "Farm.hpp"

int main()
{
    srand(time(NULL));

    Farm farm ("city", "state", 50);

    for (int i = 0; i < 100; i++)
    {
    farm.Add_toFarm (Type_Animal (rand() % 5));
    }

    farm.print();

    farm.feed(2);

    farm.print();

    farm.displacement(20);
    farm.Rm_fromFarm(10);

    farm.print();

    return 0;
}