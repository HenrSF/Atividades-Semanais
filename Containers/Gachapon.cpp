#include "Gachapon.hpp"
#include <random>

namespace P //probability
{
    int common = 55;
    int uncommon = 30;
    int rare = 10;
    int super_rare = 4;
    int ultra_rare =  1;
    
}

Gachapon::Gachapon(string name, int quantity) //Constructor
{
    set_name(name);

    if (quantity <= 0)
    {
        cerr << "\nInvalid quantity!" << endl;
        exit(EXIT_FAILURE);
    }
    
    fill_machine(quantity);
}

Gachapon::~Gachapon()
{
    while(!prize.empty())
    {
        prize.pop();
    }

    cout << "\nGoodbye machine-san!";
}

void Gachapon::fill_machine(int quantity) //Fill the machine with each type of capsule and it's rarity
{
    while (prize.size() < quantity)
    {
        int r = rand() % 100 + 1;

        if (r <= P::ultra_rare)
        {
            prize.push(ultra_rare);
        }
        
        else if (r <= P::ultra_rare + P::super_rare)
        {
            prize.push(super_rare);
        }

        else if(r <= P::ultra_rare + P::super_rare + P::rare)
        {
            prize.push(rare);
        }

        else if(r <= P::ultra_rare + P::super_rare + P::rare + P::uncommon)
        {
            prize.push(uncommon);
        }

        else
        {
            prize.push(common);
        }
    }
    
}

void Gachapon::pull(int ticket) //Remove the top capsule and tells it's rarity;
{
    while(ticket > 0)
    {
    
        if(prize.top() == common)
        {
            cout << "\nYou pulled a common capsule." << endl;
            prize.pop();
            ticket--;
            continue;
        }

        if(prize.top() == uncommon)
        {
            cout << "\nYou pulled a uncommon capsule." << endl;
            prize.pop();
            ticket--;
            continue;
        }

        if(prize.top() == rare)
        {
            cout << "\nCongratulations!! You pulled a rare capsule!" << endl;
            prize.pop();
            ticket--;
            continue;
        }

        if(prize.top() == super_rare)
        {
            cout << "\nWOW, Congratulations!! You pulled a super rare capsule!" << endl;
            prize.pop();
            ticket--;
            continue;
        }

        if(prize.top() == ultra_rare)
        {
            cout << "\nI had a feeling you were something else! you just pulled a ultra rare capsule!!!!!" << endl;
            prize.pop();
            ticket--;
            continue;
        }
    }
}
