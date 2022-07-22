#include "Matriz.hpp"
Matriz temp;
Matriz::Matriz(int line, int column) //Construtor para matrizes de qualquer tamanho;
{
    if(line < 0) line *= -1;
    if(column < 0) column *= -1;
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
    if(Order < 0) Order *= -1;
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
    if(min > max)
    {
        double temp = min;
        min = max;
        max = temp;
    }

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

void Matriz::trocalinha(int i, int linechange)
{
    double *ptraux = matriz[i];
    matriz[i] = matriz[linechange];
    matriz[linechange] = ptraux;
}

void Matriz::jump_end(int line)
{
    for(int i = line; i < this->line-1; i++)
    {
        trocalinha(i, i+1);
    }
}

void Matriz::gaussian_elimination() //Ainda falta fazer
{
    //Tratamento de zeros (realocação dentro da matriz);
    for (int i = 0; i < line; i++)
    {
        for (int k = i; k < line; k++)
        {
            for (int test = 0; test < line; test++)
            {
                if(matriz[k][i] == 0)
                {
                    jump_end(k);
                }
                /*
                if(test == line - 1)
                {
                    i++;
                }
                */
            }

            if(matriz[k][i] < 0)
            {
                for (int j = 0; j < column; j++)
                {
                    matriz[k][j] *= -1;
                }
            }
        }
    }
    
    for (int i = 0; i < line; i++)
    {
        for (int k = i; k < line; k++)
        {
            if(matriz[k][i] != 0)
            {
                for (int j = 0; j < column; j++)
                {
                    matriz[k][j] /= matriz[k][i];
                }

                for (int j = 0; j < column; j++)
                {
                    if(k == 0) continue;
                    matriz[k][j] = matriz[i][j] - matriz[k][j];
                }
            }
        }
    }
    cout << *this;  
}

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
    return matriz_copy; //Retorna a cópia do atributo matriz para manter o encapsulamento;
}

double *Matriz::operator[](int i) //Acessa um índice da matriz.
{

    if (i >= 0 || i < this->line)
    {
        return this->matriz[i]; //Retorno de um ponteiro.
    }

    cerr << "\nÍndice inválido!";
    exit ( EXIT_FAILURE);
}

Matriz &Matriz::operator+(const Matriz &other) //Soma de matrizes;
{
    temp = *this;
    if (this->line == other.line && this->column == other.column) //Verifca a possibilidade de realizar a operação;
    {
        for (int i = 0; i < this->line; i++)
            for (int j = 0; j < this->column; j++)
            {
                temp.matriz[i][j] += other.matriz[i][j];
            }

        return temp; //Retorna o próprio objeto;
    }

    cerr << "\nThe matrix cannot be summed!";
    exit(EXIT_FAILURE);
}


Matriz &Matriz::operator-(const Matriz &other) //Subtração de matrizes 
{
    temp = *this;
    if (this->line != other.line && this->column != other.column) //Verifca a possibilidade de realizar a operação;
    {
        cerr << "\nThe matrix cannot be subtracted!";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] -= other.matriz[i][j];
        }

    return temp; //Retorna o objeto temp;
}

Matriz &Matriz::operator*(const Matriz &other) //Multiplicação de matrizes;
{

    Matriz resultado(this->line, other.column); //Objeto temporário para receber os valores da multiplicação;

    if (this->column != other.line) //Condição para multiplicar 2 matrizes.
    {
        cerr << "\nThe matrix cannot be multiplied!";
        exit(EXIT_FAILURE);
    }
    //Algorotímo para efetuar a multiplicação de matrizes;
    for (int i = 0; i < this->line; i++)
    for (int j = 0; j < other.column; j++)
    {
        for (int k = 0; k < this->column; k++)//Percorre a linha da primeira matriz junto a coluna da segunda matriz;
        {
            resultado.matriz[i][j] += (this->matriz[i][k] * other.matriz[k][j]); //Somatório das multiplicações índice à índice para atribuição dos valores da matriz resulante;
        }
    }
    temp = resultado;
    return temp; //Retorna o objeto temp;
}


