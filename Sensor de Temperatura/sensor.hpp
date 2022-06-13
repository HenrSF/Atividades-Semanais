#ifndef CLASSE_SENSOR_
#define CLASSE_SENSOR_
using namespace std;
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class SensorTemperatura{
    public:
    SensorTemperatura (); //contrutor
    
    void setunidade(int);
    void setdefeito(int);
    
    int getn_sensores();
    int getcorrente_saida();
    
    void imprimir();    //imprime o estado do obj
    void ligar();       //liga o sensor
    void desligar();    //desliga o sensor
    
    static float CelsiusToKelvin();
    static float CelsiusToFahrenheit();

    static float KelvinToCelsius();
    static float KelvinToFahrenheit();
    
    static float FahrenheitToCelsius();
    static float FahrenheitToKelvin();
    
    int efetuaMedicao(); //medicao feita pelo sensor

    private:
    static int corrente_saida();
    bool ligado = true;
    static int n_sensores;
    
    int corrente_saida;
    int defeito, unidade;

};

#endif
