#include "Gachapon.hpp"

int main()
{
    srand(time(NULL));

    Gachapon gacha("Pokémon", 20);

    gacha.pull(5);

    return 0;
}