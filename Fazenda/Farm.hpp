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
    Bull, Pig, Duck, Chicken
};

class Farm
{
    public:

        Farm(string city, string state, float area); //Constructor;
        ~Farm(); //Destructor;

        //Condition of empty vector;
        void Add_toFarm(Type_Animal type); //Add a new animal to the Farm;
        void print(); //Print the Farm status;
        void total_price(); //Print the current price of all animals together;
        void Rm_fromFarm(int index); //Remove an animal from the Farm;
        Animals* CreateAnimal(Type_Animal type);


        //Getters
        string GetCity() const {return city;}
        string GetState() const {return state;}
        float GetArea() const {return area;}
        

        //Setters
        void SetCity(string city) {this->city = city;}
        void SetState(string state) {this->state = state;}
        void SetArea(float area) {this->area = area;}

    private:

        vector <Animals *> farm;

        string city;
        string state;
        float area;

};
#endif