#include "Gachapon.hpp"

int main()
{
    srand(time(NULL));

    Gachapon gacha("Pokémon", 20);

    gacha.pull(6);

    return 0;
}