#ifndef FARM_HPP
#define FARM_HPP

using namespace std;

#include "Animals.hpp"
#include "Bull.hpp"
#include "Pig.hpp"
#include "Duck.hpp"
#include "Chicken.hpp"

#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

enum Type_Animal //Use this in the base class to 
{
    Type_Bull, Type_Pig, Type_Duck, Type_Chicken
};

class Farm
{
    public:

        Farm(string city, string state, float area); //Constructor;
        ~Farm(); //Destructor;

        //Condition of empty vector;
        void Add_toFarm(Type_Animal type); //Add a new animal to the Farm;
        void print(); //Print the Farm status;
        void print_animal(int index); //Print the Animal status;
        float total_price() const; //Print the current price of all animals together;
        float price(int index) const; //Print the current price of one animal;
        void Rm_fromFarm(int index); //Remove an animal from the Farm;
        void clear_farm(); //Clear the Farm;
        void feed(); //Feed all animals in the Farm;
        void displacement(); //Displace all animals in the Farm;

        //Getters
        string GetCity() const {return city;}
        string GetState() const {return state;}
        float GetArea() const {return area;}
        

        //Setters
        void SetCity(string city) {this->city = city;}
        void SetState(string state) {this->state = state;}
        void SetArea(float area) {this->area = area;}
        void setPrice_kg(float bull, float pig, float duck, float chicken); //Price per kg for each animal

    private:

        vector <Animals *> farm;

        string city;
        string state;
        float area;

        Animals* CreateAnimal(Type_Animal type); //Creates a new animal

};
#endif