#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum rarity
{
    common, uncommon, rare, super_rare, ultra_rare
};

class Gachapon
{
    public:

    Gachapon(string name, int prize_quantity); //Constructor
    ~Gachapon(); //Destructor

    //Setters
    void set_name(string &name) { this->name = name;}

    //Getters
    string get_name() const { return name; }

    void pull(int ticket); //Remove the top capsule and tells it's rarity;

    private:

    stack <rarity> prize; //Stack cointainer that receives rarity as a type
    string name;         

    void fill_machine(int quantity); //Fill the gachapon with each type of capsule and it's rarity

    
};
