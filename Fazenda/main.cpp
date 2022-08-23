#include <iostream>
#include "Bull.hpp"
#include "Pig.hpp"

int main()
{
    Bull bull(Gender::Male, 450, 10);
    Pig *pig = new Pig(Gender::Female, 100, 3);

    for(int i = 0; i < 20; i++)
    {
        bull.eat();
        pig->eat();
    }

    Bull::setprice_kg(30);
    Pig::setprice_kg(20);

    bull.print();
    pig->print();
    
    return 0;
}