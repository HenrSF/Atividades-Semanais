#include "Matriz.hpp"

Matriz temp; //Objeto temporário para ser retornado sem modificar o objeto que chama o método 

Matriz::Matriz(int line, int column) //Construtor para matrizes de n tamanho;
{
    //Mudando o sinal para evitar valores negativos nos atributos line e column;
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
    //Mudando o sinal para evitar valores negativos nos atributos line e column;
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
    if(min > max) //Troca as variáveis para manter o min < max;
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

void Matriz::imprimir() //Método para imprimir todos os atributos do objeto.
{
    cout << "\nNúmero de linhas: " << this->line
         << "\nNúmero de colunas: " << this->column << endl
         << *this
         << "\nMatriz diagonal:" << diagonal_check();
}

bool Matriz::diagonal_check() //Verificar se a matriz é diagonal;
{
    int cont = 0; //Contoador para verificar a quantidade de zeros fora da diagonal principal da matriz;

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

void Matriz::trocalinha(int i, int linechange) //Método que utiliza um ponteiro auxiliar para trocar linhas
{   
    //É possível desalocar a memória desse ponteiro?
    ptraux = matriz[i];
    matriz[i] = matriz[linechange];
    matriz[linechange] = ptraux;
}

void Matriz::jump_end(int line) //Transfere uma linha da matriz para a última posição;
{
    for(int i = line; i < line - 1; i++) //(line - 1) para evitar trocar com uma linha inexistente;
    {
        trocalinha(i, i+1); //Troca a linha i, com a linha abaixo;
    }
}

void Matriz::zero_fix(int n) //Reajusta os zeros da coluna da matriz no escalonamento;
{
    for(int j = 0; j < line; j++)
    {   
        for (int i = 0; i < line; i++)
        if(matriz[i][n] == 0) //Caso o elemento da matriz seja zero, transfere a linha para o final da matriz;
        {
            jump_end(i); 
        } 
    }
}

void Matriz::gaussian_elimination()
{   
    //Variáveis para casos de colunas inteiras igual a 0;
    int zero_control;
    int l = 0; //Variável para avançar a coluna permanecendo na mesma linha;
    
    for (int i = 0; i < line + l; i++) //Percorre as colunas da matriz, considerando apenas a formação do triângulo inferior;
    {   
        zero_control = 0; //Reseta a variável;

        for (int k = i - l; k < line; k++) //Laço de repetição que realiza as divisões;
        {
            if(matriz[k][i] != 0) //Se o elemento for diferente de zero, realiza a divisão;
            {
                zero_control++; //Conta valores diferentes de zero;

                for (int j = column - 1; j >= 0; j--) //Percorre de forma decrescente, realizando divisões pelo primeiro elemento da coluna atual;
                {
                    matriz[k][j] /= matriz[k][i];
                }
            }
        }

        if(zero_control > 0) zero_fix(i); //Se houver algum zero na coluna, chama o método de correção de zeros;
        

        for(int x = i - l + 1; x < line; x++) //Subtração entre as linhas;
        {   
            if(zero_control == 0) //Se todos os elemento da coluna abaixo do pivô forem iguais a zero, avança para a próxima coluna, sem realizar as subtrações;
            {
                l++; //Serve para permanecer na mesma linha;
                break;
            }

            if (matriz[x][i] == 0) break; //Se o pivô for igual a zero, avança para a próxima coluna sem realizar a subtração;

            for (int j = 0; j < column; j++) //Realiza a subtração da linha atual, pelo linha pivô anteriormente estabelecida;
            {
                matriz[x][j] -= matriz[i-l][j];
            }
        }

        if(zero_control > 0) zero_fix(i); //Realiza a correção de zeros novamente;
    }
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
    if (this != &temp) temp = *this; //Temp só recebe o objeto se o objeto não for o próprio temp;

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
    if (this != &temp) temp = *this; //Temp só recebe o objeto se o objeto não for o próprio temp;

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
    if (this->column != other.line) //Condição para multiplicar 2 matrizes.
    {
        cerr << "\nThe matrix cannot be multiplied!";
        exit(EXIT_FAILURE);
    }

    Matriz resultado(this->line, other.column); //Cria um bjeto para receber os valores da multiplicação;
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

        return *this; //Retorna o próprio objeto, permitindo o efeito cascata;
    }

    cerr << "\nThey are the same matrix!";
    exit(EXIT_FAILURE);
}


Matriz &Matriz::operator+(double num) //Soma de matriz e escalar com o objeto à esquerda;
{
    
    if (this != &temp) temp = *this; //Temp só recebe o objeto se o objeto não for o próprio temp;

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] += num;
        }

    return temp; //Retorna o objeto temp;
}

Matriz &Matriz::operator-(double num) //Subtração de matriz e escalar com o objeto à esquerda;
{
    if (this != &temp) temp = *this; //Temp só recebe o objeto se o objeto não for o próprio temp;

    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
        {
            temp.matriz[i][j] -= num;
        }

    return temp; //Retorna o objeto temp;
}

Matriz &Matriz::operator*(double num) //Multiplicação de matriz e escalar com o objeto à esquerda;
{
    if (this != &temp) temp = *this; //Temp só recebe o objeto se o objeto não for o próprio temp;

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
    return right + num;
}

Matriz &operator-(const double num, Matriz &right) //Subtração de matriz e escalar, com objeto à direita;
{ 
    return right * -1 + num; //Retorna a matriz objeto da classe;
}

Matriz &operator*(const double num, Matriz &right) //Multiplicação de matriz e escalar, com objeto à direita;
{
    return right * num;
}                     