#include "Matriz.hpp"

int main()
{
srand(time(NULL));

Matriz matrizA(4);
//Matriz matrizB;
//Matriz matrizC;

matrizA.fill();
//matrizB.fillrand(0, 10);
//matrizC.fill();

//cout << matrizA;
cout << matrizA;
//Matriz matrizD = matrizA;
//Matriz matrizC(2 + matrizB);

matrizA.gaussian_elimination();


  return 0;   
}
