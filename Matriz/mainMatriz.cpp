#include "Matriz.hpp"

int main()
{

Matriz matrizA(3);
Matriz matrizB(3, 2);
Matriz matrizC(2, 3);

matrizA.fillrand(0, 10);
matrizB.fillrand(0, 10);
matrizC.fillrand(0, 10);

Matriz matrizD = matrizA;

cout << matrizA
     << matrizB 
     << matrizC
     << matrizD
     << endl;

  return 0;   
}
