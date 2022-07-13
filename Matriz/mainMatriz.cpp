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

double **a;

a = new double *[3];

for(int i=0; i<3; i++)
{
     a[i] = new double[2]();
}

a = matrizB.getmatriz();

for (int i = 0; i < 3; i++)
{
cout << endl;
for (int j = 0; j < 2; j++)
{
cout << a[i][j] << " ";
}
}

matrizA.imprimir();

  return 0;   
}
