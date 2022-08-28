#include <iostream>
#include <fstream>

#include "Farm.hpp"

int main()
{
    srand(time(NULL));

    Farm farm ("city", "state", 50);

    for (int i = 0; i < 5; i++)
    {
    farm.Add_toFarmRDM (Type_Bull);
    }

    farm.print();
 
    farm.feed(2);

    farm.print();

    for (int i = 1; i <= 5; i++)
    farm.print_animal(Type_Bull, i);

    return 0;

}
