#ifndef FARM_HPP
#define FARM_HPP

using namespace std;

#include "Animals.hpp"
#include "Bull.hpp"
#include "Pig.hpp"
#include "Duck.hpp"
#include "Chicken.hpp"

#include <vector>
#include <ctime>
#include <cstdlib>

class Farm
{
    public:

        Farm(string city, string state, float area); //Constructor;
        ~Farm(); //Destructor;

        //Condition of empty vector;
        void Add_toFarm(Type_Animal type); //Add a new animal to the Farm;
        
        void print();                      //Print the Farm status;
        
        void print_animal(int index);      //Print the Animal status;
        
        float total_price() const;         //Print the current price of all animals together;
        
        float price(int index) const;      //Print the current price of one animal; This method doesn't add the animal's price to the revenue
        
        void Rm_fromFarm(int index);       //Remove an animal from the Farm; This method doesn't add the animal's price to the revenue 

        
        void clear_farm();                 //Clear the Farm, this method n
        
        void feed(int times);              //Feed all animals in the Farm; if overweight, the animal is killed and it's price is added to the revenue
        
        void displacement(int times);      //Displace all animals in the Farm;

        //Getters
        string GetCity() const {return city;}
        
        string GetState() const {return state;}
        
        float GetArea() const {return area;}
        
        int getn_animals() const {return farm.size();}
        

        //Setters
        void SetCity(string city) {this->city = city;}
        
        void SetState(string state) {this->state = state;}
        
        void SetArea(float area) {this->area = area;}
        
        void setPrice_kg(float bull, float pig, float duck, float chicken); //Price per kg for each animal;

    private:

        vector <Animals *> farm;
        string city;
        string state;
        float area;
        float revenue; //revenue of sold animals

        Animals* CreateAnimal(Type_Animal type); //Creates a new animal
};
#endif