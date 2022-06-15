#ifndef CLASSE_SENSOR_
#define CLASSE_SENSOR_

//using std::cout, std::fixed(2), std::setprecision(2)

using namespace std:

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

class SensorTemperatura
{
    private:

    //Atributos;
    bool ligado = true;
    static int n_sensores;
    
    int corrente_saida;
    int defeito, unidade;

    static float corrente_saida(); //.

    public:

    SensorTemperatura (int unidade); //contrutor

    //Métodos set;
    void setunidade(int unidade);
    void setdefeito(int defeito);
    
    //Métodos get;
    bool getligado();
    int getn_sensores();
    int getcorrente_saida();
    int getdefeito();
    int getunidade();

    
    void imprimir();        //imprime o estado do objeto
    void ligar();           //liga o sensor
    void desligar();        //desliga o sensor
    
    static void CelsiusToKelvin();
    static void CelsiusToFahrenheit();

    static void KelvinToCelsius();
    static void KelvinToFahrenheit();
    
    static void FahrenheitToCelsius();
    static void FahrenheitToKelvin();
    
    float efetuaMedicao();  //medicao feita pelo sensor
};

#endif
