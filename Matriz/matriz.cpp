#include "matriz.hpp"

Matriz::Matriz(int Line, int Column)
{
    line = Line;
    column = Column;
    matriz = new double* [line];

    for (int i = 0; i < line; i++)
    {
        matriz[i] = new double [column];
    }

    for (int i = 0; i < line; i++)
    for (int j = 0; j < column; j++)
    {
        matriz[i][j] = 0;
    }  
}

Matriz::Matriz(int Order)
{
    line = Order;
    column = Order;
    matriz = new double* [line];

    for (int i = 0; i < line; i++)
    {
        matriz[i] = new double [column];
    }

    for (int i = 0; i < line; i++)
    for (int j = 0; j < column; j++)
    {
        matriz[i][j] = 0;
    }  
}

Matriz::~Matriz()
{   
    for (int i = 0; i < line; i++)
    {
        delete [] matriz [i];
    }
    delete [] matriz;
    matriz = nullptr;

    cout << "The Matrix has been destroyed";
}
void Matriz::fill()
{
   for (int i = 0; i < line; i++)
   for (int j = 0; j < column; j++)
   {
        cin >> matriz[i][j];
   }
}
void Matriz::fillrand(double min, double max)
{
    srand(time(NULL));
    
    for (int i = 0; i < line; i++)
    for (int j = 0; j < column; j++) 
    {
        matriz[i][j] =(min + (rand()) * (max - min)/RAND_MAX);//Explicação
    }
}
bool Matriz::diagonal()
{

}
double** Matriz::gaussian_elimination()
{

}
double &Matriz::getmatriz()
{
    double** matriz_copy = NULL;
    matriz_copy = new double* [line];

    for (int i = 0; i < line; i++)
    {
        matriz_copy[i] = new double[column];
    }

    for (int i = 0; i < line; i++)
    for (int j = 0; j < column; j++)
    {
        matriz_copy[i][j] = matriz[i][j];
    }
    return **matriz_copy; //Explicação
}

double Matriz::operator[] (double i, double j)//Problema
{
    if ((i < 0 || j < 0) || (i < line || j < column)) return matriz[i][j];

    cerr << ""
}

double &Matriz::operator[] (double i, double j)
{
    return matriz[i][j];
}
