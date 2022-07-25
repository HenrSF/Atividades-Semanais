#include "Matriz.hpp"

int main()
{
srand(time(NULL));

Matriz matrizA;
Matriz matrizB;

matrizA.fillrand(-10, 10);
matrizB.fillrand(0, 10);

cout << matrizA;
cout << matrizB;
//Matriz matrizD = matrizA;
//Matriz matrizC(2 + matrizB);

matrizA.gaussian_elimination();
cout << matrizA;

matrizB = (20 - matrizB) * matrizB * 10 + (matrizA - 50);
cout << matrizB;

  return 0;   
}
