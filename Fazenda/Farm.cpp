#include "Farm.hpp"

Farm::Farm(string city, string state, float area) //constructor
{
    SetArea(area);
    SetCity(city);
    SetState(state);
    setPrice_kg(35, 28, 32, 20);
}

Farm::~Farm() //destructor
{
    for(size_t i = 0; i < farm.size(); i++) 
    {
        delete farm[i];
    }

    farm.clear();

    cout << "\nGoodbye farm!" << endl;
}

void Farm::Add_toFarm(Type_Animal type) //add an animal based on it's type to the farm's vector
{
    farm.push_back(CreateAnimal(type));
}

Animals* Farm::CreateAnimal(Type_Animal type) //the animals are random generated (including gender, weight, age)
{
    switch(type)
    {
        case Type_Animal::Type_Bull:     
            return new Bull(Gender (rand() % 2), float (BULL::min_weight + (rand()) * (BULL::max_weight - BULL::min_weight) / RAND_MAX), int (rand() % BULL::max_age));
            break;

        case Type_Animal::Type_Pig:
            return new Pig(Gender (rand() % 2), float (PIG::min_weight + (rand()) * (PIG::max_weight - PIG::min_weight) / RAND_MAX), int (rand() % PIG::max_age));
            break;
        
        case Type_Animal::Type_Duck:
            return new Duck(Gender (rand() % 2), float (DUCK::min_weight + (rand()) * (DUCK::max_weight - DUCK::min_weight) / RAND_MAX), int (rand() % DUCK::max_age));
            break;
        
        default:
            return new Chicken(Gender (rand() % 2), float (CHICKEN::min_weight + (rand()) * (CHICKEN::max_weight - CHICKEN::min_weight) / RAND_MAX), int (rand() % CHICKEN::max_age));
            break;
    }
}

void Farm::print()
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "\n\nCity: " << GetCity()
         << "\nState: " << GetState() << fixed << setprecision(2)
         << "\nArea: " << GetArea() << "m²"
         << "\nNumber of animals: " << farm.size()
         << "\nNumber of bulls: " << Bull::getn_bulls()
         << "\nNumber of pigs: " << Pig::getn_pigs()
         << "\nNumber of ducks: " << Duck::getn_ducks()
         << "\nNumber of chickens: " << Chicken::getn_chickens()
         << "\nTotal price: R$" << total_price()
         << "\nRevenue: R$" << income << endl;
}

void Farm::print_animal(int index)
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    farm[index]->print();
}

float Farm::total_price() const
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    float price;

    for(size_t i = 0; i < farm.size(); i++) 
    {
        price += farm[i]->price(); //gives the price of all current living animals
    }

    return price;
}

float Farm::price(int index) const
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    return farm[index]->price();
}

void Farm::Rm_fromFarm(int index)
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    delete farm[index];
    farm.erase(farm.begin() + index);
}

void Farm::clear_farm()
{
    for(size_t i = 0; i < farm.size(); i++)
    {
        delete farm[i];
    }

    farm.erase(farm.begin(), farm.end());
    cout << "\nFarm cleared!";
}

void Farm::feed(int times)
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < times; i++)
    for(size_t j = 0; j < farm.size(); j++)
    {
        farm[j]->eat();

        if(farm[j]->getoverweight())
        {
            income += farm[j]->price();
            delete farm[j];
            farm.erase(farm.begin() + j);
            j--;
        }
    }
}

void Farm::displacement(int times)
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < times; i++)
    for(size_t j = 0; j < farm.size(); j++)
    {
        farm[j]->displacement();
    }
}

void Farm::setPrice_kg(float bull, float pig, float duck, float chicken)
{
    Bull::setprice_kg(bull);
    Pig::setprice_kg(pig);
    Duck::setprice_kg(duck);
    Chicken::setprice_kg(chicken);
}
