#include "Matriz.hpp"

Matriz::Matriz(int line, int column)
{
    this->line = line;
    this->column = column;
    matriz = new double *[this->line];

    for (int i = 0; i < line; i++)
    {
        matriz[i] = new double[this->column];
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
    matriz = new double *[line];
    for (int i = 0; i < line; i++)
    {
        matriz[i] = new double[column];
    }

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
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
        delete[] matriz[i];
    }
    delete[] matriz;
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
            matriz[i][j] = (min + (rand()) * (max - min) / RAND_MAX); // Explicação
        }
}

void Matriz::imprimir()
{
    cout << "\nNúmero de linhas: " << this->line
         << "\nNúmero de colunas: " << this->column << endl
         << this;
}

bool Matriz::diagonal() // Ainda falta fazer
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
            return true;
        }
    }
    return false;
}


double **Matriz::gaussian_elimination() // Ainda falta fazer
{

}

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

double Matriz::operator[](int i) const // Como fazer [][]
{
    /*if (i < 0 || i)
    {
        return
    }

    cerr << "";
    */
}

double &Matriz::operator[](int i) // Dúvida
{
    return *matriz[i];
}

// Operador entre objetos
Matriz &Matriz::operator+(const Matriz &other)
{
    Matriz temp(this->line, this->column);

    if (this->line == other.line && this->column == other.column)
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

// Operador entre objetos
Matriz &Matriz::operator-(const Matriz &other) const
{
    Matriz temp(line, column);
    if (this->line != other.line && this->column != other.column)
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

// Operador entre objetos
Matriz &Matriz::operator*(const Matriz &other)
{
    double soma;
    Matriz temp(this->line, other.column);

    if (this->column != other.line)
    {
        cerr << "The matrix cannot be multiplied!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < this->line; i++) // Multiplicando as Matrizes 1 e 2.
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

// Operador entre objetos
const Matriz &Matriz::operator=(const Matriz &other)
{
    if (&other != this)
    {
        if (this->column != other.column || this->line != other.line)
        {
            for (int i = 0; i < this->line; i++)
            {
                delete this->matriz[i];
            }

            delete[] this->matriz;
            this->matriz = NULL;
            this->matriz = new double *[other.line];

                for (int i = 0; i < this->line; i++)
            {
                this->matriz[i] = new double[other.column];
            }
        }

        for (int i = 0; i < line; i++)
            for (int j = 0; j < column; j++)
            {
                matriz[i][j] = other.matriz[i][j];
            }

        return *this; // esse retorno é correto? e pq usar
    }

    cerr << "They are the same matrix!";
    exit(EXIT_FAILURE);
}

// Operador entre objeto (lvalue) e inteiro
Matriz &Matriz::operator+(int num) const
{
    Matriz temp(*this);

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] += num;
        }

    return temp;
}

Matriz &Matriz::operator-(int num) const
{
    Matriz temp(*this);

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] -= num;
        }

    return temp;
}

Matriz &Matriz::operator*(int num) const
{
    Matriz temp(*this);
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] *= num;
        }
}

ostream &operator<<(ostream &output, const Matriz &right)
{
    for (int i = 0; i < right.line; i++)
    {
        cout << endl;
        cout << "| ";

        for (int j = 0; j < right.column; j++)
        {
            cout << setprecison(2) << setw(4)
                 << right.matriz[i][j];
        }

        cout << " |";
    }

    return output;
}

istream &operator>>(istream &input, Matriz &rigtht)
{
    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            cin >> right.matriz[i][j];
        }

    return input;
}

Matriz &operator+(double num, Matriz &right)
{
    Matriz temp(right);

    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            temp.matriz[i][j] += num;
        }

    return temp;
}

Matriz &operator-(double num, Matriz &right)
{
    Matriz temp(right);

    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            temp.matriz[i][j] -= num;
        }

    return temp;
}

Matriz &operator*(double num, Matriz &right)
{
    Matriz temp(right);

    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            temp.matriz[i][j] *= num;
        }

    return temp;
}
