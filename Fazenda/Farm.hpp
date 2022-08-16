#ifndef FARM_HPP
#define FARM_HPP

using namespace std;

#include "Animals.hpp"
#include <list>

class Farm
{
    public:
        Farm(string city, string state, float area);
        ~Farm();

    private:

    list <Animals *> 
};
#endif