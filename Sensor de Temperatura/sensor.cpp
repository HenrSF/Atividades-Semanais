#include "sensor.hpp"

SensorTemperatura::SensorTemperatura(int u)
{
    ligado = false;
    defeito = false;

    switch (u)                                  //Kelvin = 1 ; Fahrenheit = 2 ; Celsius = 3;
    {
    case 1:
        setunidade(1);
        break;
    
    case 2:
        setunidade(2);
        break;

    default:
        setunidade(u);
        break;
    }

    n_sensores++;
}

SensorTemperatura::~SensorTemperatura()
{

}

void SensorTemperatura::ligar()

{
    ligado = true;
}

void SensorTemperatura::desligar()

{
    ligado = false;
}

void SensorTemperatura::setunidade(int u)
{
    unidade = u;
}

void SensorTemperatura::setdefeito(int d)
{
    if (d < 5)
    {
        defeito = true;
        cerr << "O sensor apresenta problemas.";
        exit(EXIT_FAILURE);
    }

    else defeito = false;
}

float SensorTemperatura::convert_corrente()
{
    switch (getunidade())
    {
    case 1:
        return ((((getcorrente_saida() - 4) * 100) / 16) + 273);    //Fórmula para retornar a corrente em Kelvin;
        break;
    
    case 2:
        return ((((getcorrente_saida() - 4) * 180) / 16) + 32);     //Fórmula para retornar a corrente em graus Fahrenheit;
        break;

    default:
        return (((getcorrente_saida() - 4) * 100) / 16);            //Fórmula para retornar a corrente em graus Celsius;
        break;
    }
}
//Métodos get;
bool SensorTemperatura::getligado()
{
    return ligado;
}

int SensorTemperatura::getn_sensores()
{
    return n_sensores;
}

int SensorTemperatura::getdefeito()
{
    return defeito;
}

int SensorTemperatura::getunidade()
{
    return unidade;
}

float SensorTemperatura::getcorrente_saida()
{
    return corrente_saida;
}

float SensorTemperatura::efetuaMedicao()
{
    srand(time(NULL));

    setdefeito(rand() % 100 + 1);

    if (getdefeito() == false)
    {
        corrente_saida = (low + static_cast<float> (rand()) * static_cast<float>(high - low) / RAND_MAX);

        return convert_corrente();
    }
    
    else exit(EXIT_FAILURE);
}

//Métodos static;
float SensorTemperatura::CelsiusToFahrenheit()

{
    F = (1.8*C) + 32;
}

float SensorTemperatura::CelsiusToKelvin()

{
    K = C + 273;
}

float SensorTemperatura::KelvinToCelsius()

{
    C = K - 273;
}

float SensorTemperatura::KelvinToFahrenheit()

{
    F = ((K - 273)*1.8) + 32;
}

float SensorTemperatura::FahrenheitToCelsius()

{
    F = (F - 32)/1.8;
}

float SensorTemperatura::FahrenheitToKelvin()

{
    K = ((F-32)*(5/9)) + 273;
}
