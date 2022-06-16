#ifndef CLASSE_SENSOR_
#define CLASSE_SENSOR_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define low 4                   //Parâmetros do intervalo da corrente;
#define high 20

using namespace std;

class SensorTemperatura
{
    private:

    //Atributos;
    bool ligado = true;
    bool defeito = true;
    
    static int n_sensores;

    float corrente_saida;
    int unidade;

    string unidade_engenharia;

    float convert_corrente(); //Métoro auxiliar que retorna a temperatura de acordo com a corrente;
    
    public:

    SensorTemperatura (int unidade); //Constructor;
    ~SensorTemperatura ();           //Destructor;

    //Métodos set;
    void setunidade(int unidade);
    void setdefeito(int defeito);
    
    //Métodos get;
    bool getligado();
    int getn_sensores();
    int getdefeito();
    int getunidade();
    float getcorrente_saida();
    string getunidade_engenharia();

    void imprimir();        //imprime o estado do objeto
    void ligar();           //liga o sensor
    void desligar();        //desliga o sensor
    
    //Métodos static que recebe um valor em uma unidade e coverte para outra 
    static float CelsiusToKelvin(float Celsius);
    static float CelsiusToFahrenheit(float Celsius);

    static float KelvinToCelsius(float kelvin);
    static float KelvinToFahrenheit(float kelvin);
    
    static float FahrenheitToCelsius(float Fahrenheit);
    static float FahrenheitToKelvin(float Fahrenheit);
    //Nessa parte de static não ficou claro se era para receber um valor definido na main,
    //ou se era utilizando o valor da corrente do sensor; 
    float efetuaMedicao();  //medicao feita pelo sensor
};

#endif
