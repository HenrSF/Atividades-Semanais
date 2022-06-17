#include "sensor.hpp"

int SensorTemperatura::n_sensores;

SensorTemperatura::SensorTemperatura(int u)
{
    ligado = false;
    defeito = false;
    
    setunidade(u);

    n_sensores++;
}

SensorTemperatura::~SensorTemperatura()
{
    n_sensores--;
}

void SensorTemperatura::ligar()

{
    ligado = true;
}

void SensorTemperatura::desligar()

{
    ligado = false;
}

//Métodos set;
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

float SensorTemperatura::convert_corrente() //Converter a corrente para uma unidade de temperatura;
{
    switch (getunidade())                                           //Kelvin = 1 ; Fahrenheit = 2 ; Celsius = else;
    {
    case 1:
        unidade_engenharia = "K";
        return ((((getcorrente_saida() - 4) * 100) / 16) + 273);    //Fórmula para retornar a corrente em Kelvin;
        break;
    
    case 2:
        unidade_engenharia = "º F";
        return ((((getcorrente_saida() - 4) * 180) / 16) + 32);     //Fórmula para retornar a corrente em graus Fahrenheit;
        break;

    default:
        unidade_engenharia = "º C";
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
string SensorTemperatura::getunidade_engenharia()
{
    return unidade_engenharia;
}

float SensorTemperatura::getcorrente_saida()
{
    return corrente_saida;
}

float SensorTemperatura::efetuaMedicao()
{
    setdefeito(rand() % 100 + 1);

    if (getdefeito() == false)
    {
        corrente_saida = (low + static_cast<float> (rand()) * static_cast<float>(high - low) / RAND_MAX); //Retorna um ponto flutuante entre o intervalo da corrente.

        return convert_corrente();
    }
    
    else exit(EXIT_FAILURE);
}

void SensorTemperatura::imprimir()
{
    cout << fixed << setprecision(2) 
         << "\nLigado = "             << getligado()
         << "\nDefeito = "            << getdefeito()
         << "\nNúmero de sensores = " << getn_sensores()
         << "\nCorrente de saída = "  << getcorrente_saida() << "mA" 
         << "\nTemperatura = "        << convert_corrente()  << getunidade_engenharia();

}

//Métodos static;
float SensorTemperatura::CelsiusToFahrenheit(float c)

{
    return ((c * 1.8) + 32);
}

float SensorTemperatura::CelsiusToKelvin(float c)

{
    return (c + 273);
}

float SensorTemperatura::KelvinToCelsius(float k)

{
    return  (k - 273);
}

float SensorTemperatura::KelvinToFahrenheit(float k)

{
    return (((k - 273) * 1.8) + 32);
}

float SensorTemperatura::FahrenheitToCelsius(float f)

{
    return ((f - 32)/1.8);
}

float SensorTemperatura::FahrenheitToKelvin(float f)

{
    return (((f - 32) * (5/9)) + 273);
}
