#include "Matriz.hpp"

int main()
{
srand(time(NULL));

Matriz matrizA;
Matriz matrizB;
Matriz matrizC(2, 3);

matrizA.fill();
matrizB.fill();
matrizC.fill();

Matriz matrizD = matrizA;
 
matrizA.imprimir();
matrizB.imprimir();

  return 0;   
}
