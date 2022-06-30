#include "Matriz.hpp"

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
        matriz[i][j] =(min + (rand()) * (max - min)/RAND_MAX);  //Explicação
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
    if (i < 0 || i)
    {
        return
    }

    cerr << "";
}

double &Matriz::operator[] (int)        //Dúvida
{
    return matriz[i][j];}

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
    
    cerr << "The matrix cannot be summed!";
    exit(EXIT_FAILURE);
}

//Operador entre objetos
Matriz Matriz::operator- (const Matriz &other) const
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
Matriz Matriz::operator* (const Matriz &other) 
{   
    double soma;
    Matriz temp( this->line, other.column);
    
    if(this->column != other.line)
    {
    cerr << "The matrix cannot be multiplied!";
    exit (EXIT_FAILURE);
    } 
    
    for (int i = 0; i < this->line; i++) //Multiplicando as Matrizes 1 e 2.
    for (int j = 0; j < other.column; j++)
    {
        soma = 0;

        for (int k = 0; k < this->column; k++)
        {
            soma += this->matriz[i][k] * other.matriz[k][j];
            temp.matriz[i][j] = soma;
        }
    }
                   
    return temp;
}

//Operador entre objetos
const Matriz &Matriz::operator= (const Matriz &other);
{    
    if(&other != tthis)
    {
        for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        matriz[i][j] = other.matriz[i][j];
    }
}

//Operador entre objeto (lvalue) e inteiro 
void Matriz::operator+ (int num) const
{  
    for(int i = 0; i < line; i++)
    for(int j = 0; j < column; j++)
    {    
        matriz[i][j] += num;
    }
}

void Matriz::operator- (int num) const
{
    for(int i = 0; i < line; i++)
    for(int j = 0; j < column; j++)
    {    
        matriz[i][j] -= num;
    }
}

void Matriz::operator* (int num) const
{
    for(int i = 0; i < line; i++)
    for(int j = 0; j < column; j++)
    {    
        matriz[i][j] *= num;
    }
}

ostream &operator<< (ostream &output, const Matriz &right)
{
    return output;
}

istream &operator>> (istream &input, Matriz &rigtht)
{

    return input;
}

Matriz &operator+ (double num, Matriz &right)
{

}

Matriz &operator- (double num, Matriz &right) 
{

}

Matriz &operator* (double num, Matriz &right)
{
    
}