#include "Matriz.hpp"

int main()
{
srand(time(NULL));

Matriz matrizA;
Matriz matrizB;
Matriz matrizC;

matrizA.fill();
matrizB.fill();
matrizC.fill();

Matriz matrizD = matrizA;
 
matrizA * matrizB;

cout << matrizA;

  return 0;   
}
