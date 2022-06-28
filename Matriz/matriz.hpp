#ifndef _MATRIZ_
#define _MATRIZ_

#include <iostream>

class Matriz
{
private:
    
    int line, column;
    double** matriz;

public:

    Matriz(int = 3, int = 2);        //Constructor matriz qualquer;
    Matriz(int = 3);                 //Constructor matriz quadrada;
    ~Matriz();                       //Destructor;

    void imprimir();                 //Mostra os elementos da matriz;

    //Métodos set:

    //Operator unário:
    Matriz operator[] (int line, int column);       //Retornar valor;
    Matriz &operator[] (int line, int column);      //Retornar referência;

    //Operator entre objetos:
    Matriz operator+ (const Matriz &other);   //Soma matricial;
    Matriz operator- (const Matriz &other);   //Subtração matricial;
    Matriz operator* (const Matriz &other);   //Multiplicação matricial;
    Matriz operator= (const Matriz &other);   //Cópiar matriz; --> Poderia usar o efeito de cascata para método?

    //Operator para o objeto com lvalue modificável:
    Matriz operator+ (auto);                  //Soma por escalar;
    Matriz operator- (auto);                  //Subtração por escalar;
    matriz operator* (auto);                  //Multiplicação por escalar;
    
    //Operator para o objeto como rvalue:
    friend ostream &operator<< (ostream &, const Matriz &right);         //Inserção de fluxo;
    friend istream &operator>> (istream &, Matriz &rigtht);              //Extração de fluxo;

    friend Matriz &operator+ (double, Matriz &right);                    //Soma por escalar;
    friend Matriz &operator- (double, Matriz &right);                    //Subtração por escalar;
    friend Matriz &operator* (double, Matriz &right);                    //Multiplicação por escalar;
};

#endif