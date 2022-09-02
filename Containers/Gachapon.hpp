#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum rarity
{
    common, uncommon, rare, super_rare, ultra_rare // 55, 30, 10, 4, 1;
};

class Gachapon //if(common * 0.55)
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

    stack <rarity> prize;
    string name;

    void fill_machine(int quantity); //Fill the machine with each type of capsule and it's rarity

    
};