const Matriz &Matriz::operator=(const Matriz &other) //Iguala uma matriz à outra;
{
    cout << "\n Entrei no operator=";
    //Verifica se tem o mesmo endereço
    if (&other != this)
    {
        if (this->column != other.column || this->line != other.line) //Verifica se as matrizes possuem a mesma dimensão;
        {
            //Desalocando a memória da matriz;
            for (int i = 0; i < this->line; i++)
            {
                delete[] this->matriz[i];
            }
            delete[] this->matriz;
            this->matriz = NULL;
            
            //Deixa as matrizes com a mesma dimensão;
            this->line = other.line;
            this->column = other.column;
            
            //Alocando memória para a nova matriz;
            this->matriz = new double *[this->line];

                for (int i = 0; i < this->line; i++)
            {
                this->matriz[i] = new double[this->column];
            }
        }
        
        //Atribui os valores de uma matriz a outra;
        for (int i = 0; i < this->line; i++)
            for (int j = 0; j < this->column; j++)
            {
                this->matriz[i][j] = other.matriz[i][j];
            }

        return *this; //Retorna o próprio objeto;
    }

    cerr << "\nThey are the same matrix!";
    exit(EXIT_FAILURE);
}


Matriz &Matriz::operator+(double num) //Soma de matriz e escalar com o objeto à esquerda;
{
    temp = *this;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] += num;
        }

    return temp; //Retorna o objeto temp;
}

Matriz &Matriz::operator-(double num) //Subtração de matriz e escalar com o objeto à esquerda;
{
    temp = *this;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] -= num;
        }

    return temp; //Retorna o objeto temp;
}

Matriz &Matriz::operator*(double num) //Multiplicação de matrize e escalar com o objeto à esquerda;
{
    temp = *this;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] *= num;
        }

    return temp; //Retorna o objeto temp;
}

ostream &operator<<(ostream &output, const Matriz &right) //Operador de inserção de fluxo;
{
    //Imprime a matriz em um formato tradicional;
    for (int i = 0; i < right.line; i++)
    {
        cout << endl;
        cout << "| ";

        for (int j = 0; j < right.column; j++)
        {
            cout << fixed << setprecision(2) //Saída com precisão de duas casas decimais;
                 << right.matriz[i][j] << " ";
        }

        cout << "|";
    }
        cout << endl;

    return output; //Retorna o objeto output para efeito em cascata;
}

istream &operator>>(istream &input, Matriz &right) //Operador de extração de fluxo
{   
    //Permite que o usuário preencha a matriz;
    for (int i = 0; i < right.line; i++)
        for (int j = 0; j < right.column; j++)
        {
            cin >> right.matriz[i][j];
        }

    return input; //Retorna o objeto input para efeito em cascata;
}

Matriz &operator+(const double num, Matriz &right) //Soma de matriz e escalar, com objeto à direita; 
{
    return (right + num);
}

Matriz &operator-(const double num, Matriz &right) //Subtração de matriz e escalar, com objeto à direita;
{ 
    right = right * -1;
    return right + num; //Retorna a matriz objeto da classe;
}

Matriz &operator*(const double num, Matriz &right) //Multiplicação de matriz e escalar, com objeto à direita;
{
    return (right * num);
}

    /*
    double coefficient = 1;
        //Pivotização;
        for (int i = 0; i < line; i++) //Utiliza um quadrado baseado na quantidade de colunas;
            for (int k = i + 1; k <= line; k++) //Linha abaixo
            {
                //coefficient = 1;
                /*if(matriz[0][0] == 0)
                {
                    for (int f = i + 1; f < line; f++)
                    {
                        if(matriz[f][i] != 0)
                        {
                            trocalinha(i , f);
                        }
                    }
                if(matriz[i][i] > 0)
                {
                    coefficient = matriz[k][i] / matriz[i][i];
                }

                if(matriz[i][i] < 0)
                {
                    coefficient = (-1) * (matriz[k][i] / matriz[i][i]);
                }

                for(int j = 0; j < column; j++)
                {
                    matriz[k][j] -= coefficient * matriz[i][j];
                }

            }
            */