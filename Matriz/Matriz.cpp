#include "Matriz.hpp"

Matriz::Matriz(int line, int column)
{
    this->line = line;
    this->column = column;
    this->matriz = new double *[this->line];

    for (int i = 0; i < this->line; i++)
    {
        matriz[i] = new double[this->column]();
    }

    for (int i = 0; i < this->line; i++)
        for (int j = 0; j < this->column; j++)
        {
            matriz[i][j] = 0;
        }
}

Matriz::Matriz(int Order)
{
    this->line = Order;
    this->column = Order;
    this->matriz = new double *[this->line];
    for (int i = 0; i < this->line; i++)
    {
        matriz[i] = new double[this->column];
    }

    for (int i = 0; i < this->line; i++)
        for (int j = 0; j < this->column; j++)
        {
            matriz[i][j] = 0;
        }
}

Matriz::Matriz(const Matriz &other)
{
    this->line = other.line;
    this->column = other.column;

    this->matriz = new double *[this->line];

    for (int i = 0; i < this->line; i++)
    {
        this->matriz[i] = new double[this->column];
    }

    for (int i = 0; i < this->line; i++)
        for (int j = 0; j < this->column; j++)
        {
            this->matriz[i][j] = other.matriz[i][j];
        }
}

Matriz::~Matriz()
{
    for (int i = 0; i < line; i++)
    {
        delete[] this->matriz[i];
    }
    delete[] this->matriz;

    this->matriz = nullptr;

    cout << "\nThe Matrix has been destroyed.";
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
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            matriz[i][j] = (min + (rand()) * (max - min) / RAND_MAX); // Explicação
        }
}

void Matriz::imprimir()
{
    cout << "\nNúmero de linhas: " << this->line
         << "\nNúmero de colunas: " << this->column << endl
         << this;
}

bool Matriz::diagonal()
{
    int cont = 0;

    if (line == column)
    {
        for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            if (i == j) continue;
                
            if (matriz[i][j] == 0)//diagonal
            {
                cont++;
            }
        }
 
        if(cont == line * column - line)
        {
            return true; //retornará 1
        }
    }

    return false; //retornará 0
}

/*double **Matriz::gaussian_elimination() // Ainda falta fazer
{
 if(line > column)          // Quando o número de linha é maior que o número de colunas de colunas, ex.: Matriz(3x2)
{

}

 if(line <= column)         // Quando o número de linhas é menor ou igual ao número de colunas, ex.: Matriz(2x3) ou Matriz(3x3) 
{
    for (int i = 0; i < line; i++)
    {
    matriz[1][i];

    *matriz[i];
    }
}

}
*/

double &Matriz::getmatriz()
{
    double **matriz_copy = NULL;
    matriz_copy = new double *[this->line];

    for (int i = 0; i < line; i++)
    {
        matriz_copy[i] = new double[this->column];
    }

    for (int i = 0; i < this->line; i++)
        for (int j = 0; j < this->column; j++)
        {
            matriz_copy[i][j] = matriz[i][j];
        }
    return **matriz_copy; // Explicação: se esse retorno é correto e pq
}

double * Matriz::operator[](int i) // Como fazer [][]
{
    if (i <= 0 || i < this->line)
    {
        return this->matriz[i];
    }

    cerr << "\nÍndice inválido!";
    exit ( EXIT_FAILURE);
}

// Operador entre objetos
Matriz &Matriz::operator+(const Matriz &other)
{
    if (this->line == other.line && this->column == other.column)
    {
        for (int i = 0; i < this->line; i++)
            for (int j = 0; j < this->column; j++)
            {
                this->matriz[i][j] += other.matriz[i][j];
            }

        return *this;
    }

    cerr << "\nThe matrix cannot be summed!";
    exit(EXIT_FAILURE);
}

// Operador entre objetos
Matriz &Matriz::operator-(const Matriz &other) 
{
    if (this->line != other.line && this->column != other.column)
    {
        cerr << "\nThe matrix cannot be subtracted!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            this->matriz[i][j] -= other.matriz[i][j];
        }

    return *this;
}

// Operador entre objetos
Matriz &Matriz::operator*(const Matriz &other) // Falta alterar a matriz
{
    double soma;
    Matriz temp(*this);

    this = Matriz matrix(this->line, other.column)

    if (this->column != other.line)
    {
        cerr << "\nThe matrix cannot be multiplied!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < this->line; i++) // Multiplicando as Matrizes 1 e 2.
        for (int j = 0; j < other.column; j++)
        {
            soma = 0;

            for (int k = 0; k < this->column; k++)
            {
                soma += temp.matriz[i][k] * other.matriz[k][j];
                this->matriz[i][j] = soma;
            }
        }

    return *this;
}

// Operador entre objetos
const Matriz &Matriz::operator=(const Matriz &other)
{
    if (&other != this)
    {
        if (this->column != other.column || this->line != other.line)
        {
            for (int i = 0; i < this->line; i++)
            {
                delete[] this->matriz[i];
            }

            delete[] this->matriz;
            this->matriz = NULL;
            this->matriz = new double *[other.line];

                for (int i = 0; i < this->line; i++)
            {
                this->matriz[i] = new double[other.column];
            }
        }

        for (int i = 0; i < this->line; i++)
            for (int j = 0; j < this->column; j++)
            {
                this->matriz[i][j] = other.matriz[i][j];
            }

        return *this; // esse retorno é correto? e pq usar
    }

    cerr << "\nThey are the same matrix!";
    exit(EXIT_FAILURE);
}

// Operador entre objeto (lvalue) e inteiro
Matriz &Matriz::operator+(double num)
{
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            this->matriz[i][j] += num;
        }

    return *this;
}

Matriz &Matriz::operator-(double num)
{
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            this->matriz[i][j] -= num;
        }

    return *this;
}

Matriz &Matriz::operator*(double num)
{
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            this->matriz[i][j] *= num;
        }

    return *this;
}

ostream &operator<<(ostream &output, const Matriz &right)
{
    for (int i = 0; i < right.line; i++)
    {
        cout << endl;
        cout << "| ";

        for (int j = 0; j < right.column; j++)
        {
            cout << fixed << setprecision(2)
                 << right.matriz[i][j] << " ";
        }

        cout << "|";
    }
        cout << endl;

    return output;
}

istream &operator>>(istream &input, Matriz &right)
{
    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            cin >> right.matriz[i][j];
        }

    return input;
}

Matriz &operator+(const double num, Matriz &right)
{
    return (right + num);
}

Matriz &operator-(const double num, Matriz &right)
{
    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            right.matriz[i][j] = num - right.matriz[i][j];
        }
    return right;
}

Matriz &operator*(const double num, Matriz &right)
{
    return (right * num);
}
