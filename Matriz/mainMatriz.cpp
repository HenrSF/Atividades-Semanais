#include "Matriz.hpp"

int main()
{
srand(time(NULL));

Matriz matrizA(5, 4);
Matriz matrizB;
Matriz matrizC;

matrizA.fill();
//matrizB.fill();
//matrizC.fill();

//Matriz matrizD = matrizA;
 
matrizA.gaussian_elimination();

cout << matrizA;

  return 0;   
}
