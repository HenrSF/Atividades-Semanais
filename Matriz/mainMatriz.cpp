#include "Matriz.hpp"

int main()
{
srand(time(NULL));

Matriz matrizA;
Matriz matrizB;
//Matriz matrizC;

matrizA.fillrand(0, 10);
matrizB.fillrand(0, 10);
//matrizC.fill();

//cout << matrizA;
cout << matrizB;
//Matriz matrizD = matrizA;
//Matriz matrizC(2 + matrizB);

matrizB = matrizB * 10;
cout << matrizB;

cout << "\n\n Efetuando subtracao....";
matrizB = 2 - matrizB;
cout << matrizB;

  return 0;   
}
