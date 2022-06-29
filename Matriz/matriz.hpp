#ifndef _MATRIZ_
#define _MATRIZ_

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::cerr;
using std::ostream;
using std::istream;

class Matriz
{
private:
    
    int line, column;
    double** matriz;
    
public:

    Matriz(int line, int column);    //Constructor matriz qualquer;
    Matriz(int = 3);                 //Constructor matriz quadrada;
    //Matriz(Matriz &other);         //Copy Constructor; 
    ~Matriz();                       //Destructor;

    void imprimir();                 //Mostra os elementos da matriz;
    void fill();                     //Preencher a matriz manual;
    void fillrand(double min, double max); //Preencher a matriz randon;
    bool diagonal();                 //Verificar se a matriz é diagonal;
    double** gaussian_elimination(); //Escalonamento da matriz;

    //Métodos set:
    //void &setline (int line);     {this->line = line; return *this; };
    //void &setcolumn (int column); {this->column = column; return *this;};
    

    //Métodos get:
    int getline()   {return line;};
    int getcolumn() {return column;};
    double &getmatriz();                       //Dever ser retornada uma cópia da matriz;
    
    //Operator subscrito:
    double  operator[] (int i) const; //Retornar valor;
    double &operator[] (int i); //Retornar referência;

    //Operator entre objetos:
    Matriz &operator+ (const Matriz &other);   //Soma matricial;
    Matriz &operator- (const Matriz &other);   //Subtração matricial;
    Matriz &operator* (const Matriz &other);   //Multiplicação matricial;
    Matriz &operator= (const Matriz &other);   //Cópiar matriz; --> Poderia usar o efeito de cascata para método?

    //Operator para o objeto como lvalue modificável:
    void operator+ (double num) const;                //Soma por escalar;
    void operator- (double num) const;                //Subtração por escalar;
    void operator* (double num) const;                //Multiplicação por escalar;
    
    //Operator para o objeto como rvalue:
    friend ostream &operator<< (ostream &, const Matriz &right);         //Inserção de fluxo;
    friend istream &operator>> (istream &, Matriz &rigtht);              //Extração de fluxo;

    friend Matriz &operator+ (double num, Matriz &right);                    //Soma por escalar;
    friend Matriz &operator- (double num, Matriz &right);                    //Subtração por escalar;
    friend Matriz &operator* (double num, Matriz &right);                    //Multiplicação por escalar;
};

#endif