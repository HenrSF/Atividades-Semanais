#ifndef _MATRIZ_
#define _MATRIZ_

class matriz
{
private:
    
    int linhas, colunas;

public:

    matriz(int linhas, int colunas);        //Constructors;
    matriz(int ordem);
    
    void imprimir();                        //Mostra os elementos da matriz;
    ~matriz();                              //Destructor;
};

#endif