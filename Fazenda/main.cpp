#include <iostream>
#include "Bull.hpp"
#include "Pig.hpp"
#include "Chicken.hpp"
#include "Duck.hpp"

int main()
{
    Bull bull(Gender::Male, 450, 10);
    Pig pig (Gender::Female, 100, 3);
    Chicken chicken(Gender::Female, 1.2, 15);
    Duck duck(Gender::Male, 2.3, 10);

    for(int i = 0; i < 20; i++)
    {
        bull.eat();
        pig.eat();
        chicken.eat();
        duck.eat();
    }

    for (int i = 0; i < 30; i++)
    {
        bull.displacement();
        pig.displacement();
        chicken.displacement();
        duck.displacement();
    }

    Bull::setprice_kg(35);
    Pig::setprice_kg(22);
    Chicken::setprice_kg(18);
    Duck::setprice_kg(32);

    bull.print();
    pig.print();
    chicken.print();
    duck.print();
    
    return 0;
}