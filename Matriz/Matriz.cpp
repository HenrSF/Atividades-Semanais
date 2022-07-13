#include "Matriz.hpp"

Matriz::Matriz(int line, int column) //Construtor para matrizes de qualquer tamanho;
{
    //Definindo os atributos de linha e coluna;
    this->line = line;
    this->column = column;
    //Alocando memória dinamicamente para o atributo **matriz;
    this->matriz = new double *[this->line];
    for (int i = 0; i < this->line; i++)
    {
        matriz[i] = new double[this->column](); //Iniciando todos valores iguais a 0;
    }
}

Matriz::Matriz(int Order) //Construtor para matrizes de ordem pré-definida
{   
    //Definindo os atributos de linha e coluna;
    this->line = Order;
    this->column = Order;
    //Alocando memória dinamicamente para o atributo **matriz;
    this->matriz = new double *[this->line];
    for (int i = 0; i < this->line; i++)
    {
        matriz[i] = new double[this->column](); //Iniciando todos valores iguais a 0;
    }
    
}

Matriz::Matriz(const Matriz &other) //Construtor de cópia;
{
    //Definindo os atributos de linha e coluna, iguais ao do objeto parâmetro;
    this->line = other.line;
    this->column = other.column;
    //Alocando memória dinamicamente para o atributo **matriz;
    this->matriz = new double *[this->line];

    for (int i = 0; i < this->line; i++)
    {
        this->matriz[i] = new double[this->column];
    }
    //Atribuindo os valores da matriz iguais aos do objeto copiado.
    for (int i = 0; i < this->line; i++)
        for (int j = 0; j < this->column; j++)
        {
            this->matriz[i][j] = other.matriz[i][j];
        }
}

Matriz::~Matriz() //Destrutor
{
    //Desalocando a memória das colunas;
    for (int i = 0; i < line; i++)
    {
        delete[] this->matriz[i];
    }
    delete[] this->matriz; //Desalocando a matriz;

    this->matriz = nullptr; //Ponteiro nulo;

    cout << "\nThe Matrix has been destroyed.";
}

void Matriz::fill() //Método para preenchimento manual de matrizes;
{
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            cin >> matriz[i][j];
        }
}

void Matriz::fillrand(double min, double max) //Método para preenchimento randomico de matrizes;
{
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            matriz[i][j] = (min + (rand()) * (max - min) / RAND_MAX); //Gerando um ponto flutante aleatório;
        }
}

void Matriz::imprimir() //Método para imprimir todos os atrinutos do objeto.
{
    cout << "\nNúmero de linhas: " << this->line
         << "\nNúmero de colunas: " << this->column << endl
         << *this
         << "\nMatriz diagonal:" << diagonal_check();
}

bool Matriz::diagonal_check() //Verificar se a matriz é diagonal;
{
    int cont = 0;

    if (line == column) //Verificar se a matriz é quadrada;
    {
        for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            if (i == j) continue; //Ignora os elementos da diagonal principal;
                
            if (matriz[i][j] == 0) //Se um elemento for igual a zero, incrementa o contador;
            {
                cont++; //Conta a quantiade de zeros fora da diagonal principal;
            }
        }
 
        if(cont == (line * column) - line) //Se o contador for igual ao numero de elementos fora da diagonal principal, retorna true;
        {
            return true;
        }
    }

    return false;
}

/*double &Matriz::gaussian_elimination() // Ainda falta fazer
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

double **Matriz::getmatriz() //Obter o atributo matriz do objeto;
{   
    //Alocando memória para copiar o atributo matriz;
    double **matriz_copy = NULL;
    matriz_copy = new double *[this->line];

    for (int i = 0; i < line; i++)
    {
        matriz_copy[i] = new double[this->column];
    }
    //Copiando os valores do atributo matriz;
    for (int i = 0; i < this->line; i++)
        for (int j = 0; j < this->column; j++)
        {
            matriz_copy[i][j] = matriz[i][j];
        }
    return matriz_copy; //Retorna a cópia do atributo matriz, para manter o encapsulamento;
}

double *Matriz::operator[](int i)
{
    //
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
    Matriz temp(*this);
    Matriz temp1(this->line, other.column);

    if (this->column != other.line)
    {
        cerr << "\nThe matrix cannot be multiplied!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < this->line; i++) // Multiplicando as Matrizes 1 e 2.
    for (int j = 0; j < other.column; j++)
    {
        for (int k = 0; k < this->column; k++)
        {
            temp1.matriz[i][j] += (temp.matriz[i][k] * other.matriz[k][j]);
                
        }
    }

    *this = temp1;
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

            this->line = other.line;
            this->column = other.column;

            this->matriz = new double *[this->line];

                for (int i = 0; i < this->line; i++)
            {
                this->matriz[i] = new double[this->column];
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
