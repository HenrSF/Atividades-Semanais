#include "matriz.hpp"

Matriz::Matriz(int line, int column)
{
    this->line = line;
    this->column = column;
    matriz = new double* [this->line];

    for (int i = 0; i < line; i++)
    {
        matriz[i] = new double [this->column];
    }

    for (int i = 0; i < this->line; i++)
    for (int j = 0; j < this->column; j++)
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

double Matriz::operator[] (int i) const //Como fazer [][]
{
    if ((i < 0 || i)
    {
        return
    }

    cerr << ""
}

double &Matriz::operator[] (int)
{
    return matriz[i][j];
}
//Operador entre objetos
Matriz Matriz::operator+ (const Matriz &other)
{
    Matriz temp(this->line, this->column);
    
    if( this->line == other.line && this->column == other.column )
    {
    for (int i = 0; i < this->line; i++)
     for (int j = 0; j < this->column; j++)
     {
       temp.matriz[i][j] = this->matriz[i][j] + other.matriz[i][j]; 
        return temp;
     }
     }
    
     else
     {
        cerr << "The matrix cannot be summed!";
        exit(EXIT_FAILURE);
     }
}
//Operador entre objetos
Matriz Matriz::operator -(const Matriz& other) const
{
    Matriz temp(line, column);
     if( this->line != other.line && this->column != other.column )
    {
        cerr << "The matrix cannot be subtracted!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < line; i++)
    for (int j = 0; j < column; j++)
    {
        temp.matriz[i][j] = this->matriz[i][j] - other.matriz[i][j]; 
        
    }
    return temp;
} 
//Operador entre objetos
Matriz Matriz::operator*(const Matriz& other) 
{

}
//Operador entre objetos
Matriz &Matriz::operator=(const Matriz& other) 
{
    if( this->matriz != other.matriz && this->line == other.line && this->column == other.column )
    {
        for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        matriz[i][j] = other.matriz[i][j];
    }
}
//Operador entre objeto (lvalue) e inteiro 
void Matriz::operator+(int n)const
{

}
void Matriz::operator-(int n)const
{

}
void Matriz::operator*(int n)const
{

}