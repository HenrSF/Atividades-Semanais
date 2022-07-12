#include "Matriz.hpp"

int main()
{
srand(time(NULL));

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

cout << matrizA[1][2];

matrizA[1][2] = 25;      

cout << matrizA;

cout << matrizA.diagonal();

cout << "\nDigite os valores para a matriz A:";

cin >> matrizA;

cout << matrizA
     << matrizA.diagonal() << endl;

  return 0;   
}
