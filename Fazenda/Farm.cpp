#include "Farm.hpp"

Farm::Farm(string city, string state, float area) //Constructor
{
    SetArea(area);
    SetCity(city);
    SetState(state);
    setPrice_kg(35, 28, 32, 20);
}

Farm::~Farm() //Destructor
{
    for(size_t i = 0; i < farm.size(); i++) 
    {
        delete farm[i]; 
    }

    farm.clear();

    cout << "\nGoodbye farm!" << endl;
}

void Farm::SetArea(float area)
{
    if(area <= 0)
    {
        this->area = 500;
    }

    this->area = area;
}

void Farm::Add_toFarm(Animals* animal)
{
    farm.push_back(animal);
}

void Farm::Add_toFarmRDM(Type_Animal type) //Add an animal based on it's type to the farm's vector
{
    farm.push_back(CreateAnimal(type));
}

Animals* Farm::CreateAnimal(Type_Animal type) //The animals are random generated (including gender, weight, age)
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

void Farm::print() //Print the Farm status;
{
    if(farm.empty()) //If the Farm is empty there is nothing to print;
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "\n\nCity: " << GetCity()
         << "\nState: " << GetState() << fixed << setprecision(2)
         << "\nArea: " << GetArea() << "m²"
         << "\nNumber of animals: " << farm.size()
         << "\n\nNumber of bulls: " << Bull::getn_bulls()
         << "\nPrice of bulls: R$" << price_type(Type_Bull)
         << "\nNumber of pigs: " << Pig::getn_pigs()
         << "\nPrice of pigs: R$" << price_type(Type_Pig)
         << "\nNumber of ducks: " << Duck::getn_ducks()
         << "\nPrice of ducks: R$" << price_type(Type_Duck)
         << "\nNumber of chickens: " << Chicken::getn_chickens()
         << "\nPrice of chickens: R$" << price_type(Type_Chicken)
         << "\n\nTotal price: R$" << total_price()
         << "\nRevenue: R$" << revenue << endl;
}

void Farm::print_animal(Type_Animal type ,int index) //Print the animal status by the index
{
    if(farm.empty()) //If the Farm is empty there is nothing to print;
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }
    if(index <= 0 || index > getn_animals_per_type(type))
    {
        cerr << "\nInvalid index value" << endl;
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int j = 0;
    
    while(i < farm.size())
    {
        if(farm[i]->gettype() == type)
        {
            if(j == index - 1)
            {
                cout << "\n\n" << index << "º ";
                farm[i]->print(); //Use the print method of the object by the pointer;
                break;
            }

            j++;
        }
        i++;
    }
}

float Farm::total_price() //Print the sum of all animal's price;
{
    if(farm.empty()) //If the Farm is empty there is nothing to return;
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    float price = 0;

    for(size_t i = 0; i < farm.size(); i++) 
    {
        price += farm[i]->price(); //Gives the price of all current living animals
    }

    return price;
}

float Farm::price_animal(Type_Animal type, int index) //Gives the price of one animal
{
    if(farm.empty()) //If the Farm is empty there is nothing to return;
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }
    if(index <= 0 || index > getn_animals_per_type(type))
    {
        cerr << "\nInvalid index value" << endl;
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int j = 0;
    
    while(i < farm.size())
    {
        if(farm[i]->gettype() == type)
        {
            if(j == index - 1)
            {
                break;
            }

            j++;
        }
        i++;
    }

    return farm[i]->price();
}

float Farm::price_type(Type_Animal type) //Gives the price of all animals of one type specified;
{
    if(farm.empty()) //If the Farm is empty there is nothing to return;
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }
    
    float price = 0;

    for(size_t i = 0; i < farm.size(); i++)
    {
        if(farm[i]->gettype() == type)
        {
            price += farm[i]->price(); //Gives the price of all current living animals
        }
    }

    return price;
}

void Farm::Rm_fromFarm(int index) //Remove animals from the farm
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
        exit(EXIT_FAILURE);
    }

    delete farm[index];
    farm.erase(farm.begin() + index);
}

void Farm::clear_farm() //Remove all animals from the farm
{
    for(size_t i = 0; i < farm.size(); i++) //Delete all the objects
    {
        delete farm[i];
    }

    farm.erase(farm.begin(), farm.end()); //
    cout << "\nFarm cleared!";
}

void Farm::feed(int times) //Feed all the animals of the farm by a number of times

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
            revenue += farm[j]->price(); //Return the price of the animals killed

            delete farm[j];
            farm.erase(farm.begin() + j);
            j--;
        }
    }
}

void Farm::feed_type(Type_Animal type, int times)
{
    if(farm.empty())
    {
        cerr << "\nFarm is empty" << endl;
       exit(EXIT_FAILURE);
    }

    for(int i = 0; i < times; i++)
    for(size_t j = 0; j < farm.size(); j++)
    {
        if(farm[j]->gettype() == type)
        {
            farm[j]->eat();

            if(farm[j]->getoverweight())
            {
                revenue += farm[j]->price(); //Return the price of the animals killed

                delete farm[j];
                farm.erase(farm.begin() + j);
                j--;
            }
        }
    }

}
void Farm::displacement(int times) //Calls the displacement function X times so the animals can move
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

void Farm::setPrice_kg(float bull, float pig, float duck, float chicken) //Set the price of each type of animal 
{
    Bull::setprice_kg(bull);
    Pig::setprice_kg(pig);
    Duck::setprice_kg(duck);
    Chicken::setprice_kg(chicken);
}

int Farm::getn_animals_per_type(Type_Animal type)
{
    switch(type)
        {
        case Type_Animal::Type_Bull:
            return Bull::getn_bulls();   
            break;

        case Type_Animal::Type_Pig:
            return Pig::getn_pigs();
            break;
        
        case Type_Animal::Type_Duck:
            return Duck::getn_ducks();
            break;
        
        default:
            return Chicken::getn_chickens();
            break;
    }

}